# Shell

A **shell** is a program that acts as the interface between the user and the operating system's **kernel**. When you type a command, the shell reads it, figures out what you mean, and asks the kernel to actually carry it out — then shows you the result. You never talk to the kernel directly; you talk to the shell, and the shell talks to the kernel on your behalf.

```text
User -> Shell -> Kernel -> Hardware
```

What a shell actually does, in short:

- **Reads** what you type (interactively, one line at a time) or a script file (top to bottom).
- **Interprets** it — splits it into commands + arguments, expands variables/wildcards, checks for `if`/loops/etc.
- **Executes** it — either handles it internally (a *builtin*) or asks the kernel to run a separate program for it.
- **Shows you the output** — connects the program's output back to your terminal.

A shell is also a full **scripting language** in its own right — not just something you type one-off commands into. The same interpreter that runs your typed commands also reads and runs `.sh`/`.zsh`/`.fish` script files, line by line, with no separate compile step, no bytecode, no VM layer — unlike C, there's no pipeline turning shell code into a standalone binary first (see [How A Shell Actually Works](#how-a-shell-actually-works) for the direct comparison).

This README covers four shells: **sh**, **bash**, **zsh**, and **fish**. The first three (`sh`, `bash`, `zsh`) all descend from the same lineage and are broadly **POSIX-compatible** — meaning they agree on a common core of syntax (`if`, loops, `$()`, `export`, etc.), even though bash and zsh each layer their own extensions on top of plain `sh`. **fish** is the outlier — built from scratch in 2005, deliberately **not POSIX-compatible**, trading `sh`-lineage syntax for cleaner defaults. That split (three POSIX-family shells + one deliberately different one) is why almost every section below calls fish out separately.

## Index

- [History](#history)
- [How They All Run](#how-they-all-run)
- [How A Shell Actually Works](#how-a-shell-actually-works)
- [Famous Shell Builtins](#famous-shell-builtins)

## History

All four shells trace back to one common ancestor, except fish, which deliberately broke from it.

- **sh (Bourne Shell) — 1977.** Written by Stephen Bourne at Bell Labs for Unix. The original shell — introduced the `if`/`for`/`while` scripting constructs, variables, and `$()`-style substitution that almost every later shell still builds on. Minimal by modern standards, but it defined the baseline that "POSIX-compatible" is measured against today.
- **bash (Bourne Again Shell) — 1989.** Written by Brian Fox for the GNU Project, as a free, extended replacement for `sh` on GNU/Linux systems. Added command history, tab-completion, arrays, and more scripting features on top of the Bourne syntax while staying backward-compatible with it. Became the default login shell on almost every Linux distribution.
- **zsh (Z Shell) — 1990.** Created by Paul Falstad while a student at Princeton. Combines ideas from both `ksh` and `tcsh` on top of the Bourne lineage — programmable completion, extended globbing, better array handling, and fully themeable prompts. The name comes from Yale professor Zhong Shao, then a TA at Princeton, whose login-id "zsh" Falstad borrowed. Development passed to the community (Bart Schaefer, Andrew Main, others) in the mid-90s. In 2019, Apple made zsh the default shell on macOS, replacing bash.
- **fish (Friendly Interactive Shell) — 2005.** Created by Axel Liljencrantz. Unlike the three above, fish was **designed from scratch**, not as an extension of Bourne syntax — the explicit goal was a shell that's friendly and usable immediately, with syntax highlighting and tab-completion working out of the box, no plugins needed, in exchange for deliberately **not** being POSIX-compatible (`if [ x = y ]`, `$()`, `export VAR=val` all look and work differently in fish). Development today is community-driven on GitHub.

```text
sh (1977)
 └── bash (1989)
 └── zsh (1990)         <- POSIX-family, share a common core

fish (2005)              <- built from scratch, not POSIX-compatible
```

## How They All Run

This part is identical across all four shells — running a shell script never involves a linker, compiler, or separate binary output. The same file is read and re-executed, top to bottom, every single time. There are three ways to run any of them:

1. **Interactive shell** — the live session you're typing into right now. Each shell auto-runs its own startup file when a new interactive session opens (`~/.bashrc` for bash, `~/.zshrc` for zsh, `~/.config/fish/config.fish` for fish; plain `sh` typically has no user startup file by default).
2. **Script file, via interpreter** — naming the interpreter yourself runs the file directly, no permissions or shebang required: `bash script.sh`, `zsh script.zsh`, `fish script.fish`, `sh script.sh`.
3. **Script file, as an executable** — needs a **shebang** line as the very first line, plus execute permission:

```bash
#!/bin/bash        # or #!/bin/sh , #!/usr/bin/env zsh , #!/usr/bin/env fish
echo "Hello World"
```
```bash
chmod +x script.sh   # do this once — grants execute permission
./script.sh
```

**Shebang** (`#!`) — "sharp" + "bang." When you run a file directly (`./file`), the kernel reads the first two bytes; if they're `#!`, the rest of that line names the exact interpreter to hand the rest of the file to. `#!/usr/bin/env zsh` (or `fish`) finds the interpreter via `$PATH`, which is more portable across machines than hardcoding `#!/bin/zsh`. The shebang only matters for direct execution (`./file`) — it's irrelevant when you already name the interpreter yourself (`zsh file.zsh`).

**Login shells** — the one place behavior actually differs: bash and zsh both distinguish a *login* shell (SSH, TTY, `bash -l`/`zsh -l`) from a plain interactive one, and source extra files only on login (`~/.bash_profile`/`~/.profile` for bash; `~/.zprofile`/`~/.zlogin` for zsh) — opening a normal terminal window usually does **not** trigger this. Fish doesn't split this the same way — it sources the same `config.fish` for both login and non-login interactive sessions, and you branch inside it yourself with `status is-login` / `status is-interactive` if you need different behavior.

## How A Shell Actually Works

A shell command does not run "as text." Just like C source code needs to go through preprocessing, compilation, assembly, and linking before the CPU can run it, a shell has to turn the line you typed into actual running processes — the shell just does this itself, at the moment you press Enter, instead of ahead of time via a separate compiler.

```text
You type a line
    |
    v
Read + Tokenize
    |
    v
Expansion (variables, wildcards, substitution)
    |
    v
Builtin? -----yes----> Shell runs it internally, in its own process
    |
    no
    |
    v
Find the program on $PATH
    |
    v
fork() -> clone the shell process into parent + child
    |
    v
execve() in the child -> child process is replaced by the new program
    |
    v
wait() in the parent -> shell pauses until child finishes
    |
    v
Output shown, shell prints the prompt again
```

### 1. Read + Tokenize

The shell reads one line (interactively) or one statement (in a script), then splits it into pieces by whitespace — this is **tokenizing**. Running `ls -l *.c` produces the raw tokens `ls`, `-l`, `*.c`. Internally this is essentially what C's `strtok()` does — walking the string and cutting it at whitespace boundaries into an array.

### 2. Expansion

Before anything is executed, the shell rewrites certain tokens:

- **Variables** — `$name` is replaced with its stored value.
- **Wildcards/globbing** — `*.c` is expanded into every matching filename in the current directory, e.g. `main.c util.c test.c`.
- **Command substitution** — `$(cmd)` (or backticks, or fish's `(cmd)`) is replaced with that command's output.
- **Aliases** — if the first token is an alias, it's swapped for its real definition (`ls` → `ls --color=tty`, for example) before anything else happens.

After this stage the shell has a clean, final list of tokens ready to execute — e.g. `{"ls", "-l", "main.c", "util.c", "test.c"}`.

### 3. Builtin or external program?

The shell now checks: is the first token something the shell implements *itself* (a **builtin**, like `cd` or `export`), or is it a separate program that lives somewhere on disk (like `/bin/ls`)?

- If it's a **builtin**, the shell just runs that logic directly, in its own process — no new process is created at all. This is exactly why `cd` *must* be a builtin: if `cd` forked a child process to change directory, only that short-lived child's working directory would change, and the parent shell (your actual terminal) would be completely unaffected the instant the child exited.
- If it's **not a builtin**, the shell searches the directories listed in the `$PATH` environment variable, in order, until it finds a matching executable file (e.g. `ls` is found at `/bin/ls` or `/usr/bin/ls`).

### 4. fork() — cloning the shell

To run an external program *without* replacing itself (so your shell is still there once the command finishes), the shell calls the `fork()` system call.

`fork()` clones the current process — memory, open files, environment variables, and the exact point of execution — into two nearly identical processes: the original (**parent**) and a new copy (**child**). `fork()` returns *twice*, with a different value in each:

- Returns `0` inside the **child**.
- Returns the child's actual process ID inside the **parent**.

Checking that return value is how the shell's own code knows which of the two copies it's currently running as, so it can decide what to do next.

### 5. execve() — replacing the child process

Inside the **child** copy only, the shell calls `execve(path, argv, envp)` — a system call that:

1. Loads the target program's machine code (e.g. `/bin/ls`) into the *current* process's memory.
2. Discards everything the process was running before.
3. Gives it a brand-new stack, heap, and data section.

Crucially, `execve()` does not create a new process — it **replaces** the contents of the process that calls it. This is why `fork()` had to happen first: if the *original* shell process called `execve()` directly with no fork, the shell itself would be overwritten by `ls` and would simply cease to exist the moment `ls` finished — there would be no shell left to return to. By forking first, only the disposable child copy gets replaced; the real shell (the parent) is untouched and still running.

### 6. wait() — the parent pauses

Meanwhile, the **parent** (the real shell) calls `wait()`, which pauses it until the child process finishes running (or is killed). Without this step, the shell's prompt would print again immediately, racing ahead of — and getting jumbled together with — the child program's output.

### 7. Output

Because `fork()` copies the child's file descriptors, the child process (now running `ls`, after `execve()`) still writes to the same terminal (`stdout`) the shell itself was attached to — so the program's output appears in your terminal exactly as if the shell had printed it itself, even though it's really a completely different program running in its own process.

Once `wait()` returns, the parent shell resumes, prints its prompt, and reads the next line — starting the whole loop over again.

```text
Contrast with C compilation:
C: source -> preprocess -> compile -> assemble -> link  -> ONE executable produced ahead of time, run later.
Shell: source line -> tokenize -> expand -> fork+execve directly -> runs immediately, every single time, no separate build step.
```

This entire model — read, tokenize, expand, builtin-or-fork/exec, wait — is exactly the same across sh, bash, zsh, and fish. What differs between them is only the *syntax* used at the tokenizing/expansion stage (covered below), not the underlying execution mechanism.

### Sample scripts (syntax comparison)

**Hello World**
```sh
# sh / bash / zsh
echo "Hello, World!"
```
```fish
# fish
echo "Hello, World!"
```
Identical everywhere — `echo` is a shared builtin.

**Take input, say name**
```sh
# sh / bash / zsh
echo "Enter your name:"
read name
echo "Hello, $name"
```
```fish
# fish
echo "Enter your name:"
read name
echo "Hello, $name"
```
Also identical — `read` and `$var` expansion behave the same in all four here.

**Take two numbers, add them, if/else**
```sh
# sh / bash / zsh
echo "Enter first number:"; read a
echo "Enter second number:"; read b
sum=$((a + b))

if [ "$sum" -gt 10 ]; then
    echo "Sum is $sum, bigger than 10"
else
    echo "Sum is $sum, 10 or less"
fi
```
```zsh
# zsh also supports the more powerful (( )) test for numeric comparisons:
if (( sum > 10 )); then
    echo "Sum is $sum, bigger than 10"
fi
```
```fish
# fish — deliberately different at every one of these points
echo "Enter first number:"
read a
echo "Enter second number:"
read b

set sum (math "$a + $b")

if test $sum -gt 10
    echo "Sum is $sum, bigger than 10"
else
    echo "Sum is $sum, 10 or less"
end
```
Three concrete divergence points, visible side by side:
- **Arithmetic** — `sh`/`bash`/`zsh` use `$(( ))`; fish has no arithmetic expansion operator at all and shells out to the `math` builtin instead.
- **Command substitution** — `sh`/`bash`/`zsh` use `$(cmd)` (or backticks); fish uses plain `(cmd)`.
- **Conditionals + block closing** — `sh`/`bash` use `[ ]` (or `zsh`'s extra `(( ))` for numbers) closed with `fi`; fish uses `test` for everything (numeric and string/file alike) and closes **every** block type — `if`, `for`, `while`, `function` — with the single keyword `end`, rather than `fi`/`done`/`esac`.

## Famous Shell Builtins

A **builtin** is a command the shell implements internally — no separate file/binary exists for it anywhere on disk, which is exactly why builtins skip the fork/execve steps entirely (see above). A command like `mv`, by contrast, is a real compiled program sitting at `/usr/bin/mv` or `/bin/mv` — written and compiled (often in C) completely independently of whichever shell happens to call it. The shell doesn't know or care what language `mv` was written in; it just finds the file on `$PATH` and hands it to `execve()`, which loads whatever machine code is already sitting in that file. That's *why* the same `mv` works identically no matter which of the four shells you run it from — it's not shell code at all, just a program the shell launches.

You can check whether something is a builtin with `type`, e.g. `type cd` reports "cd is a shell builtin," while `type mv` reports a file path.

Below: builtins that behave the same across `sh`/`bash`/`zsh` (all three descend from the same POSIX core), with fish's separate equivalent syntax wherever fish diverges.

**cd** — change the current working directory. Must be a builtin in every shell (see [step 3](#3-builtin-or-external-program) above for why) — identical everywhere:
```sh
cd ~        # sh / bash / zsh / fish — all identical
```

**Alias** — text substitution; the shell swaps a short name for the real command before running it.
```sh
# sh / bash / zsh
alias ll='ls -la'
```
```fish
# fish — same idea, but implemented as sugar over defining a function under the hood.
# Session-only by default in both families unless made persistent.
alias ll='ls -la'
```

**export / set -x** — makes a variable visible to child processes (programs the shell launches), not just the shell itself.
```sh
# sh / bash / zsh
export GREETING="hello"
```
```fish
# fish has no bare VAR=val assignment at all — one builtin, `set`, handles every
# variable assignment, and -x/--export is the flag that makes it exported.
set -x GREETING "hello"
```

**source (or `.`)** — runs a file's lines directly inside the *current* shell process, rather than starting a new one. This is why reloading a config file always uses `source ~/.bashrc`, never `bash ~/.bashrc` — the latter runs in a separate, throwaway process that exits immediately, so none of its exported variables, aliases, or prompt changes would carry back into your actual terminal.
```sh
# sh / bash / zsh
source ~/.bashrc      # or the POSIX shorthand: . ~/.bashrc
```
```fish
# fish — same command name, same behavior
source ~/.config/fish/config.fish
```

**Prompt customization** — the one with the biggest surface-level divergence, though the underlying idea (a piece of shell code that gets re-run before every new command line) is the same everywhere.
```sh
# bash — PS1 is a plain string variable with backslash-escape codes
PS1='\u@\h:\w\$ '     # \u=user \h=host \w=working dir
```
```zsh
# zsh — PROMPT is a string variable too, but with its own %-escape mini-syntax
PROMPT='%F{190}%B%n@%m:%~$ %b%f'   # %n=user %m=host %~=dir %F{}=color %B=bold
```
```fish
# fish — the prompt isn't a variable at all, it's a real function, fish_prompt,
# that gets called and re-run before every command. No mini-syntax to memorize.
function fish_prompt
    set_color yellow
    echo -n (whoami)'@'(hostname)':'(prompt_pwd)'$ '
    set_color normal
end
```

**test / `[ ]` vs `(( ))` vs fish's `test`** — every shell needs some way to evaluate conditions for `if`/`while`. `sh`/`bash`/`zsh` share `test` (aliased as `[ ]`) for string/file/numeric comparisons, and `bash`/`zsh` additionally support `(( ))` specifically for arithmetic comparisons (more readable for math: `(( x > 10 ))` vs `[ "$x" -gt 10 ]`). fish has no `(( ))` at all — `test` (used bare, no brackets) is the single tool for every kind of comparison in fish.
```sh
# sh / bash / zsh
[ "$x" -gt 10 ]        # POSIX test, works in all three
(( x > 10 ))           # bash/zsh only — cleaner numeric syntax, NOT POSIX
```
```fish
# fish — one tool for everything, no bracket or double-paren forms exist
test $x -gt 10
```

**External, non-builtin examples (same in all four, since these are just separate programs on disk)** — `mv`, `cp`, `rm`, `grep`, `ls`, `cat`. None of these are implemented by any shell; every shell finds them on `$PATH` and runs them via the exact same fork → execve → wait sequence described above, regardless of which of the four shells you're typing into.