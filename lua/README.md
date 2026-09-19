# Lua

Lua is a lightweight, embeddable scripting language. "Embeddable" is the key word — Lua was designed from day one to live *inside* other programs (games, editors, terminal emulators) and let them be configured or extended, rather than to be run as standalone applications on its own.

Lua source runs through an interpreter. There's no separate linker step, no standalone `.exe` produced the way C or Java produces one — the host application (WezTerm, Neovim, a game engine) embeds the Lua interpreter itself and executes your `.lua` file directly.

```text
Lua source (.lua) -> compiled to bytecode internally, in memory -> run by the Lua VM inside the host program.
```

## Index

- [History](#history)
- [Sample code](#sample-code)
- [How Lua code compiles and runs](#how-lua-code-compiles-and-runs)
- [Data structures: only tables](#data-structures-only-tables)
- [Scope: local vs global](#scope-local-vs-global)

## History

Lua was created in 1993 at PUC-Rio (Pontifical Catholic University of Rio de Janeiro), Brazil, by Roberto Ierusalimschy, Luiz Henrique de Figueiredo, and Waldemar Celes.

It began as two smaller in-house languages, DEL and SOL, built for data-entry and configuration tasks on Petrobras (Brazilian oil company) projects. In 1993 the team merged both into one language and named it Lua (Portuguese for "moon").

Lua was built to be small, fast, portable, and easy to embed via a C API — not to compete as a general standalone language like Python. That embeddability is why it spread into games (World of Warcraft, Angry Birds), image software (Adobe Lightroom), and countless configuration systems (WezTerm, Neovim, Redis scripting).

## Sample code

**1. Hello World**
```lua
print("Hello, World!")
```
Output:
```text
Hello, World!
```

**2. Take input, say name**
```lua
io.write("Enter your name: ")
local name = io.read()
print("Hello, " .. name)
```
Output:
```text
Enter your name: nkc
Hello, nkc
```
- `io.write` — like `print`, but no trailing newline; keeps the prompt on the same line as typed input.
- `io.read()` — waits for input + Enter, returns it as a **string**.

**3. Take two inputs, add them, if/else**
```lua
io.write("Enter first number: ")
local a = tonumber(io.read())

io.write("Enter second number: ")
local b = tonumber(io.read())

local sum = a + b

if sum > 10 then
  print("Sum is " .. sum .. ", bigger than 10")
else
  print("Sum is " .. sum .. ", 10 or less")
end
```
Output:
```text
Enter first number: 7
Enter second number: 6
Sum is 13, bigger than 10
```
- `tonumber(io.read())` — `io.read()` always returns a **string**, even for digits; `tonumber()` converts it so `+` does real math, not text-joining.
- `if ... then ... else ... end` — plain `if`, no `[[ ]]`/`(( ))` split like zsh needs for strings vs numbers.

## How Lua code compiles and runs

Lua has no linker and no compile-to-binary step exposed to the user like `gcc` or `javac` — it never produces a standalone `.exe`/`.out`.

- **C's approach**: `gcc` translates source all the way down to real CPU machine code, once, into a self-contained binary file you can run anytime after, with no compiler present.
- **Lua's approach**: the `lua` interpreter translates your source into **bytecode internally, in memory**, fresh, every single time you run it — then the Lua VM executes that bytecode immediately. Nothing is saved to disk. This happens because Lua was designed to always be run *through* an interpreter (standalone `lua` binary, or a host app's embedded Lua VM) — never as an independent program on its own.

Two ways it actually runs:
- **Standalone interpreter** — `lua script.lua`, via the reference `lua` binary. Good for testing plain Lua on its own.
- **Embedded** — the host application (WezTerm, Neovim) has the Lua interpreter compiled into itself and executes your script internally. This is the common case for config files — you never call `lua` yourself; the host does it on startup.

There's no JVM-style "must match filename to entry point" rule. Any `require 'modulename'` looks for `modulename.lua` in a search path, or resolves to a module the host program has pre-registered (like WezTerm's own `wezterm` module — not a file on disk at all).

## Data structures: only tables

Lua has exactly one composite data structure: the **table** (`{ }`). No separate array type, no separate dict/map type — a table is both, depending on how it's filled.

```lua
{ 'a', 'b', 'c' }         -- array-style: auto keys 1, 2, 3
{ weight = 'Medium' }     -- dict-style: explicit string key
{ 'a', weight = 'Medium' }-- both at once, fully legal
```

## Scope: `local` vs `global`

### What is local and global

Declaring a variable **without** `local` makes it **global** — visible and overwritable from anywhere else in the program, no matter which file wrote it. Declaring it **with** `local` locks it to the exact block of code (function or file) it was created in, and nowhere else.

```lua
local x = 5   -- local: only exists inside this block/file
y = 5         -- global: visible everywhere, avoid this
```

### Simple example — two files

**main.lua**
```lua
local a = 10
b = 20
```

**main2.lua**
```lua
dofile("main.lua")
print(a)
print(b)
```

Running `lua main2.lua`:
```text
nil
20
```

- `a` was declared `local` inside `main.lua` → sealed there. `main2.lua` has no idea it exists → `nil`.
- `b` has no `local` → it's global → visible from `main2.lua` too → `20`.

`dofile("main.lua")` is just what makes `main.lua`'s code actually *run* before `main2.lua` tries to read anything from it — without running it first, both `a` and `b` would be `nil` simply because that code never executed at all.

### Why `local` can NEVER be reached from another file — no matter what

This isn't a missing feature you can work around — it's a hard rule at the language level. A `local` variable lives on that file's own call stack while it runs, and once the file finishes, it's gone — there is no leftover copy anywhere for another file to go find, through any mechanism:

```lua
-- main.lua
local a = 10
```

```lua
-- tries every possible way to reach `a` from outside
dofile("main.lua");            print(a)  --> nil
local x = require("main");     print(a)  --> nil
local c = loadfile("main.lua"); c(); print(a)  --> nil
```

Every single one prints `nil`. `dofile`, `require`, `loadfile` — none of them expose another file's locals. A **global**, by contrast, sits in one shared table Lua keeps for the whole running program (`_G`), which is exactly why any file can read or overwrite it. Locals never enter that shared table at all — there's simply nothing to fetch.

### The only real doorway out: `return`

The one and only way a file can hand a value to another file is by explicitly writing `return`:

```lua
-- main.lua
local a = 10
return a
```

```lua
-- main2.lua
local x = require("main")   -- x = 10, because main.lua RETURNED it
print(x)   --> 10
print(a)   --> still nil — `a` itself was never exposed, only its VALUE was handed over
```

Important distinction: `require` doesn't give you the other file's variable — it gives you **whatever that file put after `return`**, and you catch that value in a brand-new local variable of your own choosing. If `main.lua` has no `return` at all, `require` just gives back `true` (Lua's "loaded successfully, nothing returned" default) — completely unrelated to any local variable inside it, even one with a matching name.