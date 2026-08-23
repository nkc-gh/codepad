# Zsh

Zsh (Z shell) is a Unix shell — both an interactive command-line interpreter AND a scripting language. Unlike Lua, there's no separate "host application" embedding it — zsh itself is the program you're typing into, and `.zshrc` is code that zsh (the program) reads and runs on itself, on startup.

Zsh scripts run through zsh directly, no separate compile step, no bytecode, no VM layer to think about — it reads and executes line by line as you'd expect from a shell.

```text
.zshrc / any zsh script -> read and executed directly by the zsh binary, line by line.
```

## Index

- [History](#history)
- [Sample code](#sample-code)
- [How to run them](#how-to-run-them)
- [Shell built-ins:](#shell-built-ins)

## History

Zsh was created by Paul Falstad in 1990 while he was a student at Princeton University. It combines features from both ksh and tcsh, offering functionality such as programmable command-line completion, extended file globbing, improved variable/array handling, and themeable prompts.

The name comes from Yale professor Zhong Shao, then a teaching assistant at Princeton — Falstad thought Shao's login-id, "zsh", was a good name for a shell. Development was later taken over in the mid-90s by community members including Bart Schaefer and Andrew Main.

Zsh is a descendant of the original Bourne shell (`sh`), same family as bash and ksh — mostly compatible for basics (variables, `if`, loops), but each has its own extensions. In 2019 Apple made zsh the default shell on macOS, replacing bash.

## Sample code

**1. Hello World**
```zsh
echo "Hello, World!"
```
Output:
```text
Hello, World!
```

**2. Take input, say name**
```zsh
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
- `$name` inside double quotes gets expanded to the stored value.

**3. Take two inputs, add them, if/else**
```zsh
echo "Enter first number:"
read a
echo "Enter second number:"
read b

sum=$((a + b))

if (( sum > 10 )); then
  echo "Sum is $sum, bigger than 10"
else
  echo "Sum is $sum, 10 or less"
fi
```
Output:
```text
Enter first number:
7
Enter second number:
6
Sum is 13, bigger than 10
```
- `sum=$((a + b))` — `$(( ))` does real arithmetic; without it, `a + b` would just be text-joining, not addition.
- `if (( sum > 10 )); then ... fi` — `(( ))` for number comparisons, vs `[[ ]]` for string/file tests (`[[ -n "$name" ]]`, etc.) — different syntax for different jobs.

## How to run them

No linker, no compile step, no separate binary produced — the same file is read and re-executed every time.

- **Interactive shell** — the zsh session you're typing commands into right now. `.zshrc` runs automatically every time a new interactive shell starts.
- **Script file, via interpreter** — `zsh myscript.zsh` runs a file directly, non-interactively, top to bottom. No permissions or shebang needed, since you're naming the interpreter yourself.
- **Script file, as an executable** — needs a shebang line and execute permission:
```zsh
#!/usr/bin/env zsh
echo "Hello World"
```
```bash
chmod +x hello_world.zsh   # do this once, grants execute permission
./hello_world.zsh
```
**Shebang** (`#!...`) — "sharp" + "bang". When run directly (`./file`), the kernel reads the first two bytes; if they're `#!`, it treats the rest of the line as the exact program to run the file with. `#!/usr/bin/env zsh` finds `zsh` on `$PATH` via `env` — portable across machines. Only matters for direct execution; irrelevant when you type `zsh file.zsh` yourself.
- **Login shell** — runs `.zprofile`/`.zlogin` in addition to `.zshrc`, only on actual login (SSH, TTY, or explicit `zsh -l`) — opening a new terminal window usually does NOT trigger this.

## Shell built-ins:

None of these are Linux/OS commands — no separate binary file exists for any of them (`type export` confirms: "export is a shell builtin"). They only exist because the shell itself implements them internally.

**Prompt** — `PROMPT` is a special variable zsh re-renders before every command. Its `%` codes are a mini-syntax that only means something inside `PROMPT`/`RPROMPT` — not general zsh scripting. Documented under `man zshmisc`, section `EXPANSION OF PROMPT SEQUENCES`. Same relationship as `printf`'s `%d`/`%s` being a mini-syntax inside C — not C itself.
```zsh
PROMPT='%F{190}%B%B%n@%m:%~$ %b%b%f' # %F{190} sets text color to yellow2 -> Based on 256 Xterm color code | %B turns bold on | %n = username | %m = hostname | %~ = current dir (~ if under home) | $ + space = literal | %b turns bold off | %f resets color back to default
```

**Alias** — text substitution; the shell swaps the short name for the real command before running it.
```zsh
alias ll='ls -la'
```

**Export** — makes a variable visible to child processes (programs you launch), not just the shell itself.
```zsh
export GREETING="hello"
```

**Source** (or the shorthand `.`) — runs a file's lines directly in the CURRENT shell session. Contrast: `zsh file.zsh` starts a separate new process; `source` does not.
```zsh
echo "export TEST=world" > test.zsh
zsh test.zsh
echo $TEST          # prints nothing — that separate process already ended
source test.zsh
echo $TEST          # prints "world" — ran directly in this shell
```
This is why `.zshrc` is reloaded with `source ~/.zshrc`, never `zsh ~/.zshrc` — you want the new `PROMPT`, aliases, and exports applied to your current terminal, not to a throwaway process that immediately exits.

**Change Directory** (shorthand - cd) - changes the current working directory
```zsh
cd ~  # changes the current working directory to home
``` 