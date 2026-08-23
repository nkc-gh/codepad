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

Declaring a variable without `local` makes it **global** — visible and overwritable from any other file/script running in the same host program. Always prefer `local`.

```lua
local x = 5   -- scoped to this file/chunk only
y = 5         -- global, visible everywhere, avoid this
```

Each file loaded via `require` is its own scope ("chunk"). A `local` in one file is not automatically visible in another — every file must `require` what it needs itself, even the file that did the loading.

```lua
-- main.lua
local wezterm = require 'wezterm'
local keys = require 'keybindings'
```
```lua
-- keybindings.lua
print(wezterm)                      -- ERROR: doesn't exist here
local wezterm = require 'wezterm'   -- must fetch it again, itself
print(wezterm)                      -- works now
```

**Why the first `print` doesn't work:**
- `main.lua` runs and creates `local wezterm` — but this only lives inside main.lua's own private box.
- `require 'keybindings'` opens keybindings.lua as a **brand-new, empty box**. Nothing from main.lua's box gets copied over.
- Inside keybindings.lua, `print(wezterm)` looks in its own box — finds nothing, since it was never declared there. Lua treats it as `nil` ("doesn't exist").
- The next line, `local wezterm = require 'wezterm'`, fetches a fresh copy into keybindings.lua's own box.
- Now `print(wezterm)` works — it refers to the one just declared in this same file.

**Mental model:** each `.lua` file is a separate room. Loading one file from another doesn't move furniture between rooms — the new room starts empty and has to bring in its own.