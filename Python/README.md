# Python

Python is a general-purpose programming language.

It is used to write programs quickly and readably, trading away some of the raw speed and low-level control C and C++ give you, in exchange for code that is faster to write, easier to read, and easier to change. Python handles memory management, type checking (mostly), and a lot of other bookkeeping automatically, so the programmer can focus on what the program should do rather than how the machine does it.

Python lets us write human-readable code without having to compile it into machine code ahead of time, the way we typically do with C and C++. Instead, Python code is executed by the Python interpreter at runtime. In the standard Python implementation (CPython), the source code is first compiled into bytecode, which is then executed by the Python virtual machine. This is one of the major structural differences between Python and C/C++. Because Python code is commonly executed through an interpreter, Python is often called a scripting language, and `.py` files are commonly referred to as Python scripts. The `python3` command is used to run the Python interpreter.

Python is a high-level language. Where C is often called a "middle-level" language because it gives low-level control over memory and hardware, Python sits further up: it deliberately hides memory addresses, manual allocation, and pointers from the programmer entirely.

Simple idea:

```text
C/C++    = compiled ahead of time, close to hardware, manual memory management, fast, more code to write
Python   = interpreted at run time, far from hardware, automatic memory management, slower, less code to write
```

## Index

- [History](#history)
- [Why Python Was Created](#why-python-was-created)
- [Why Python Is So Popular Today](#why-python-is-so-popular-today)
- [Where Python Is Used](#where-python-is-used)
- [A Basic Python Program](#a-basic-python-program)
- [How A Python Program Actually Runs](#how-a-python-program-actually-runs)
- [Taking Input](#taking-input)
- [Variables And Data Types](#variables-and-data-types)
- [Type Checking And Dynamic Typing](#type-checking-and-dynamic-typing)
- [Operators And Precedence](#operators-and-precedence)
- [Control Flow](#control-flow)
- [Functions](#functions)
- [Strings In Depth](#strings-in-depth)
- [Lists, Tuples, Sets, And Dictionaries](#lists-tuples-sets-and-dictionaries)
- [Working With Files](#working-with-files)
- [Exception Handling](#exception-handling)
- [Modules And Imports](#modules-and-imports)
- [Object-Oriented Programming In Python](#object-oriented-programming-in-python)
- [pip — Python's Package Manager](#pip--pythons-package-manager)
- [Common Everyday Libraries](#common-everyday-libraries)
- [Errors](#errors)

## History

Python was created by Guido van Rossum, starting around Christmas of 1989, while working at Centrum Wiskunde & Informatica (CWI) in the Netherlands. The first official release, version 0.9.0, came out in February 1991.

Van Rossum was working on a language called ABC at the time, and had grown frustrated with some of its limitations. He wanted a hobby project to work on over the holidays that would keep him busy — something that took ABC's good ideas (readable syntax, ease of use) but was more practical and extensible for real-world programming.

The name "Python" has nothing to do with the snake. Van Rossum was a fan of the British comedy show *Monty Python's Flying Circus*, and simply wanted a name that was short, unique, and slightly mysterious.

Python's version history has a few major landmarks worth knowing:

```text
Python 1.0  (1994) — first stable public release, added lambda, map, filter, reduce
Python 2.0  (2000) — added list comprehensions, garbage collection, unicode support
Python 3.0  (2008) — a deliberate, non-backward-compatible redesign to fix early design mistakes
```

Python 2 and Python 3 lived side by side for a long time, and this caused real friction in the ecosystem: libraries had to support both, and many teams delayed moving to Python 3 for years. Python 2 officially reached its end of life on January 1, 2020, and stopped receiving updates, including security fixes. All modern Python work uses Python 3.

Simple idea:

```text
Python started as a holiday hobby project meant to improve on an existing language, ABC.
It is named after a comedy show, not the snake.
```

## Why Python Was Created

Python was created to make programming more readable and more accessible, without sacrificing the ability to actually build serious software with it.

By the time Python appeared, languages like C and C++ already existed and were (and still are) excellent at what they do — speed, control, closeness to hardware. But that power comes at a cost: you have to manage memory yourself, worry about pointer arithmetic, write more code to do simple things, and spend real effort on things that have nothing to do with the actual problem you're trying to solve.

Van Rossum wanted a language where:

```text
- code reads almost like plain English
- indentation and structure are enforced by the language itself, not just style convention
- a beginner could pick it up quickly, but an expert could still build large, serious systems with it
- memory management, type declarations, and other low-level bookkeeping are handled automatically
```

This is really the same underlying question C++ answered for C — "how do we add more structure and productivity on top of what came before?" — except Python takes it much further, giving up direct hardware control entirely in exchange for a much simpler, more forgiving language to write in.

Even after so many programming languages already existed by 1991 — and many more have been created since — Python kept growing precisely because "easy to read, easy to write, fast to develop in" is a need that never really goes away. Most programs are not bottlenecked by CPU speed; they're bottlenecked by how long it takes a human to write, debug, and maintain them. Python optimizes for that.

## Why Python Is So Popular Today

Python's popularity today comes from a combination of readability, an enormous ecosystem of ready-made libraries, and its role as the default language of data science, machine learning, and AI.

A few concrete reasons:

```text
- syntax is close to plain English, and enforced indentation keeps code visually consistent across projects
- an enormous standard library ("batteries included") plus an even larger third-party ecosystem via pip
- one of the easiest languages for a total beginner to start with
- the dominant language for data science, machine learning, and AI research (NumPy, pandas, PyTorch, TensorFlow, scikit-learn)
- widely used for automation and scripting — small everyday tasks (renaming files, scraping a website, processing a spreadsheet) are quick to write
- strong web development frameworks (Django, Flask, FastAPI)
- runs on essentially every platform (Windows, macOS, Linux) without modification
- a very large, active community, meaning help, tutorials, and libraries exist for almost anything you want to do
```

Python is rarely the fastest choice for raw performance-critical work (that is still usually C, C++, or Rust), but it is very often the fastest choice for *developer* time — how quickly an idea becomes working code. In fields like data science and AI, where experimentation and iteration speed matter more than raw execution speed, that trade-off has made Python the default language almost everywhere.

## Where Python Is Used

Common uses of Python:

- data science and data analysis
- machine learning and artificial intelligence
- web development (backend, using frameworks like Django, Flask, FastAPI)
- automation and scripting (small everyday tasks, file handling, task scheduling)
- web scraping
- scientific computing and numerical research
- automated testing
- DevOps and infrastructure tooling
- game prototyping (less common for full commercial games, but common for prototypes and tools)
- teaching programming to beginners

## A Basic Python Program

A simple Python program looks like this:

```python
print("Hello, World!")
```

That's the entire program. One line. Compare this to C:

```c
#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    return 0;
}
```

There is no `#include`, no `main` function, no return type, no semicolon, no curly braces. Let's go through exactly why, line by line (in this case, just the one line).

`print` is a built-in function. It does not need to be imported or declared anywhere — it is simply always available the moment the Python interpreter starts, the same way `printf` is always declared once you `#include <stdio.h>` in C. The difference is Python doesn't require that include step at all for its most basic tools; a set of built-in functions (`print`, `len`, `input`, `range`, and others) are automatically available in every Python program with zero setup.

`(` and `)` call the function, exactly like in C — `print(...)` means "run the function named `print`, passing it whatever is inside the parentheses."

`"Hello, World!"` is a string literal, Python's built-in text type. Unlike C, where a string is really just a `char` array you build and manage yourself, Python has a real, built-in `str` type. Single quotes (`'Hello'`) and double quotes (`"Hello"`) both work identically in Python — there is no functional difference, only style preference.

There is no `\n` written anywhere, but the output still ends with a new line. `print` automatically adds a newline at the end of whatever it prints, unless told not to. This is a small default behavior baked into `print` itself, to save you from typing `\n` every single time, since printing a line of text followed by a newline is by far the most common case.

There is no semicolon at the end of the line. Python does not use semicolons to mark the end of a statement — a new line is enough. (Semicolons can technically be used to put multiple statements on one line, but this is unusual and generally discouraged in normal Python code.)

There is no `main` function, and no `return 0`. Python does not require a special entry-point function the way C requires `main`. A Python file is simply run from top to bottom, in order, starting at the very first line. (There is a common convention, `if __name__ == "__main__":`, used in larger programs to control what runs when a file is executed directly versus imported elsewhere — covered later in [Modules And Imports](#modules-and-imports) — but it is a convention, not a language requirement, unlike C's `main`.)

There is no explicit "success" exit code written anywhere either. Python programs automatically exit with status `0` (success) when they reach the end of the file normally, without needing you to state that yourself.

Simple idea:

```text
Python's Hello World has no includes, no entry-point function, no semicolons, no explicit return.
The language fills in all of that structure for you, automatically, by default.
```

## How A Python Program Actually Runs

This is the single biggest structural difference between Python and C/C++, so it deserves its own full section, the same way the C readme has a full section on `gcc` and linking.

Recall the C journey:

```text
C Source Code -> Preprocessing -> Compilation -> Assembly -> Object Code -> Linking -> Executable File -> Run Time
```

All of that happens *before* the program ever runs. By the time you type `./hello`, the CPU is executing raw machine code directly — there is no C left in the picture at all at that point.

Python does not work this way. There is no separate build step you run ahead of time, no `gcc`-style command that produces a standalone executable, and no direct machine code sitting in a file waiting to be run by the CPU. Instead, Python code is read and executed by another program — the **interpreter** — while your program is running.

```bash
python3 hello.py
```

When you type this, `python3` is itself a real, compiled program (written mostly in C) sitting on your computer, exactly like any other executable. `hello.py` is not compiled into machine code the way `hello.c` would be. Instead, the `python3` program opens `hello.py`, reads through it, and carries out each instruction itself, one at a time, translating and executing as it goes.

### CPython, The Reference Interpreter

There isn't just one single "Python." Python is a language specification — a set of rules describing how the language should behave — and multiple different programs implement those rules. The interpreter you get by typing `python3` on almost every machine is called **CPython**, so named because it is itself written in C. It is the original, reference implementation, and by far the most widely used.

```text
CPython    -> the standard, most common implementation, written in C (what "python3" almost always means)
PyPy        -> an alternative implementation with a Just-In-Time (JIT) compiler, often much faster
Jython       -> runs Python on the Java Virtual Machine
IronPython    -> runs Python on .NET
```

Everything in this readme describes CPython's behavior, since it's what "Python" means for the overwhelming majority of programmers.

### The Real Steps: Source -> Bytecode -> PVM

Even though there's no separate build step *you* invoke, CPython does not literally re-read and re-interpret your raw text character by character every single time a line runs. There is a translation step happening internally, just automated and hidden from you, and happening at run time instead of ahead of time.

```text
hello.py (source code)
    |
    v
Compilation to bytecode   (automatic, done by CPython itself, in memory)
    |
    v
.pyc file (compiled bytecode, cached)
    |
    v
Python Virtual Machine (PVM) executes the bytecode
    |
    v
Output
```

**Bytecode** is a lower-level, intermediate set of instructions — not the human-readable Python you wrote, but also not raw CPU machine code either. It sits in between, similar in spirit to how C's assembly code sits between C source and final machine code, except bytecode is not tied to any particular CPU. The same bytecode can run on any machine that has a compatible CPython interpreter installed, whether it's Windows, macOS, or Linux, on an Intel chip or an ARM chip.

You can actually see this happen yourself. If you write a Python file that gets imported by another file (covered in [Modules And Imports](#modules-and-imports)), CPython automatically creates a cached, compiled version of it:

```text
mymodule.py
__pycache__/mymodule.cpython-312.pyc
```

That `.pyc` file is the compiled bytecode, cached so that the next time the file is imported, CPython can skip the compilation step and load the bytecode directly, saving time. (Notice this caching only reliably happens for *imported* files, not the one main script you run directly — the file you launch with `python3 hello.py` is compiled to bytecode in memory every time, but not written to a `.pyc` file on disk.)

The **Python Virtual Machine (PVM)** is the part of the CPython program that actually reads this bytecode and carries it out, instruction by instruction. "Virtual machine" here does not mean a whole simulated computer, like a VirtualBox virtual machine — it means a piece of software that behaves like a very simple CPU, understanding a small, fixed set of bytecode instructions and executing them one by one. This is the part actually running when your Python program is "running."

You can look at this bytecode yourself using Python's built-in `dis` (disassemble) module:

```python
import dis

def add(a, b):
    return a + b

dis.dis(add)
```

Output (may vary slightly by Python version):

```text
  4           0 LOAD_FAST                0 (a)
              2 LOAD_FAST                1 (b)
              4 BINARY_OP                0 (+)
              8 RETURN_VALUE
```

This is directly analogous to using `objdump -d` on a compiled C program to see its assembly, covered in the C readme's [Inspecting Compiled Code](../C/README.MD#inspecting-compiled-code) section — except here, you're looking at Python's own intermediate instruction set, not real CPU assembly.

### How The PVM Actually Executes This Bytecode

Seeing the bytecode is one thing. Understanding what the PVM actually *does* with each line of it is the real answer to "how does Python run." Let's trace through the exact example above, `add(a, b)`, called as `add(5, 3)`.

```python
import dis

def add_numbers(a, b):
    return a + b

# Disassemble the function to see its bytecode instructions
dis.dis(add_numbers)
```

Output:

```text
  4           0 LOAD_FAST                0 (a)
              2 LOAD_FAST                1 (b)
              4 BINARY_OP                0 (+)
              8 RETURN_VALUE
```

The PVM does not understand `a` or `b` as named variables at this point — by the time your source code reaches bytecode, names have already been resolved down to plain numbered slots. `LOAD_FAST 0` means "slot 0," `LOAD_FAST 1` means "slot 1." `(a)` and `(b)` shown in the output above are just labels added for *your* benefit — the PVM itself only ever sees the numbers `0` and `1`.

The PVM works using a **stack** — a small pile of values where the last thing placed on top is the first thing taken back off, exactly like the C++ readme's `std::stack` (LIFO). Every bytecode instruction either pushes a value onto this stack, or pops values off it to do something with them. Walking through the four instructions above, one at a time, with `a = 5` and `b = 3` already sitting in local slots 0 and 1:

```text
Instruction:            What the PVM does:                              Stack after:

LOAD_FAST 0 (a)     ->  push locals[0]  (which is 5)                    [5]
LOAD_FAST 1 (b)     ->  push locals[1]  (which is 3)                    [5, 3]
BINARY_OP 0 (+)     ->  pop -> 3
                         pop -> 5
                         compute 5 + 3 = 8
                         push 8                                          [8]
RETURN_VALUE        ->  pop -> 8, hand this back to the caller           []
```

`BINARY_OP` doesn't inherently "know" it's addition — the `0` next to it is an index into a small internal table of operations the PVM keeps; `0` happens to mean "+". If your code had written `a - b` instead, you'd see the same instruction name, `BINARY_OP`, just with a different number next to it, pointing at subtraction instead.

### What The PVM's Own Code Actually Looks Like

Remember from earlier: the PVM is not a separate program. It is a loop, written in C, already compiled into the `python3` binary the moment it starts. Stripped down to its essence, it looks roughly like this:

```c
int stack[100];
int top = 0;

void push(int value) {
    stack[top] = value;
    top = top + 1;
}

int pop(void) {
    top = top - 1;
    return stack[top];
}

// THE PVM LOOP -- a "fake CPU" that only understands a fixed set of instructions
while (there are more bytecode instructions) {

    instruction = get_next_instruction();

    if (instruction == LOAD_FAST) {
        push(locals[instruction.arg]);
    }
    else if (instruction == BINARY_OP) {
        int right = pop();
        int left  = pop();
        push(left + right);        // <-- this line is where "+" actually happens
    }
    else if (instruction == RETURN_VALUE) {
        return pop();
    }
}
```

This loop, and every branch inside it, was already sitting inside the `python3` binary as real, compiled machine code before your file even existed — nothing here is generated fresh for your program. What changes every time you run a different `.py` file is only the *list of bytecode instructions* fed into this loop; the loop's own logic never changes.

`push(left + right)` is the one line that matters most for your question of "who does the plus." That `+` is a plain, ordinary C addition. It gets compiled — once, years ago, when `python3` itself was built — into a single real CPU instruction, something like:

```asm
add %edx, %eax
```

That instruction is not Python, not bytecode, and not really even "C" anymore at this point — it's a raw instruction understood directly by the processor's ALU (Arithmetic Logic Unit), physical circuitry that performs binary addition in hardware. That's the actual, honest bottom of the chain:

```text
Python:    a + b
Bytecode:  BINARY_OP 0 (+)                (just a number — meaningless to any real CPU on its own)
PVM (C):   push(left + right)              (a fixed, already-compiled loop reacting to that number)
Compiled:  add %edx, %eax                   (a real x86/ARM instruction, decided when python3 was built)
Hardware:  the CPU's ALU flips bits          (the only place actual "work" happens)
```

(CPython's real internal code for integer addition, `long_add` in `Objects/longobject.c`, is more involved than this simplified loop, because Python's `int` has no fixed size and can grow arbitrarily large — it first checks whether both numbers are small enough to fit a normal machine register, and only then does a plain C `+` like the one shown above; very large numbers instead go through a slower, manual digit-by-digit addition path. The simplified loop above captures the core idea faithfully for ordinary-sized numbers, which is the overwhelming majority of real Python code.)

### Why This Makes Python "Interpreted"

Because this compile-to-bytecode step happens automatically, in memory (or cached to a `.pyc` file), every time you run the program, rather than once ahead of time producing a standalone executable, Python is classified as an **interpreted language**, while C and C++ are classified as **compiled languages**.

```text
Compiled (C/C++):    source -> machine code, done once, ahead of time -> standalone executable -> run any time later, no compiler needed
Interpreted (Python): source -> bytecode -> PVM executes it, redone (or reloaded from cache) essentially every run -> the interpreter must be present to run it at all
```

This is also exactly why you can't just double-click a `.py` file on a machine that doesn't have Python installed, the way you might run a `.exe` on Windows without needing anything extra — the `.py` file is not a standalone program. It is only instructions for another program (the interpreter) to carry out. Without CPython installed, there is nothing on the machine that knows how to read it.

### Where Libraries Fit In

When your code does something like:

```python
import math
print(math.sqrt(16))
```

`import math` does not "include declarations" the way `#include <stdio.h>` does in C. There is no separate linking step here at all. Instead, `import` tells the PVM, right there at run time, to locate the `math` module, load it into memory, run through its own contents, and make its names (like `sqrt`) available in your program from that point onward. Some standard library modules like `math` are actually implemented in C internally, for speed, and exposed to Python as if they were normal modules — but this detail is invisible from the Python side; `math.sqrt(16)` looks and behaves the same either way.

This is also why Python has no separate "linker" step the way C does: there is no final executable being assembled ahead of time that needs all its pieces connected beforehand. Everything is resolved live, while the program is actually running.

Simple idea:

```text
C/C++ finish all their translation work before the program ever starts running, producing a standalone file.
Python does its translation (source -> bytecode) automatically, at run time, using another program (CPython) present on the machine, every time you run it.
```

## Taking Input

`input()` reads a line of text typed by the user, from the keyboard (standard input), and returns it.

```python
age = input("Enter your age: ")
print("You are " + age + " years old")
```

Output (user types `25`):

```text
Enter your age: 25
You are 25 years old
```

Notice there is no equivalent of C's `&age`, no format specifier like `%d`, and no separate variable declaration beforehand. `input()` simply returns whatever was typed, directly, and `age = input(...)` stores that returned value in a new variable, created right there on the spot.

### input() Always Returns A String

This is a very common beginner trap. Even if the user types `25`, `input()` gives you back the *text* `"25"`, not the number `25`. If you try to do math with it directly, you'll get a string-related error or unexpected behavior instead of a calculation.

```python
age = input("Enter your age: ")
next_year = age + 1   # error — can't add an int to a string
```

To actually use it as a number, it needs to be explicitly converted:

```python
age = input("Enter your age: ")
age = int(age)
next_year = age + 1

print("Next year you will be " + str(next_year))
```

`int(age)` converts the string into an integer. `str(next_year)` converts the integer back into a string so it can be joined with other text using `+` (covered in [Strings In Depth](#strings-in-depth)).

This whole pattern is usually written in one line:

```python
age = int(input("Enter your age: "))
```

Here, `input(...)` runs first and returns a string, and `int(...)` immediately converts that string before it's ever stored in `age`.

Simple idea:

```text
input() always returns a string, no matter what the user types.
Convert it explicitly (int(), float(), etc.) before using it as a number.
```

## Variables And Data Types

A variable is a named reference to a value. Unlike C, where declaring `int age = 25;` reserves a specific, fixed-size chunk of memory and tells the compiler exactly how to interpret the bits stored there, Python variables do not declare a type at all, and do not reserve a fixed memory size up front.

```python
age = 25
```

There is no `int`, no type keyword, nothing. `age` is simply a name now pointing to the value `25`, wherever Python has actually placed that value in memory. This works because in Python, **the value carries its own type, not the variable**. `age` itself has no type; the object `25` that `age` currently refers to is what has a type.

### Basic Data Types

```python
a = 10          # int
b = 3.14        # float
c = "hello"     # str
d = True        # bool
e = None        # NoneType
```

```text
int      = whole numbers, any size (see below — this is different from C)
float    = decimal numbers (Python only has one floating-point type, unlike C's float/double split)
str      = text, Python's built-in string type
bool     = True or False, a real, dedicated type (unlike C, which uses plain ints for this)
NoneType = represents "no value at all" — Python's equivalent of NULL/nullptr, written as None
```

You can check any value's type using the built-in `type()` function:

```python
age = 25
print(type(age))
```

Output:

```text
<class 'int'>
```

### int Has No Fixed Size

In C, `int` is typically 4 bytes, giving it a fixed maximum range, and overflowing that range causes undefined behavior or silent wraparound. Python's `int` has no fixed size at all — it grows automatically to hold however large a number actually is, limited only by your computer's available memory.

```python
big_number = 99999999999999999999999999999999
print(big_number * big_number)
```

This runs completely normally in Python, producing the full, exact, correct result, no matter how large the number gets. There is no equivalent of C's integer overflow to worry about with plain arithmetic on `int`.

### float Is Always "Double Precision"

Python does not distinguish between `float` and `double` the way C does. Python's `float` type is always a 64-bit, double-precision floating-point number internally — the name `float` in Python does not mean the same thing as C's single-precision `float`.

### bool Is A Real Type, And A Subtype Of int

Unlike C, where comparisons produce plain integers (`0` or `1`), Python has an actual `bool` type, with the values `True` and `False` (capitalized — this matters, `true`/`false` lowercase do not exist in Python).

```python
is_adult = True
print(is_adult)
print(is_adult + 1)
```

Output:

```text
True
2
```

Internally, `True` behaves like `1` and `False` behaves like `0` in arithmetic — `bool` is technically a subtype of `int` in Python — but printing a `bool` shows `True`/`False`, not `1`/`0`, unlike C's `printf("%d", isAdult)`, which would show `1`.

### None — Python's "No Value"

`None` is a special, unique value representing the absence of a value, similar in purpose to C's `NULL`/`nullptr`, but it is its own distinct type (`NoneType`), not secretly the number `0` the way C's `NULL` traditionally was.

```python
result = None

if result is None:
    print("No result yet")
```

Note the use of `is` rather than `==` when checking against `None` — this is the conventional, correct way to do it in Python, and is explained further in [Operators And Precedence](#operators-and-precedence).

### Type Conversion (Casting)

Converting between types is done with built-in functions, rather than a cast syntax like C's `(float)`:

```python
a = int("10")       # string -> int
b = float("3.14")   # string -> float
c = str(42)         # int -> string
d = int(3.99)       # float -> int, TRUNCATES (does not round) -> 3
```

```python
result = int(7 / 2)      # 7 / 2 = 3.5 first, then truncated to 3
print(result)
```

Output:

```text
3
```

Simple idea:

```text
In C, the VARIABLE has a fixed type and fixed size.
In Python, the VALUE has a type; the variable is just a name pointing at whatever value it currently refers to.
```

## Type Checking And Dynamic Typing

C is a **statically typed** language: every variable's type is fixed at compile time, checked by the compiler before the program ever runs, and it cannot change afterward. Writing `int x = 10; x = "hello";` is a compile-time error in C — the types simply don't match, and the compiler refuses to build the program at all.

Python is a **dynamically typed** language: types are checked at run time, not ahead of time, and a variable name can be reassigned to a value of a completely different type at any point.

```python
x = 10          # x currently refers to an int
print(x)

x = "hello"     # now x refers to a string instead — completely legal
print(x)
```

Output:

```text
10
hello
```

This is legal in Python precisely because of what was explained above: `x` never had a type to begin with. It's just a name, and it's free to point at a different kind of value whenever you reassign it. No compiler exists to object beforehand, because there is no separate compile-time type-checking stage in Python the way there is in C.

### Where This Bites You

Because there's no compiler catching type mistakes ahead of time, a type-related mistake in Python often isn't discovered until the exact line of code that has the problem actually runs — which might be deep inside a program, in a rarely used code path, long after the program otherwise seemed to work fine.

```python
def add(a, b):
    return a + b

print(add(2, 3))          # 5, fine
print(add("2", "3"))      # "23", string concatenation, not addition, but a "type-valid" operation
print(add(2, "3"))        # TypeError: unsupported operand type(s) — only crashes when THIS line runs
```

The last line is only discovered at run time, precisely when Python attempts to actually add an `int` and a `str` together and finds it doesn't know how. In C, mismatched types like this are usually caught immediately, at compile time, before the program ever gets to run at all.

This trade-off — flexibility and less code to write, versus catching mistakes later rather than sooner — is one of the most fundamental differences between languages like Python and languages like C/C++, and it shapes a lot of how larger Python codebases are tested and organized.

### Type Hints (Optional, Not Enforced)

Modern Python allows writing optional type hints, purely as documentation and for external tools — they are not checked or enforced by the Python interpreter itself at run time.

```python
def add(a: int, b: int) -> int:
    return a + b

add(2, "3")   # still runs at run time, and still crashes with a TypeError — the hint is not enforced by Python itself
```

`a: int`, `b: int`, and `-> int` are all hints, telling a human reader (or an external tool like `mypy`) what types are expected. The Python interpreter itself does not check these at run time; it will happily let you call `add(2, "3")` and only fail when the `+` inside actually runs into mismatched types, exactly the same as without the hints. Type hints are a convention for readability and tooling, not a language-enforced feature like C's type system.

Simple idea:

```text
Static typing (C/C++): types fixed and checked before the program runs.
Dynamic typing (Python): types checked live, as each line actually runs — mistakes surface later, not sooner.
Python's type hints are optional documentation, not an enforced type system.
```

## Operators And Precedence

Most operators work the same conceptually as C, with a few Python-specific differences worth calling out.

### Arithmetic Operators

```python
a = 10
b = 3

a + b    # addition -> 13
a - b    # subtraction -> 7
a * b    # multiplication -> 30
a / b    # division -> 3.3333333333333335 (ALWAYS produces a float, unlike C)
a // b   # floor division -> 3 (divides, then rounds DOWN toward negative infinity)
a % b    # modulus, remainder -> 1
a ** b   # exponentiation -> 1000 (10 to the power of 3) — C has no built-in operator for this at all
```

`/` is a key difference from C. In C, `10 / 3` performs integer division and gives `3`, silently discarding the remainder, because both operands are `int`. In Python, `/` is "true division" — it always produces a `float`, even when dividing two whole numbers evenly (`10 / 2` gives `5.0`, not `5`). If you specifically want integer-style division (rounding down, discarding the remainder), Python requires you to use `//` explicitly instead.

```python
print(10 / 3)    # 3.3333333333333335
print(10 // 3)    # 3
```

`**` is exponentiation, built directly into the language as an operator. C has no equivalent operator at all; it requires calling `pow()` from `math.h` instead.

### Comparison Operators

```python
a == b   # equal to
a != b   # not equal to
a > b    # greater than
a < b    # less than
a >= b   # greater than or equal to
a <= b   # less than or equal to
```

These all produce a real `bool` (`True`/`False`), unlike C, which produces a plain `int` (`1`/`0`).

### Logical Operators

Python spells its logical operators out as words, rather than using symbols like C's `&&`, `||`, and `!`.

```python
a and b   # logical AND
a or b    # logical OR
not a     # logical NOT
```

```python
age = 20
has_id = True

if age >= 18 and has_id:
    print("Allowed in")
```

### is vs ==

This is a distinction that doesn't exist in C at all, and trips up a lot of people coming from other languages. `==` checks whether two values are *equal*. `is` checks whether two variables refer to the *exact same object* in memory — closer to comparing two C pointers for the same address, rather than comparing the values they point to.

```python
a = [1, 2, 3]
b = [1, 2, 3]
c = a

print(a == b)   # True  — same VALUES
print(a is b)   # False — two DIFFERENT objects in memory, even though they look identical
print(a is c)   # True  — c refers to the exact same object as a
```

The conventional exception is `None`: it is checked with `is`, not `==` (`if x is None:`), by strong convention, partly because `None` is guaranteed to be a single, unique object that only ever exists once, no matter how many variables refer to it.

### Chained Comparisons

Python allows chaining comparisons together in a way C does not support at all.

```python
age = 20

if 18 <= age <= 65:
    print("Working age")
```

In C, this exact same expression, `18 <= age <= 65`, would technically compile, but would not do what you expect — it would evaluate `18 <= age` first (giving `1` or `0`), then compare *that result* against `65`, which is almost always true and not the intended check at all. Python's chained comparison is a real, intentional language feature that checks both conditions properly against `age`.

### Assignment Operators

```python
a = 10
a += 5   # a = a + 5
a -= 5   # a = a - 5
a *= 5   # a = a * 5
a /= 5   # a = a / 5
a //= 5  # a = a // 5
a **= 2  # a = a ** 2
```

Notice there is no `a++` or `a--` in Python at all — these do not exist as operators here. You must write `a += 1` or `a -= 1` instead.

### Operator Precedence

Precedence works the same conceptually as in C — higher-precedence operators run first.

```text
()                        parentheses, evaluated first
**                        exponentiation
* / // %                  multiplication, division, floor division, modulus
+ -                       addition, subtraction
< <= > >= == !=            comparisons
not                        logical NOT
and                        logical AND
or                         logical OR
=  +=  -=  etc.            assignment, evaluated last
```

```python
result = 2 + 3 * 4
print(result)
```

Output:

```text
14
```

Just like in C, `*` runs before `+`, so this is `2 + (3 * 4)`, not `(2 + 3) * 4`. Parentheses can always be used to force a specific order.

Simple idea:

```text
/ always gives a float in Python; use // for integer-style (floor) division.
** is a real exponent operator, built into the language.
is checks identity (same object); == checks equality (same value).
There is no ++ or -- in Python.
```

## Control Flow

The biggest structural difference from C here isn't the logic — it's how blocks of code are marked at all.

### No Curly Braces — Indentation Is The Syntax

In C, `{ }` marks where a block of code starts and ends; indentation is just a readability convention on top of that, and technically optional (though obviously bad practice to skip). In Python, there are no curly braces at all. **Indentation itself is the syntax** that defines a block. A consistent indentation level (4 spaces is the near-universal convention) is not optional style — it is how Python knows which lines belong inside a block and which don't.

```python
age = 20

if age >= 18:
    print("Adult")
    print("Can vote")
else:
    print("Minor")
```

Every line indented under `if age >= 18:` belongs to that block. The moment indentation returns to a shallower level, the block has ended. Mismatched or inconsistent indentation is a real, common source of `IndentationError` in Python — something that has no equivalent category of error in C at all.

A colon `:` always introduces a new indented block — after `if`, `else`, `elif`, `for`, `while`, `def` (functions), and `class` (covered later), among others.

### if / elif / else

```python
marks = 75

if marks >= 90:
    print("A")
elif marks >= 75:
    print("B")
elif marks >= 50:
    print("C")
else:
    print("Fail")
```

Output:

```text
B
```

`elif` is Python's version of C's `else if` — written as one word. Just like in C, only the first true branch runs; the rest are skipped.

### No switch (Until Recently)

For most of Python's history, there was no `switch` statement at all — long `if`/`elif` chains, or a dictionary of functions, were used instead. Python 3.10 (released in 2021) introduced `match`, which serves a similar purpose but is considerably more powerful (it can match on structure/patterns, not just exact values).

```python
day = 3

match day:
    case 1:
        print("Monday")
    case 2:
        print("Tuesday")
    case 3:
        print("Wednesday")
    case _:
        print("Unknown")
```

Output:

```text
Wednesday
```

`case _:` is the default/fallback case, matching anything not caught above it, similar to `default:` in C's `switch`. Unlike C's `switch`, there is no fall-through by default in `match` — each `case` automatically stops after running, with no `break` needed at all.

### while

```python
i = 1

while i <= 5:
    print(i)
    i += 1
```

Output:

```text
1
2
3
4
5
```

This works exactly like C's `while`: the condition is checked before each run of the loop body.

### There Is No do-while

Python does not have a `do-while` loop at all. If you need a loop that always runs at least once, the common pattern is a `while True:` loop with a `break` inside:

```python
while True:
    response = input("Continue? (y/n): ")
    if response == "n":
        break
```

### for — Very Different From C

This is one of the biggest surface-level differences from C. Python's `for` loop does not use a counter/condition/increment structure at all (`for (int i = 0; i < 5; i++)` has no direct equivalent). Instead, Python's `for` always loops over the items of something iterable — directly, the same underlying idea as C++'s range-based `for`, except Python has no other kind of `for` loop at all.

```python
for i in range(1, 6):
    print(i)
```

Output:

```text
1
2
3
4
5
```

`range(1, 6)` produces a sequence of numbers starting at `1`, stopping *before* `6` — so `1, 2, 3, 4, 5`. The stopping value is always exclusive. `range(5)` alone (one argument) starts at `0` automatically, giving `0, 1, 2, 3, 4` — this is the closest equivalent to C's classic `for (int i = 0; i < 5; i++)`.

```python
fruits = ["apple", "banana", "cherry"]

for fruit in fruits:
    print(fruit)
```

Output:

```text
apple
banana
cherry
```

This reads directly as "for each `fruit` in `fruits`, do the following" — there is no index variable at all unless you specifically ask for one. To get both the index and the value while looping, `enumerate()` is used:

```python
for index, fruit in enumerate(fruits):
    print(index, fruit)
```

Output:

```text
0 apple
1 banana
2 cherry
```

### break And continue

These work exactly the same as in C.

```python
for i in range(1, 11):
    if i == 5:
        break
    print(i)
```

Output:

```text
1
2
3
4
```

```python
for i in range(1, 6):
    if i == 3:
        continue
    print(i)
```

Output:

```text
1
2
4
5
```

### Nested Loops

```python
for i in range(1, 3):
    for j in range(1, 4):
        print("i=" + str(i) + " j=" + str(j))
```

Output:

```text
i=1 j=1
i=1 j=2
i=1 j=3
i=2 j=1
i=2 j=2
i=2 j=3
```

Simple idea:

```text
Indentation replaces { } entirely — it is not optional style, it IS the block structure.
for always loops over an iterable (a range, a list, etc.) — there is no classic counter-based for.
There is no do-while and, until Python 3.10, no switch equivalent at all.
```

## Functions

A function is defined with the `def` keyword, followed by a name, parentheses, and a colon — with the body indented underneath, following the same indentation rule as everything else.

```python
def greet():
    print("Hello")

greet()
```

Output:

```text
Hello
```

Compare this to C's `void greet(void) { printf("Hello\n"); }`. There is no return type written at all (Python figures out whether a function returns something, and what, purely from what `return` statements exist inside it), no `void` needed for "takes no arguments," and no braces — just the colon and indentation.

### Parameters, Arguments, And Return Values

```python
def add(a, b):
    return a + b

result = add(2, 3)
print(result)
```

Output:

```text
5
```

No types are written next to `a` and `b` at all (recall [Type Checking And Dynamic Typing](#type-checking-and-dynamic-typing) — this `add` function would run on strings, lists, or anything else supporting `+`, without ever needing a second overloaded version the way C++ would require). `return` sends a value back to the caller, exactly like in C.

A function with no `return` statement at all, or a bare `return` with nothing after it, automatically returns `None`.

```python
def greet():
    print("Hello")

result = greet()
print(result)
```

Output:

```text
Hello
None
```

### Default Arguments

Just like C++, Python allows giving a parameter a default value, used automatically if the caller doesn't provide it.

```python
def greet(name="Guest"):
    print("Hello, " + name)

greet("Alice")
greet()
```

Output:

```text
Hello, Alice
Hello, Guest
```

Unlike C++, a default argument does not strictly need to be the last parameter as an absolute rule tied to position the same way — but any parameter *with* a default must still come after all parameters *without* one, for the same underlying reason: Python has to be able to tell which arguments you meant for which parameters.

### Keyword Arguments

Arguments can be passed by name, rather than by position, which is common enough in Python to be worth calling out specifically, since C has no equivalent at all.

```python
def describe(name, age):
    print(name + " is " + str(age) + " years old")

describe(age=30, name="Alice")   # order doesn't matter, since names are given explicitly
```

Output:

```text
Alice is 30 years old
```

### Variable Number Of Arguments (*args and **kwargs)

Python allows a function to accept an arbitrary number of arguments, something C cannot do directly at all without resorting to more complex tricks like variadic functions (`printf` itself is one, implemented with special macros in `stdarg.h`).

```python
def add_all(*numbers):
    total = 0
    for n in numbers:
        total += n
    return total

print(add_all(1, 2, 3))
print(add_all(1, 2, 3, 4, 5))
```

Output:

```text
6
15
```

`*numbers` collects any number of positional arguments into a single tuple (covered in [Lists, Tuples, Sets, And Dictionaries](#lists-tuples-sets-and-dictionaries)) named `numbers`, inside the function.

`**kwargs` does the same thing, but for keyword arguments, collecting them into a dictionary:

```python
def describe(**details):
    for key, value in details.items():
        print(key + ": " + str(value))

describe(name="Alice", age=30)
```

Output:

```text
name: Alice
age: 30
```

Simple idea:

```text
def defines a function; indentation marks its body, same rule as everywhere else.
No types are declared on parameters or the return value.
*args and **kwargs let a function accept a flexible number of arguments — no direct C equivalent.
```

## Strings In Depth

Recall from the C readme that a C string is just a `char` array ending in `\0`, with no real "type" of its own, and needing functions like `strcat`/`strcmp` to do basic things. Python's `str` is a real, built-in type, closer in spirit to C++'s `std::string`, but immutable — once created, a string's contents can never be changed in place; any operation that looks like it's "modifying" a string is really creating a brand new one.

```python
name = "Alice"
print(name)
```

### Common Operations

```python
first = "Hello"
second = "World"

combined = first + " " + second   # concatenation with +
print(combined)
print(len(combined))                # length — a built-in function, not a method here
print(combined[0:5])                 # slicing — characters from index 0 up to (not including) 5
print(first == "Hello")               # comparison with ==
print(combined.upper())                # uppercase
print(combined.lower())                # lowercase
```

Output:

```text
Hello World
11
Hello
True
HELLO WORLD
hello world
```

`len()` works the same conceptually as C++'s `.length()`, but in Python it is a standalone built-in function applied to the string, rather than a method belonging to it — `len(combined)`, not `combined.len()`. This pattern (`len()` working on strings, lists, and other collections alike) is common across Python.

### Slicing

Slicing is a Python-specific feature with no direct equivalent as a language construct in C or C++ — it lets you pull out a sub-portion of a string (or list) using `[start:stop]` notation.

```python
text = "Hello, World!"

print(text[0:5])    # "Hello" — index 0 up to (not including) 5
print(text[7:])      # "World!" — from index 7 to the end
print(text[:5])       # "Hello" — from the start up to (not including) 5
print(text[-6:])       # "World!" — negative indices count from the end
```

Negative indices are another Python-specific convenience: `-1` means the last character, `-2` the second-to-last, and so on — there is no equivalent in C, where you'd have to compute `length - 1` manually.

### f-strings — Formatted String Literals

This is the modern, standard way to build strings that include variable values, introduced in Python 3.6, and closer in purpose to using multiple `<<` with `std::cout`, or `printf`'s format specifiers, but generally considered cleaner than either.

```python
name = "Alice"
age = 30

message = f"{name} is {age} years old"
print(message)
```

Output:

```text
Alice is 30 years old
```

The `f` immediately before the opening quote marks it as an f-string. Anything inside `{ }` is evaluated as a real Python expression and inserted directly into the string — not just a variable name, but any expression at all:

```python
a = 5
b = 3
print(f"{a} + {b} = {a + b}")
```

Output:

```text
5 + 3 = 8
```

Before f-strings existed, the same thing was done with `.format()` or the older `%` operator, both of which are still valid and still appear in existing code, but f-strings are now the standard for new code.

```python
print("{} + {} = {}".format(a, b, a + b))   # .format() style, older
print("%d + %d = %d" % (a, b, a + b))         # % style, oldest, closest to C's printf
```

### String Methods

A few very commonly used ones:

```python
text = "  Hello, World!  "

print(text.strip())               # removes leading/trailing whitespace
print(text.strip().split(","))     # splits into a list, at each comma
print("-".join(["a", "b", "c"]))    # joins a list into one string, with "-" between each
print(text.replace("World", "Python"))  # replaces all matches
```

Output:

```text
Hello, World!
['Hello', ' World!']
a-b-c
  Hello, Python!  
```

Simple idea:

```text
str is a real, immutable, built-in type — operations like .upper() return a NEW string, never modify the original.
Slicing ([start:stop]) and f-strings (f"{value}") are Python-specific conveniences with no direct C/C++ equivalent.
```

## Lists, Tuples, Sets, And Dictionaries

C's array is fixed in size, holds only one type at a time (conceptually), and gives you no built-in higher-level structures beyond that and `struct`. Python has several built-in collection types, each suited to a different job, roughly comparable to what C++'s STL containers (`vector`, `pair`, `set`, `map`) provide, but built directly into the language with no `#include` needed at all.

### Lists — Like A Resizable Array

`list` is the closest equivalent to C++'s `std::vector`: ordered, resizable, and able to hold a mix of different types at once (something `std::vector<T>` cannot do, since `T` is fixed).

```python
numbers = [10, 20, 30]

numbers.append(40)         # add to the end
print(numbers)
print(numbers[0])            # indexing, same as an array
print(len(numbers))

numbers.remove(20)            # removes the first matching value
print(numbers)
```

Output:

```text
[10, 20, 30, 40]
10
4
[10, 30, 40]
```

Lists are **mutable** — unlike strings, a list's contents genuinely can be changed in place.

```python
numbers[0] = 999
print(numbers)
```

Output:

```text
[999, 30, 40]
```

### List Comprehensions

A very common, Python-specific way of building a list in one line, based on some other iterable — there is no equivalent syntax construct in C or C++ at all.

```python
squares = [x * x for x in range(1, 6)]
print(squares)
```

Output:

```text
[1, 4, 9, 16, 25]
```

This reads as "for each `x` in `range(1, 6)`, put `x * x` into the new list." A condition can be added too:

```python
even_squares = [x * x for x in range(1, 11) if x % 2 == 0]
print(even_squares)
```

Output:

```text
[4, 16, 36, 64, 100]
```

### Tuples — Like A Fixed, Immutable List

A `tuple` is written with `( )` instead of `[ ]`, and once created, cannot be changed at all — no adding, removing, or reassigning individual elements. It plays a similar role to C++'s `std::pair`, but can hold any number of values, not just two.

```python
person = ("Alice", 30)

print(person[0])
print(person[1])

# person[0] = "Bob"   # ERROR — tuples cannot be modified
```

Output:

```text
Alice
30
```

Tuples are commonly used for values that logically belong together and shouldn't change, and for returning multiple values from a function at once:

```python
def get_min_max(numbers):
    return min(numbers), max(numbers)

low, high = get_min_max([4, 1, 9, 2])
print(low, high)
```

Output:

```text
1 9
```

This last example is also using **tuple unpacking** — `low, high = ...` — another Python-specific convenience letting you assign multiple variables from one tuple in a single line.

### Sets — Unique, Unordered Values

`set`, written with `{ }`, is directly comparable to C++'s `std::set`: it stores only unique values, with no duplicates, though Python's `set` is unordered (no guaranteed sort order, unlike `std::set`, which keeps values sorted).

```python
numbers = {10, 20, 30}
numbers.add(30)   # duplicate, ignored
numbers.add(40)

print(numbers)
```

Output (order may vary):

```text
{40, 10, 20, 30}
```

### Dictionaries — Key-Value Pairs

`dict`, also written with `{ }` but using `key: value` pairs, is directly comparable to C++'s `std::map`: it stores values looked up by a key, rather than by numeric position.

```python
ages = {"Alice": 30, "Bob": 25}

print(ages["Alice"])

ages["Charlie"] = 35   # add a new key
print(ages)

for name, age in ages.items():
    print(name + ": " + str(age))
```

Output:

```text
30
{'Alice': 30, 'Bob': 25, 'Charlie': 35}
Alice: 30
Bob: 25
Charlie: 35
```

Unlike C++'s `std::map`, a plain Python `dict` does not keep its keys sorted — but as of Python 3.7, it does reliably preserve **insertion order** (the order keys were added), which earlier versions of Python did not guarantee at all.

Simple idea:

```text
list   -> resizable, ordered, mutable, mixed types allowed   (like std::vector, but more flexible)
tuple  -> fixed, ordered, immutable                            (like std::pair, but any number of items)
set    -> unique values, unordered                              (like std::set, but not sorted)
dict   -> key-value pairs, insertion-ordered                     (like std::map, but not sorted by key)
```

## Working With Files

Python's file handling is conceptually the same as C's `fopen`/`fclose` or C++'s `fstream`, but built with automatic cleanup baked directly into the language, using the `with` statement.

### Writing To A File

```python
with open("data.txt", "w") as file:
    file.write("Hello, file!\n")
    file.write("42\n")
```

`open("data.txt", "w")` opens the file for writing (creating it if it doesn't exist, or overwriting it if it does — same as C's `"w"` mode). `with ... as file:` is a **context manager**: it guarantees the file is automatically closed when the indented block ends, even if an error happens partway through — there is no equivalent of forgetting to call `fclose()` the way there is in C.

### Reading From A File

```python
with open("data.txt", "r") as file:
    for line in file:
        print(line, end="")
```

A file object is itself directly iterable in Python — looping `for line in file:` reads one line at a time automatically, without needing a separate function call like C's `fgets` inside the loop condition. `end=""` is passed to `print` because each `line` already includes its own trailing `\n` from the file, and `print` would otherwise add a second one.

Other common ways to read:

```python
with open("data.txt", "r") as file:
    content = file.read()        # reads the ENTIRE file as one string

with open("data.txt", "r") as file:
    lines = file.readlines()      # reads the entire file as a LIST of lines
```

### File Modes

```text
"r"   read only, file must exist
"w"   write only, creates file or overwrites existing content
"a"   append, writes are added to the end of the file
"r+"  read and write, file must exist
```

These match C's file modes exactly, since Python's file handling is really a thin, safer wrapper around the same underlying operating system file operations.

Simple idea:

```text
with open(...) as file: automatically closes the file, even if an error happens — no manual fclose() needed.
A file object is directly iterable line by line in a for loop.
```

## Exception Handling

Python's exception handling plays the same role as C++'s `try`/`catch`/`throw`, with almost identical structure, but exceptions are used far more pervasively in normal Python code than they are in typical C++ code — many everyday Python operations (opening a missing file, converting an invalid string to a number, accessing a missing dictionary key) raise an exception as their normal way of signaling failure.

```python
def divide(a, b):
    if b == 0:
        raise ValueError("Division by zero")
    return a / b

try:
    result = divide(10, 0)
    print(result)
except ValueError as e:
    print("Error:", e)
```

Output:

```text
Error: Division by zero
```

```text
raise    -> Python's equivalent of C++'s throw
try      -> wraps code that might raise an exception
except   -> Python's equivalent of catch
```

`ValueError` is one of Python's many built-in exception types, similar to `std::runtime_error` in C++. `as e` names the caught exception object, similar to `catch (const std::runtime_error &e)`.

### Multiple except Blocks

```python
try:
    numbers = [1, 2, 3]
    print(numbers[10])
except IndexError as e:
    print("Index error:", e)
except ValueError as e:
    print("Value error:", e)
except Exception as e:
    print("Some other error:", e)
```

Output:

```text
Index error: list index out of range
```

Checked top to bottom, same as C++'s multiple `catch` blocks. `except Exception as e:` is the closest equivalent to C++'s `catch (...)` — it catches almost anything, since nearly all built-in exception types inherit from `Exception`, and is conventionally placed last as a fallback.

### finally

`finally` runs no matter what happened — whether an exception was raised or not, and whether it was caught or not. There is no direct equivalent keyword in C++, though the same *effect* is often achieved there using destructors (RAII).

```python
try:
    file = open("data.txt", "r")
    content = file.read()
except FileNotFoundError:
    print("File not found")
finally:
    print("Done trying to read the file")
```

### Custom Exceptions

Similar to C++'s pattern of inheriting from `std::exception`, a custom Python exception inherits from `Exception` (or a more specific built-in exception type).

```python
class InsufficientFundsError(Exception):
    pass

def withdraw(balance, amount):
    if amount > balance:
        raise InsufficientFundsError("Not enough funds for this withdrawal")
    return balance - amount

try:
    withdraw(100, 500)
except InsufficientFundsError as e:
    print(e)
```

Output:

```text
Not enough funds for this withdrawal
```

`pass` is a Python keyword meaning "do nothing" — used here because this class needs no extra code of its own; it only needs to exist as a distinct, named exception type.

Simple idea:

```text
raise / try / except map directly onto C++'s throw / try / catch.
finally always runs, whether or not an exception occurred — no direct C++ keyword equivalent.
Custom exceptions inherit from Exception, the same way C++ custom exceptions inherit from std::exception.
```

## Modules And Packages

Python lets you organize code into **modules** and **packages** so that you can reuse functions and keep larger projects manageable.

### 1. What Is A Module?

A **module** is a single Python file (`.py`). It can contain functions, variables, and classes that other Python files can import and use.

For example, create a file named `mymath.py`:

```python
# mymath.py

def add(a, b):
    return a + b

def multiply(a, b):
    return a * b
```

Now create another file named `main.py` in the same directory:

```python
# main.py

import mymath

print(mymath.add(2, 3))
print(mymath.multiply(2, 3))
```

Output:

```text
5
6
```

When Python encounters `import mymath`, it loads the module and executes its top-level statements. Python normally caches an imported module, so it isn't executed afresh every time that module is imported again during the same program run. Its names can then be accessed through the module name, such as `mymath.add()`.

You can also import a particular name directly:

```python
from mymath import add

print(add(2, 3))
```

Here, you call `add()` directly rather than writing `mymath.add()`.

### 2. What Is A Package?

A **package** is a way to organize related modules together in a directory. Instead of keeping every module in one large folder, you can group related files into a package and import them using dotted names.

For a conventional beginner-friendly package, create this structure:

```text
my_project/
├── main.py
└── calculations/
    ├── __init__.py
    ├── addition.py
    └── multiplication.py
```

The `calculations` directory is the package. The files `addition.py` and `multiplication.py` are modules inside it. The `__init__.py` file marks the directory as a regular package and can also expose names that you want users of the package to access conveniently.

Put this in `calculations/addition.py`:

```python
def add(a, b):
    return a + b
```

Put this in `calculations/multiplication.py`:

```python
def multiply(a, b):
    return a * b
```

The package's `__init__.py` can re-export those functions:

```python
# calculations/__init__.py

from .addition import add
from .multiplication import multiply
```

The leading dot means “import from this same package.”

Now `main.py` can use the package:

```python
# main.py

import calculations as calc

print(calc.add(10, 20))
print(calc.multiply(10, 20))
```

Run it from the `my_project` directory:

```bash
python3 main.py
```

Output:

```text
30
200
```

Because `__init__.py` imports `add` and `multiply`, they are available as `calc.add()` and `calc.multiply()` when you import the package.

You can also import directly from a module within the package:

```python
from calculations.addition import add

print(add(10, 20))
```

### 3. Module Vs Package

| Module | Package |
|---|---|
| A single Python file, such as `addition.py`. | A directory that groups related modules, such as `calculations/`. |
| Holds code such as functions, classes, and variables. | Helps organize multiple modules into a meaningful structure. |
| Example import: `import mymath` | Example import: `import calculations.addition` |

**In short:** a module is a file; a package organizes modules into a directory structure. A package can contain modules and, where needed, subpackages.

### 4. The `if __name__ == "__main__":` Pattern

Python sets a special variable named `__name__` for each module:

- When you run a file directly, such as `python3 mymath.py`, Python sets `__name__` to `"__main__"`.
- When the file is imported, `__name__` is set to its module name (for example, `"mymath"`).

This makes it possible to keep a module reusable while also giving it a small test or demo that runs only when the file is executed directly.

For example, update `mymath.py`:

```python
# mymath.py

def add(a, b):
    return a + b

if __name__ == "__main__":
    print("Testing:", add(2, 3))
```

Run the file directly:

```bash
python3 mymath.py
```

Output:

```text
Testing: 5
```

But if `main.py` contains:

```python
import mymath

print(mymath.add(10, 20))
```

and you run `python3 main.py`, the test line inside `mymath.py` does not run. The `add()` function is still available to use.

This pattern is useful for quick demonstrations, manual tests, or command-line behavior that should not happen just because another file imports the module.

## Object-Oriented Programming In Python

Python fully supports OOP, and the core ideas map directly onto what's already covered in the C++ readme: classes, objects, encapsulation, inheritance, and polymorphism. The syntax and a few defaults differ, but the concepts are identical, so this section focuses mainly on those differences rather than re-explaining OOP from scratch.

```python
class Account:
    def __init__(self, starting_balance):
        self.balance = starting_balance

    def deposit(self, amount):
        self.balance += amount

    def withdraw(self, amount):
        if amount > self.balance:
            print("Insufficient funds")
            return
        self.balance -= amount

david = Account(1000)
david.deposit(500)
david.withdraw(200)

print(david.balance)
```

Output:

```text
1300
```

```text
class Account:              -> same idea as C++'s class Account { ... }
def __init__(self, ...):    -> the constructor — always named __init__, never the class name itself
self                          -> Python's explicit, always-written equivalent of C++'s hidden `this` pointer
self.balance                  -> a member variable, attached to this specific object
```

`self` is the biggest visible difference from C++. In C++, `this` is available automatically and invisibly inside every member function. In Python, the equivalent — conventionally named `self`, though technically just the first parameter and could be called anything — must be explicitly listed as the first parameter of every method, and explicitly used (`self.balance`, not just `balance`) to refer to the object's own data. There is no hiding it the way C++ hides `this`.

Python classes have no `public`/`private`/`protected` access specifiers at all, unlike C++. By convention only (not enforced by the language), a name starting with a single underscore (`_balance`) signals "treat this as internal, please don't touch it from outside," and a double underscore (`__balance`) triggers a mild form of name-mangling that makes accidental outside access harder, but nothing in Python truly prevents access to any attribute the way C++'s `private` does at compile time.

Inheritance looks like this:

```python
class Character:
    def __init__(self, name, health):
        self.name = name
        self.health = health

    def attack(self):
        print(self.name + " attacks!")

class Wizard(Character):
    def __init__(self, name, health, mana):
        super().__init__(name, health)   # calls the base class's __init__
        self.mana = mana

    def cast_spell(self):
        print(self.name + " casts a spell! Mana left: " + str(self.mana))

gandalf = Wizard("Gandalf", 100, 50)
gandalf.attack()
gandalf.cast_spell()
```

Output:

```text
Gandalf attacks!
Gandalf casts a spell! Mana left: 50
```

`class Wizard(Character):` is Python's equivalent of C++'s `class Wizard : public Character`. `super().__init__(...)` calls the base class's constructor, equivalent to C++'s `Character(n, h)` in the initializer list.

Every method in Python is effectively `virtual` by default — polymorphism (a `Wizard` used through code that only knows about `Character` still running `Wizard`'s own overridden methods) simply happens automatically, with no `virtual` keyword needed at all, since Python always resolves which method to call based on the object's actual type at run time.

Simple idea:

```text
self is Python's explicit version of C++'s hidden `this` — always written, always the first parameter.
__init__ is the constructor; there is no separate destructor typically written or needed (garbage collection handles cleanup).
There are no enforced access specifiers; privacy is convention (a leading underscore), not language-enforced.
Every method behaves as if virtual, by default — no keyword needed for polymorphism.
```

## pip — Python's Package Manager

Everything covered so far — `print`, `math`, `input`, file handling — is either a built-in language feature or part of Python's **standard library**, the large set of modules that ship with every Python installation automatically, no extra step needed. But the standard library, however large, cannot possibly contain every tool every programmer will ever need. `pip` is how you get everything else.

### Where pip Came From

Before `pip`, Python's original packaging tool was `easy_install`, part of a project called `setuptools`. It worked, but had real limitations — most notably, it had no clean way to *uninstall* a package properly, and its handling of dependency versions was weak.

`pip` was created in 2008 by Ian Bicking, specifically to fix these problems. The name is a recursive acronym: **"Pip Installs Packages"** (or, in an earlier joking form, "Pip Installs Python" — recursive acronyms like this are a long-running tradition in software, GNU itself standing for "GNU's Not Unix" being the most famous example). `pip` gained proper uninstall support, better dependency resolution, and the ability to install directly from source repositories, not just pre-built packages.

`pip` became so central to how Python is used that, since Python 3.4, it is bundled and installed automatically with Python itself — you no longer need to install `pip` separately on a fresh Python install, the way you once did.

### PyPI — The Python Package Index

`pip` needs somewhere to actually download packages *from*. That place is **PyPI**, the **Python Package Index**, a massive, public, free repository of Python packages that anyone can upload to. (PyPI is pronounced "pie-pee-eye," and is a completely separate thing from PyPy, the alternative interpreter mentioned earlier — an unfortunate, frequently confused naming clash.)

When you run a `pip` command, by default it is reaching out over the internet to PyPI's servers, searching for the package you asked for, and downloading it.

```text
pip     -> the tool that installs packages
PyPI     -> the online repository pip downloads packages FROM, by default
```

### How pip Actually Works, Step By Step

```bash
pip install requests
```

Here's what actually happens, in order, when this command runs:

```text
1. pip contacts PyPI (pypi.org) and looks up a package named "requests"
2. PyPI returns metadata: available versions, and what OTHER packages "requests" itself depends on
3. pip performs dependency resolution — figuring out compatible versions of everything needed,
   including "requests" itself and every package IT depends on, and every package THOSE depend on, and so on
4. pip downloads the appropriate files — usually a "wheel" (a pre-built package, discussed below)
5. pip extracts and copies the package's files into your Python installation's site-packages directory
6. the package becomes available to "import" in any Python program from that point onward
```

```python
import requests

response = requests.get("https://example.com")
print(response.status_code)
```

Once installed, using it is no different from using any built-in module — `import requests` works exactly like `import math`, because as far as Python's `import` system is concerned, there is no real distinction between "built-in" and "installed via pip" — both are just modules sitting somewhere Python knows to look.

### Wheels vs Source Distributions

When `pip` downloads a package, it usually gets one of two kinds of files:

```text
.whl (a "wheel")       -> a pre-built, ready-to-use package — just needs copying into place, fast to install
.tar.gz (source dist)   -> the raw source code of the package — sometimes needs to be COMPILED locally during install
```

Many popular Python packages (like `numpy`, covered next) are not pure Python underneath — parts of them are actually written in C, for speed, and need to be compiled into machine code to be usable at all. A wheel already contains that compiled code, pre-built for your specific operating system and Python version, so installing it is just a fast file copy. Without a matching pre-built wheel available, `pip` has to fall back to downloading the raw source and compiling it locally during installation, which is slower and requires a working C compiler to be present on your machine — this is why, occasionally, installing a package fails with a compiler-related error if your system is missing the right build tools.

### Where Installed Packages Actually Go

Packages installed by `pip` are copied into a specific folder Python already knows to search when you write `import something`, commonly named `site-packages`, living somewhere inside your Python installation. This is the same conceptual idea as C's `#include <stdio.h>` finding `stdio.h` in a standard system location, or C++ linking against `libc.so.6` in a standard system library path — Python's `import` system is simply looking in its own equivalent of those standard locations, `site-packages` being the main one for third-party packages.

### Virtual Environments

A very important companion concept to `pip`, worth knowing even briefly: different projects on the same machine often need *different, conflicting* versions of the same package. Installing everything globally, system-wide, causes real problems once you have more than one Python project on your machine.

```bash
python3 -m venv myenv        # create a new, isolated virtual environment
source myenv/bin/activate     # activate it (Linux/macOS)
pip install requests           # installs INTO this isolated environment only, not globally
```

A **virtual environment** is an isolated copy of Python's package folder, specific to one project, so that `pip install`-ing something for one project never affects, breaks, or conflicts with any other project on the same machine. This is standard, expected practice for any real Python project, not just an edge case.

### requirements.txt

Real projects also commonly list their exact dependencies in a plain text file, so anyone else (or a server deploying the project later) can install the exact same set of packages in one command.

```text
requests==2.31.0
numpy==1.26.0
pandas==2.1.0
```

```bash
pip install -r requirements.txt
```

`-r requirements.txt` tells `pip` to read this file and install every listed package, at the exact version specified, rather than typing out each `pip install` command individually.

or first install package using `pip install <package name>` and then do `pip freeze > requirements.txt` to take note of exact package and its version number used in your programe to replicate it later using `pip install -r requirements.txt`.

Simple idea:

```text
pip = the tool. PyPI = the online repository pip downloads packages from, by default.
Installing a package with pip is really: look it up on PyPI, resolve dependencies, download, copy into site-packages.
Once installed, "import" treats it identically to any built-in module.
Virtual environments keep each project's installed packages isolated from every other project.
```

## Common Everyday Libraries

These are packages installed via `pip` (except where noted as part of the standard library) that come up constantly in real, everyday Python work — well beyond just data science, though that's where several of them are most associated.

### NumPy — Numerical Computing

```bash
pip install numpy
```

NumPy ("Numerical Python") provides a fast array type, `ndarray`, and the mathematical operations to go with it. A plain Python `list` is flexible but slow for heavy numerical work, because of all the overhead of Python's dynamic typing on every single element. NumPy's arrays are implemented internally in C, store data in one tightly packed, uniform block of memory (much closer to how a C array actually works), and perform operations on entire arrays at once, without needing a Python-level loop at all.

```python
import numpy as np

a = np.array([1, 2, 3])
b = np.array([4, 5, 6])

print(a + b)
```

Output:

```text
[5 7 9]
```

`import numpy as np` is an extremely common convention — `as np` gives the module a shorter alias, so `np.array(...)` is written instead of the longer `numpy.array(...)` everywhere. Notice `a + b` adds the arrays element-wise directly — this is operator overloading, the same underlying concept covered in the C++ readme, just implemented for NumPy's array type instead of a class you'd write yourself.

### pandas — Data Analysis And Tables

```bash
pip install pandas
```

pandas provides a `DataFrame`, a table-like structure with labeled rows and columns, similar in spirit to a spreadsheet or a SQL table, built on top of NumPy underneath.

```python
import pandas as pd

data = {"name": ["Alice", "Bob"], "age": [30, 25]}
df = pd.DataFrame(data)

print(df)
```

Output:

```text
    name  age
0  Alice   30
1    Bob   25
```

pandas is the standard tool for loading, cleaning, filtering, and analyzing tabular data in Python — reading a CSV or Excel file into a `DataFrame`, filtering rows, computing statistics, and writing the result back out, is an extremely common everyday task built almost entirely around this one library.

### Matplotlib — Plotting And Charts

```bash
pip install matplotlib
```

Matplotlib is the most widely used library for creating charts and graphs — line charts, bar charts, scatter plots, and more.

```python
import matplotlib.pyplot as plt

x = [1, 2, 3, 4]
y = [10, 20, 25, 30]

plt.plot(x, y)
plt.xlabel("X Axis")
plt.ylabel("Y Axis")
plt.title("Simple Line Chart")
plt.show()
```

`plt.show()` opens a window (or, in tools like Jupyter notebooks, displays the chart inline) showing the resulting plot. Many other, more specialized plotting libraries (Seaborn, Plotly) are themselves built on top of Matplotlib.

### requests — Making Web Requests

```bash
pip install requests
```

`requests` is the standard, widely used library for making HTTP requests — fetching a web page, calling a web API, downloading data from the internet — from inside a Python program.

```python
import requests

response = requests.get("https://api.github.com")
print(response.status_code)
print(response.json())
```

Python does technically have a built-in module for this too (`urllib`, part of the standard library), but `requests` is dramatically simpler to use, and is one of the most-downloaded packages on all of PyPI as a direct result.

### Flask And Django — Web Development

```bash
pip install flask
pip install django
```

Both are frameworks for building web applications and APIs in Python. Flask is intentionally small and minimal, giving you just the basics and letting you add pieces as needed. Django is a much larger, full-featured framework, including things like a built-in admin panel and database tools out of the box. FastAPI, a newer alternative, has also become extremely popular, especially for building APIs, partly because it uses Python's type hints (mentioned earlier) to automatically validate data and generate documentation.

### pytest — Testing

```bash
pip install pytest
```

`pytest` is the most widely used framework for writing and running automated tests in Python.

```python
def add(a, b):
    return a + b

def test_add():
    assert add(2, 3) == 5
```

`assert` is a built-in Python keyword (also present, differently, in C's `assert.h`) that raises an error if the given condition is false. `pytest` automatically finds functions starting with `test_`, runs them, and reports which passed and which failed.

### scikit-learn, TensorFlow, And PyTorch — Machine Learning

```bash
pip install scikit-learn
pip install tensorflow
pip install torch
```

scikit-learn provides ready-made implementations of classic machine learning algorithms (classification, regression, clustering), suitable for smaller, more traditional machine learning tasks. TensorFlow (created by Google) and PyTorch (created by Meta) are the two dominant libraries for deep learning — building and training neural networks — and are the foundation underneath most modern AI systems, including large language models. All three lean heavily on NumPy-style array operations underneath.

### datetime — Working With Dates And Times (Standard Library)

Part of the standard library already, needing no `pip install` at all — included here because it's used constantly in everyday programs.

```python
from datetime import datetime

now = datetime.now()
print(now)
print(now.year, now.month, now.day)
```

Simple idea:

```text
NumPy       -> fast numerical arrays, the foundation almost everything else below is built on
pandas       -> tables/spreadsheets in code, built on NumPy
Matplotlib    -> charts and graphs
requests       -> talking to the web / APIs
Flask/Django    -> building web applications and APIs
pytest           -> automated testing
scikit-learn/TensorFlow/PyTorch -> machine learning and deep learning
```

## Errors

Python errors generally fall into the same broad categories as C's — problems caught before running, and problems that only show up while the program is actually running — but because Python has no separate compile step you invoke ahead of time, the categories look a little different in practice.

### Syntax Errors

These are Python's equivalent of C's compile-time errors — the interpreter cannot even begin running the program, because what you wrote isn't valid Python at all. These are caught the moment CPython tries to compile the file to bytecode, before a single line actually executes.

**Missing colon**

```python
if age >= 18
    print("Adult")
```
```text
SyntaxError: expected ':'
```

**Inconsistent indentation**

```python
def greet():
    print("Hello")
        print("World")
```
```text
IndentationError: unexpected indent
```

**Mismatched parentheses/quotes**

```python
print("Hello
```
```text
SyntaxError: unterminated string literal
```

Simple idea:

```text
Syntax errors mean Python could not even understand the structure of your code.
Nothing runs at all, the same as a C compile-time error.
```

### Run-Time Errors (Exceptions)

These happen while the program is actually executing — the code was valid Python, the interpreter started running it, and then something went wrong partway through, similar to C's run-time errors like segmentation faults, except Python's version comes with a clear, named exception and a readable message, rather than a raw crash.

**NameError — using something that doesn't exist**

```python
print(age)
```
```text
NameError: name 'age' is not defined
```

**TypeError — mismatched types used together**

```python
result = "5" + 5
```
```text
TypeError: can only concatenate str (not "int") to str
```

**ValueError — right type, invalid value**

```python
number = int("hello")
```
```text
ValueError: invalid literal for int() with base 10: 'hello'
```

**ZeroDivisionError**

```python
result = 10 / 0
```
```text
ZeroDivisionError: division by zero
```

Unlike C, where integer division by zero crashes the whole program outright (`Floating point exception (core dumped)`) with no clean way to recover mid-program, Python raises a catchable exception here — the same `try`/`except` mechanism from [Exception Handling](#exception-handling) can catch this and let the program continue normally.

**IndexError — accessing outside a list's bounds**

```python
numbers = [1, 2, 3]
print(numbers[10])
```
```text
IndexError: list index out of range
```

Unlike C, which happily lets you read or write past the end of an array (silently corrupting memory, as covered in the C readme), Python always checks bounds and raises a clear, catchable error instead of allowing undefined behavior.

**KeyError — accessing a missing dictionary key**

```python
ages = {"Alice": 30}
print(ages["Bob"])
```
```text
KeyError: 'Bob'
```

**AttributeError — calling something that doesn't exist on an object**

```python
name = "Alice"
name.push("!")
```
```text
AttributeError: 'str' object has no attribute 'push'
```

**FileNotFoundError**

```python
with open("missing.txt", "r") as file:
    content = file.read()
```
```text
FileNotFoundError: [Errno 2] No such file or directory: 'missing.txt'
```

Simple idea:

```text
Python turns most of what would be silent memory corruption or a hard crash in C
into a specific, named, catchable exception instead.
```

### No Compiler Also Means No Linker Errors

Because Python has no separate compilation or linking stage of its own (as covered in [How A Python Program Actually Runs](#how-a-python-program-actually-runs)), there is no real equivalent of C's linker errors (`undefined reference to ...`). The closest equivalent is an `ImportError` or `ModuleNotFoundError`, raised at run time, the moment an `import` statement actually tries and fails to locate a module:

```python
import some_module_that_does_not_exist
```
```text
ModuleNotFoundError: No module named 'some_module_that_does_not_exist'
```

This is usually either a typo, or a `pip install` that was never run for a third-party package.

### Logical Errors

Exactly the same concept as in C: the program runs completely fine, produces no error message at all, and simply gives the wrong answer, because the logic itself is flawed.

```python
def add(a, b):
    return a - b   # wrong operator, but perfectly valid Python
```

This never raises any exception. It just quietly returns the wrong result, every time.

Simple idea:

```text
Syntax errors  -> caught before the program starts, like C's compile-time errors.
Exceptions      -> happen while running, but are named, catchable, and safer than most of C's run-time crashes.
Logical errors   -> the program runs fine and gives no error, but is simply wrong. Same as C, and just as hard to catch.
```