# Fish

Fish (Friendly Interactive SHell) is a Unix shell — both an interactive command-line interpreter AND a scripting language. Like Zsh, there's no separate "host application" embedding it — fish itself is the program you're typing into, and `config.fish` is code that fish (the program) reads and runs on itself, on startup.

Fish scripts run through fish directly, no separate compile step, no bytecode, no VM layer to think about — it reads and executes line by line as you'd expect from a shell.

```text
config.fish / any fish script -> read and executed directly by the fish binary, line by line.
```

## Index

- [History](#history)
- [Sample code](#sample-code)
- [How to run them](#how-to-run-them)
- [Shell built-ins:](#shell-built-ins)

## History

Fish was created by Axel Liljencrantz, first released in 2005. Unlike zsh or bash, it was designed from scratch rather than as an evolution of the Bourne shell lineage — the explicit goal was a shell that's friendly and usable out of the box, with sane defaults instead of decades of `sh`-compatibility baggage.

Fish is *not* POSIX-compatible — this is a deliberate design choice, not an oversight. Syntax that "just works" in bash/zsh (`if [ x = y ]`, `$(cmd)`, `export VAR=val`) is intentionally different in fish, in exchange for cleaner syntax, autosuggestions, and sensible defaults (syntax highlighting and tab-completion work out of the box, no plugins or frameworks needed). Development is community-driven today, hosted on GitHub, with a stable release cadence.

## Sample code

**1. Hello World**
```fish
echo "Hello, World!"
```
Output:
```text
Hello, World!
```

**2. Take input, say name**
```fish
echo "Enter your name:"
read name
echo "Hello, $name"
```
Output:
```text
Enter your name:
nkc
Hello, nkc
```
- `read name` — pauses execution, waits for typed input + Enter, stores it in the variable `name`.
- `$name` inside double quotes gets expanded to the stored value (same as zsh/bash here).

**3. Take two inputs, add them, if/else**
```fish
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
Output:
```text
Enter first number:
7
Enter second number:
6
Sum is 13, bigger than 10
```
- `set sum (math "$a + $b")` — fish has no `$(( ))` arithmetic expansion; you shell out to the `math` builtin, and `( )` (not backticks or `$( )`) is fish's command-substitution syntax.
- `if test $sum -gt 10 ... end` — no `[[ ]]` or `(( ))` in fish. `test` (or its alias `[`) is the one tool for numeric AND string/file comparisons (`-gt`, `-eq`, `-n`, `-f`, etc). Blocks close with `end`, not `fi`/`done`/`esac` — one closing keyword for every block type in fish.

## How to run them

No linker, no compile step, no separate binary produced — the same file is read and re-executed every time.

- **Interactive shell** — the fish session you're typing commands into right now. `config.fish` runs automatically every time a new interactive shell starts.
- **Script file, via interpreter** — `fish myscript.fish` runs a file directly, non-interactively, top to bottom. No permissions or shebang needed, since you're naming the interpreter yourself.
- **Script file, as an executable** — needs a shebang line and execute permission:
```fish
#!/usr/bin/env fish
echo "Hello World"
```
```bash
chmod +x hello_world.fish   # do this once, grants execute permission
./hello_world.fish
```
**Shebang** (`#!...`) — "sharp" + "bang". When run directly (`./file`), the kernel reads the first two bytes; if they're `#!`, it treats the rest of the line as the exact program to run the file with. `#!/usr/bin/env fish` finds `fish` on `$PATH` via `env` — portable across machines. Only matters for direct execution; irrelevant when you type `fish file.fish` yourself.
- **Login shell** — fish sources `config.fish` for both login and non-login interactive shells (fish doesn't split startup files across `.zprofile`/`.zlogin`-style login-only files the way zsh/bash do); use `status is-login` / `status is-interactive` inside `config.fish` itself if you need to branch on which kind of session it is.

## Shell built-ins:

None of these are Linux/OS commands — no separate binary file exists for any of them (`type export` in bash/zsh has no fish equivalent by that name, but `type` still confirms builtins in fish too: "is a shell builtin"). They only exist because the shell itself implements them internally.

**Prompt** — unlike zsh's `PROMPT` string variable with `%`-codes, fish's prompt is a **function**, `fish_prompt`, that you define and that gets called and re-run before every command. There's no mini-syntax to memorize — it's just fish code that echoes/prints what you want.
```fish
function fish_prompt
    set_color yellow
    echo -n (whoami)'@'(hostname)':'(prompt_pwd)'$ '
    set_color normal
end
```
`set_color` is fish's builtin for terminal colors/bold (its equivalent job to zsh's `%F{}`/`%B` codes), `prompt_pwd` gives the abbreviated current-directory path (fish's equivalent to `%~`).

**Alias** — text substitution; the shell swaps the short name for the real command before running it. Fish's `alias` is actually sugar over defining a function, and by default aliases are **session-only** — they vanish when the shell closes unless made persistent (via `funcsave` or by putting them straight into `config.fish`).
```fish
alias ll='ls -la'
```

**Set (with -x)** — fish uses one builtin, `set`, for all variable assignment (no bare `VAR=val` syntax like sh/zsh/bash). The `-x` (or `--export`) flag is what makes a variable visible to child processes, not just the shell itself — equivalent job to zsh/bash's separate `export` command.
```fish
set -x GREETING "hello"
```

**Source** — runs a file's lines directly in the CURRENT shell session, same concept and same name as in zsh. Contrast: `fish file.fish` starts a separate new process; `source` does not.
```fish
echo 'set -x TEST world' > test.fish
fish test.fish
echo $TEST          # prints nothing — that separate process already ended
source test.fish
echo $TEST          # prints "world" — ran directly in this shell
```
This is why `config.fish` is reloaded with `source ~/.config/fish/config.fish`, never `fish ~/.config/fish/config.fish` — you want the new `fish_prompt`, aliases, and exported variables applied to your current terminal, not to a throwaway process that immediately exits.

**Change Directory** (shorthand - cd) - changes the current working directory
```fish
cd ~  # changes the current working directory to home
```
