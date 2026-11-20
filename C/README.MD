# C++

C++ is a general-purpose compiled programming language built directly on top of C. It keeps everything C offers — raw speed, direct memory control, closeness to hardware — and layers a large set of tools on top: safer I/O, references, function overloading, generics via templates, exception handling, a rich standard library of ready-made data structures and algorithms, and Object-Oriented Programming (OOP).

**Why was C++ created?**
C is powerful, but as programs grow large, keeping related data and the functions that operate on it organized together becomes hard. Bjarne Stroustrup wanted a language that kept C's speed and closeness to hardware, but also let programmers build bigger, more organized, more reusable systems — without throwing away everything C already had. Almost all valid C code is also valid C++, so the transition was natural.

**Where is C++ used?**
C++ is used where speed and control still matter, but the software is large or complex enough to need more structure than plain C provides.

- Game engines and game development (Unreal Engine)
- Operating system components and device drivers
- Browsers — large parts of Chrome and Firefox are C++
- Embedded systems and firmware
- High-frequency trading and financial systems
- Compilers and language runtimes (Clang, LLVM)
- Graphics, physics, and rendering engines
- Large desktop applications (Adobe Creative Suite, Microsoft Office)

**Why is C++ still relevant?**
Garbage-collected languages (Python, Java, Go) are easier to write but add runtime overhead that is unacceptable in performance-critical software. C++ gives you manual control over every byte of memory and every CPU cycle, plus modern abstractions on top. No other widely-used language matches that combination.

Simple idea:

```
C++ = C + extra tools for safer, more reusable code + OOP
```

The C readme is a direct prerequisite. This document only covers what changes or gets added.

---

## Index

- [History](#history)
- [A Basic C++ Program](#a-basic-c-program)
- [How C++ Code Becomes A Program](#how-c-code-becomes-a-program)
- [What C++ Adds On Top Of C](#what-c-adds-on-top-of-c)
- [The std Namespace And Standard I/O](#the-std-namespace-and-standard-io)
  - [Namespaces](#namespaces)
  - [std::cout And std::cin](#stdcout-and-stdcin)
  - [The bool Type](#the-bool-type)
  - [std::string](#stdstring)
  - [std::cerr](#stdcerr)
  - [std::stringstream](#stdstringstream)
- [Memory And Variables](#memory-and-variables)
  - [References](#references)
  - [nullptr](#nullptr)
  - [new And delete](#new-and-delete)
  - [auto And Type Inference](#auto-and-type-inference)
  - [const References](#const-references)
- [Control Flow Upgrades](#control-flow-upgrades)
  - [Range-Based for Loops](#range-based-for-loops)
- [Functions](#functions)
  - [Default Arguments](#default-arguments)
  - [Inline Functions](#inline-functions)
  - [Function Templates](#function-templates)
- [The Standard Template Library (STL)](#the-standard-template-library-stl)
  - [std::vector](#stdvector)
  - [std::array](#stdarray)
  - [std::pair](#stdpair)
  - [std::map](#stdmap)
  - [std::set](#stdset)
  - [std::stack And std::queue](#stdstack-and-stdqueue)
  - [STL Algorithms](#stl-algorithms)
  - [Class Templates](#class-templates)
  - [Common Headers](#common-headers)
- [File Handling With fstream](#file-handling-with-fstream)
- [Exception Handling](#exception-handling)
- [Object-Oriented Programming (OOP)](#object-oriented-programming-oop)
  - [The Core Idea](#the-core-idea)
  - [Classes And Objects](#classes-and-objects)
  - [Member Functions](#member-functions)
  - [Encapsulation](#encapsulation)
    - [Access Specifiers](#access-specifiers)
    - [Getters And Setters](#getters-and-setters)
  - [Constructors](#constructors)
  - [Destructors](#destructors)
  - [The this Pointer](#the-this-pointer)
  - [Copy Constructor](#copy-constructor)
  - [Static Members](#static-members)
  - [Friend Functions](#friend-functions)
  - [Inheritance](#inheritance)
    - [Base And Derived Classes](#base-and-derived-classes)
    - [Multiple Inheritance](#multiple-inheritance)
    - [The final Keyword](#the-final-keyword)
  - [Polymorphism](#polymorphism)
    - [Compile-Time Polymorphism](#compile-time-polymorphism)
      - [Function Overloading](#function-overloading)
      - [Operator Overloading](#operator-overloading)
    - [Run-Time Polymorphism](#run-time-polymorphism)
      - [Virtual Functions And Overriding](#virtual-functions-and-overriding)
      - [Abstract Classes And Pure Virtual Functions](#abstract-classes-and-pure-virtual-functions)
- [Errors](#errors)

---

## History

C++ was created by Bjarne Stroustrup in the early 1980s at Bell Labs — the same place C was born a decade earlier. Stroustrup was working in C but wanted a language that also supported grouping data and the functions that work on it together, an idea called classes, which he had seen in a language called Simula. His first version was called "C with Classes."

The name was later changed to C++. The `++` is a small joke borrowed from C's own increment operator — it means "one step beyond C."

---

## A Basic C++ Program

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

Line by line:

**`#include <iostream>`**
Includes the input/output stream library. This is C++'s replacement for `<stdio.h>` in most cases. Without it, `std::cout` does not exist. It is a preprocessor directive, same as in C.

**`int main()`**
The entry point of every C++ program, identical to C. Empty parentheses in C++ means no arguments — equivalent to `main(void)` in C.

**`std::cout << "Hello, World!"`**
Prints to the terminal. `std::cout` is a pre-made object (not a function) that represents standard output. `<<` is an operator that means "send this into the stream." Both `std` and `cout` and `<<` are explained in full in the [std Namespace](#the-std-namespace-and-standard-io) section.

**`<< std::endl`**
Chained onto the same line. `std::endl` inserts a newline and flushes the output buffer. `\n` also works and is slightly faster when you do not need to force a flush.

**`return 0`**
Tells the OS the program ended successfully. Same as in C.

### Compiling And Running

Use `g++` instead of `gcc` for C++ programs:

```bash
g++ hello.cpp -o hello
./hello
```

`g++` understands C++ syntax and automatically links the C++ standard library. `gcc` does not do this by default. For modern C++:

```bash
g++ -std=c++17 -Wall hello.cpp -o hello
```

| Flag | What it does |
|---|---|
| `-std=c++17` | Use the C++17 standard (recommended for modern code) |
| `-Wall` | Enable all common warnings |
| `-Wextra` | Enable extra warnings |
| `-g` | Include debug info (for use with `gdb`) |
| `-O2` | Optimize the output binary |

---

## How C++ Code Becomes A Program

The exact same stages as C apply — refer to the C readme for the full explanation of each one:

```
Preprocessing → Compilation → Assembly → Linking → Executable
```

The only differences in C++:

**Use `g++` instead of `gcc`**
`g++` understands C++-specific syntax (templates, classes, `std::cout`) and auto-links the C++ standard library.

**Name Mangling**
In C, a function's compiled name in the object file roughly matches its source name. In C++, because of function overloading, two functions can share the same name — for example `add(int, int)` and `add(double, double)`. The compiler encodes the parameter types into the internal name to keep them distinct. This is called name mangling and is handled entirely automatically. It is only relevant if you inspect object files directly (with `objdump`) or when linking C++ code with C code.

---

## What C++ Adds On Top Of C

Everything from the C readme still applies in C++ without any changes: variables, `if`/`else`, loops, functions, pointers, arrays, `struct`, `malloc`/`free`, file handling, preprocessor directives, stack vs heap, memory leaks, segfaults — all of it. Refer to the C readme for those.

C++ adds the following on top:

| Feature | Short description | Covered in |
|---|---|---|
| Namespaces | Named containers for groups of names, preventing collisions | [std Namespace](#the-std-namespace-and-standard-io) |
| `std::cout` / `std::cin` | Object-based I/O, replacing `printf`/`scanf` | [std Namespace](#the-std-namespace-and-standard-io) |
| `bool` type | A native `true`/`false` type, no header needed | [std Namespace](#the-std-namespace-and-standard-io) |
| `std::string` | Built-in resizeable string with operators like `+` and `==` | [std Namespace](#the-std-namespace-and-standard-io) |
| References (`&`) | Safer alternative to pointers in many common situations | [Memory And Variables](#memory-and-variables) |
| `nullptr` | A proper null pointer constant, replacing `NULL` | [Memory And Variables](#memory-and-variables) |
| `new` / `delete` | Type-safe replacements for `malloc`/`free` | [Memory And Variables](#memory-and-variables) |
| `auto` | Compiler infers the type from the assigned value | [Memory And Variables](#memory-and-variables) |
| `const` references | Pass data efficiently without allowing modification | [Memory And Variables](#memory-and-variables) |
| Range-based `for` | Loop over every element of a container without an index | [Control Flow Upgrades](#control-flow-upgrades) |
| Default arguments | Parameters with fallback values when caller omits them | [Functions](#functions) |
| Inline functions | Hint to expand a function at the call site | [Functions](#functions) |
| Function templates | Write one function that works with any type | [Functions](#functions) |
| STL containers | `vector`, `array`, `map`, `set`, `stack`, `queue` | [STL](#the-standard-template-library-stl) |
| STL algorithms | `sort`, `find`, `reverse`, `max_element` | [STL](#the-standard-template-library-stl) |
| Class templates | Write one class that works with any type | [STL](#the-standard-template-library-stl) |
| `fstream` | Object-based file I/O | [File Handling](#file-handling-with-fstream) |
| Exception handling | Structured error handling with `try`/`catch`/`throw` | [Exception Handling](#exception-handling) |
| OOP | Classes, encapsulation, inheritance, polymorphism, operator overloading | [OOP](#object-oriented-programming-oop) |

---

## The std Namespace And Standard I/O

### Namespaces

A namespace is a named container for a group of names — functions, variables, types — used to prevent naming collisions between different libraries or parts of a program.

Two different libraries might both define something called `add` or `Timer`. Without namespaces, the compiler would not know which one is meant. A namespace wraps a group of names so they can be referred to by a prefix.

```cpp
std::cout << "Hello" << std::endl;
```

Here, `cout` and `endl` both live inside the `std` namespace. `std::cout` means "the `cout` that lives inside `std`." The `::` between them is the **scope resolution operator** — it means "look inside this namespace (or class) for the name that follows."

`std` is not built by one header. Many headers each add pieces into the same shared namespace: `<iostream>` adds `cout`/`cin`, `<string>` adds `string`, `<vector>` adds `vector`, and so on.

**Defining your own namespace:**

```cpp
namespace MathUtils {
    int add(int a, int b) {
        return a + b;
    }
}

int main() {
    std::cout << MathUtils::add(3, 4) << std::endl;   // 7
    return 0;
}
```

**`using namespace`**

Typing `std::` everywhere gets repetitive. You can bring an entire namespace into scope:

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello" << endl;   // no std:: needed
    return 0;
}
```

This works, but defeats part of the purpose of namespaces — it brings every name from `std` into the current scope, increasing the chance of collisions. Many style guides recommend writing `std::` explicitly in larger programs, or bringing in only specific names:

```cpp
using std::cout;
using std::endl;
```

---

### std::cout And std::cin

`std::cout` is not a function. It is a pre-made **object** of the class `std::ostream` ("output stream"), available the moment `<iostream>` is included. It represents the standard output — the terminal.

`std::cin` is a similarly pre-made object of class `std::istream` ("input stream"), representing standard input — the keyboard.

**The `<<` and `>>` operators**

`<<` is normally C's left-shift bitwise operator on integers. When the left side is a stream object like `cout`, C++ uses a completely different function — one that knows how to print. This is called operator overloading (covered in full in the OOP section).

Because each overloaded `<<` returns the same stream it just wrote into, the result of `cout << "Hello"` is `cout` itself — which allows chaining:

```cpp
std::cout << "Age: " << 25 << std::endl;
// same as: ((std::cout << "Age: ") << 25) << std::endl
```

`std::cin` works in reverse with `>>`:

```cpp
#include <iostream>

int main() {
    int age;
    std::cout << "Enter your age: ";
    std::cin >> age;   // no &age needed — handled internally via references
    std::cout << "You are " << age << " years old" << std::endl;
    return 0;
}
```

No `&age` here, unlike `scanf(&age)` in C. The stream handles writing into the variable's memory internally using references (covered in the [References](#references) section).

**`std::endl` vs `\n`**

`std::endl` inserts a newline and also **flushes** the output buffer — forces buffered output to be written out immediately. `\n` just inserts a newline without flushing. For most programs the difference is invisible, but `\n` is slightly faster when flushing is not needed:

```cpp
std::cout << "Line one\n";           // faster, no flush
std::cout << "Line two" << std::endl; // newline + flush
```

---

### The bool Type

C has no native boolean type. Comparisons produce plain integers (`0` or `1`), and C99 bolted on `_Bool` (usable as `bool` only after including `<stdbool.h>`). C++ adds a dedicated, native `bool` type — no header required.

```cpp
bool isAdult = true;
bool isMinor = false;
```

`true` and `false` are built-in keywords. Internally `true` behaves like `1` and `false` like `0`, so it can be printed or used in arithmetic like an integer. But using `bool` for yes/no values makes code much clearer than a plain `int`.

```cpp
#include <iostream>

int main() {
    int age = 20;
    bool isAdult = (age >= 18);
    std::cout << isAdult << std::endl;   // prints 1
    return 0;
}
```

To print `true`/`false` as text instead of `1`/`0`:

```cpp
std::cout << std::boolalpha << true << std::endl;   // prints: true
```

---

### std::string

C has no built-in string type — only char arrays ending in `\0`. C++ provides `std::string` from `<string>`, which manages its own memory and can grow or shrink automatically.

```cpp
#include <iostream>
#include <string>

int main() {
    std::string name = "Alice";
    std::cout << name << std::endl;
    return 0;
}
```

Unlike a C char array, `std::string` does not need a fixed size declared upfront and does not require a manually tracked `\0` terminator (though one still exists internally).

**Common operations:**

```cpp
std::string a = "Hello";
std::string b = "World";

std::string combined = a + " " + b;          // concatenation with +
std::cout << combined.length() << std::endl; // 11
std::cout << combined.substr(0, 5) << std::endl; // Hello
std::cout << (a == "Hello") << std::endl;    // 1 (true)

if (combined.find("World") != std::string::npos) {
    std::cout << "found" << std::endl;
}
```

`+` and `==` working directly on strings is operator overloading — `std::string` defines its own versions of these operators. `std::string::npos` is a special value meaning "not found," returned by `find()` when there is no match.

**Reading input:**

```cpp
std::string word;
std::cin >> word;                    // reads one word (stops at whitespace)

std::string line;
std::getline(std::cin, line);        // reads a full line including spaces
```

**Useful methods:**

| Method | What it does |
|---|---|
| `.length()` / `.size()` | Number of characters |
| `.empty()` | True if the string has no characters |
| `.substr(pos, len)` | Extract a substring |
| `.find(str)` | Returns index of first match, or `npos` if not found |
| `.at(index)` | Access character with bounds checking |
| `.c_str()` | Returns a C-style `const char*` (for use with C APIs) |
| `.append(str)` | Append to the end (same as `+=`) |
| `.erase(pos, len)` | Remove characters |
| `.replace(pos, len, str)` | Replace characters |

---

### std::cerr

Works exactly like `std::cout` but writes to **standard error** instead of standard output. It is unbuffered — always flushes immediately. Use it for error messages so they do not get mixed into program output when stdout is redirected to a file:

```cpp
std::cerr << "Error: file not found" << std::endl;
```

---

### std::stringstream

From `<sstream>`. Lets you build a string from mixed types, or parse a string into typed values, using the same `<<`/`>>` stream syntax:

```cpp
#include <sstream>
#include <string>
#include <iostream>

int main() {
    // Building a string from mixed types
    std::stringstream ss;
    ss << "Age: " << 25 << ", Score: " << 98.5;
    std::string result = ss.str();
    std::cout << result << std::endl;   // Age: 25, Score: 98.5

    // Parsing a string into typed values
    std::string data = "42 3.14 hello";
    std::stringstream parser(data);
    int i; double d; std::string s;
    parser >> i >> d >> s;
    std::cout << i << " " << d << " " << s << std::endl;   // 42 3.14 hello

    return 0;
}
```

---

## Memory And Variables

### References

A reference is an alias — another name — for an existing variable. It is not a copy, and not a pointer.

```cpp
int a = 10;
int &ref = a;   // ref is another name for a

ref = 20;
std::cout << a << std::endl;   // 20 — a was changed through ref
```

`ref` and `a` refer to the exact same memory location. Changing one changes the other.

**References in functions**

Recall from C that modifying a variable inside a function required passing a pointer (`int *x`, then `*x = 20`). C++ allows the same result with a reference — no `&` at the call site, no `*` inside the function:

```cpp
#include <iostream>

void change(int &x) {
    x = 20;
}

int main() {
    int a = 10;
    change(a);
    std::cout << a << std::endl;   // 20
    return 0;
}
```

**References vs pointers:**

| | Pointer | Reference |
|---|---|---|
| Can be reassigned | Yes | No — permanently tied to what it was initialized with |
| Can be null | Yes (`nullptr`) | No — must always refer to something valid |
| Syntax at use | Needs `*` to dereference | Used exactly like a normal variable |

Use a reference when you need a function to work with the real variable, with no risk of null or reassignment. Use a pointer when you need nullability, reassignability, or pointer arithmetic.

---

### nullptr

In C, a pointer pointing to nothing is set to `NULL`, which is really just `0`. This can cause ambiguity when combined with function overloading — the compiler cannot always tell whether `0` is the integer zero or a null pointer.

C++ introduces `nullptr`, a dedicated keyword that means "a pointer to nothing" and nothing else:

```cpp
int *p = nullptr;

if (p == nullptr) {
    // p does not point to anything valid
}
```

`nullptr` is not the same as the integer `0`, even though it evaluates to false in a boolean check. Always use `nullptr` in C++ instead of `NULL` or `0` for null pointers.

---

### new And delete

C++ provides its own operators for dynamic memory — `new` and `delete` — as type-safe replacements for `malloc`/`free`.

```cpp
int *p = new int;       // allocate one int on the heap
*p = 10;
delete p;               // free it

int *p2 = new int(10);  // allocate and initialize in one step
delete p2;
```

No manual `sizeof`, no cast needed — `new` already knows the type and returns the correct pointer type.

**For arrays:**

```cpp
int *arr = new int[5];
arr[0] = 10;
delete[] arr;   // must use delete[], not plain delete
```

`new[]` must always be matched with `delete[]`. Mixing them is undefined behavior.

| | `new` / `delete` | `malloc` / `free` |
|---|---|---|
| Return type | Correctly typed pointer | `void*`, needs cast |
| Initialization | Can initialize immediately | Leaves memory uninitialized |
| On failure | Throws an exception | Returns `NULL` |
| Calls constructor/destructor | Yes (with objects) | No |

Memory from `new` must be released with `delete`. Memory from `malloc` must be released with `free`. Never mix them.

---

### auto And Type Inference

`auto` tells the compiler to figure out a variable's type from the value assigned to it, rather than the programmer stating it explicitly:

```cpp
auto a = 10;        // int
auto b = 3.14;      // double
auto c = "Hello";   // const char*
auto d = std::string("World");   // std::string
```

Resolved entirely at compile time — `auto` does not make C++ dynamically typed. The type is fixed the moment it is deduced. Most useful when the actual type is long or obvious from context, which is very common with STL iterators and templates.

---

### const References

A very common C++ pattern — pass a `const` reference to get the efficiency of a reference (no copying) without allowing the function to modify the original:

```cpp
void printValue(const int &x) {
    std::cout << x << std::endl;
    // x = 20;   // ERROR — const prevents this
}
```

`const int &x` means: a reference to an `int` that cannot be used to change that `int`. This is the standard way to pass data into a function efficiently, without the risk of accidental modification.

`const` can also appear on a member function to signal it does not modify the object (covered in OOP):

```cpp
int getBalance() const { return balance; }
```

---

## Control Flow Upgrades

### Range-Based for Loops

A shorter `for` loop syntax for iterating over every element of a collection without manually managing an index:

```cpp
#include <iostream>

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};

    for (int n : numbers) {
        std::cout << n << std::endl;
    }

    return 0;
}
```

Reads as "for each element in `numbers`, call it `n`." No index variable, no manual bounds check, no risk of going out of bounds.

**To modify elements in-place, use a reference:**

```cpp
for (int &n : numbers) {
    n *= 2;   // doubles each element in the original array
}
```

**Common combinations with `auto`:**

```cpp
for (auto n : numbers) { ... }              // copy of each element
for (auto &n : numbers) { ... }             // reference — can modify
for (const auto &n : numbers) { ... }       // read-only reference — most efficient for large objects
```

Works on arrays, `std::vector`, `std::string`, `std::array`, and any container that provides iterators.

---

## Functions

### Default Arguments

A parameter can have a default value used automatically when the caller does not supply that argument:

```cpp
#include <iostream>
#include <string>

void greet(std::string name = "Guest") {
    std::cout << "Hello, " << name << std::endl;
}

int main() {
    greet("Alice");   // Hello, Alice
    greet();          // Hello, Guest
    return 0;
}
```

Default arguments must come after any parameters without defaults. Once a parameter has a default, every parameter after it must also have one:

```cpp
void example(int a, int b = 5, int c = 10);   // valid
void example(int a = 5, int b);                // invalid
```

---

### Inline Functions

The `inline` keyword suggests to the compiler that instead of generating a normal function call (which involves jumping to another memory location and jumping back), it should copy the function's code directly into every place it is called from:

```cpp
inline int square(int x) {
    return x * x;
}

int main() {
    int a = square(5);   // compiler may replace this directly with: int a = 5 * 5;
    return 0;
}
```

`inline` is only a suggestion — modern compilers often make this decision automatically. The trade-off: no call overhead, but the compiled binary gets slightly larger since the code is duplicated at each call site.

---

### Function Templates

A function template lets a single function definition work with multiple data types — without writing an overloaded version for each one manually:

```cpp
#include <iostream>

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(2, 3) << std::endl;      // T = int   → 5
    std::cout << add(2.5, 3.5) << std::endl;  // T = double → 6
    return 0;
}
```

`template <typename T>` declares `T` as a placeholder for some type. The compiler fills it in based on the arguments passed when the function is called. This is called template instantiation and happens automatically at compile time. `typename` can also be written as `class` here — both mean the same thing.

---

## The Standard Template Library (STL)

The STL is a large collection of ready-made, template-based tools built into C++: containers (ways of storing groups of data) and algorithms (functions that operate on them). None of this requires OOP to use.

### std::vector

An array that can grow or shrink automatically at run time, from `<vector>`. This is the most commonly used STL container.

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {10, 20, 30};

    numbers.push_back(40);    // add to the end
    numbers.pop_back();       // remove from the end

    std::cout << numbers[1] << std::endl;      // 20 — index access, no bounds check
    std::cout << numbers.at(1) << std::endl;   // 20 — throws if out of bounds
    std::cout << numbers.size() << std::endl;  // 3

    for (auto n : numbers) {
        std::cout << n << std::endl;
    }

    return 0;
}
```

| Method | What it does |
|---|---|
| `.push_back(val)` | Add element to the end |
| `.pop_back()` | Remove last element |
| `.size()` | Number of elements |
| `.empty()` | True if no elements |
| `.at(index)` | Access with bounds checking (throws `std::out_of_range` if bad index) |
| `.front()` / `.back()` | First / last element |
| `.clear()` | Remove all elements |

Internally, `vector` stores elements contiguously in memory like a plain array — `numbers[0]` works the same way. The difference is automatic resizing.

---

### std::array

A fixed-size array with conveniences over a plain C array, from `<array>`. Size cannot change after creation.

```cpp
#include <array>
#include <iostream>

int main() {
    std::array<int, 5> numbers = {10, 20, 30, 40, 50};
    std::cout << numbers.size() << std::endl;   // 5
    return 0;
}
```

Use it when the size is known at compile time and will never change. Use `std::vector` when the size is unknown or can change.

---

### std::pair

Holds exactly two values, possibly of different types, as one unit. From `<utility>`.

```cpp
#include <iostream>
#include <utility>

int main() {
    std::pair<std::string, int> person("Alice", 30);
    std::cout << person.first << std::endl;    // Alice
    std::cout << person.second << std::endl;   // 30
    return 0;
}
```

A lightweight alternative to a small `struct` for two related values. Also what you iterate over when looping through a `std::map`.

---

### std::map

Key-value pairs, automatically sorted by key, with fast lookup by key. From `<map>`.

```cpp
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> ages;

    ages["Alice"] = 30;
    ages["Bob"]   = 25;

    std::cout << ages["Alice"] << std::endl;   // 30

    // Each element is a std::pair<string, int>
    for (auto &pair : ages) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    // Output (alphabetical order):
    // Alice: 30
    // Bob: 25

    return 0;
}
```

Note: `ages["NewKey"]` inserts a default value if the key does not exist. Use `.count(key)` to check for existence first.

---

### std::set

Unique values only, automatically sorted, no duplicates allowed. From `<set>`.

```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> numbers;
    numbers.insert(30);
    numbers.insert(10);
    numbers.insert(30);   // ignored — already exists

    for (int n : numbers) {
        std::cout << n << std::endl;   // 10, then 30
    }
    return 0;
}
```

---

### std::stack And std::queue

```cpp
#include <iostream>
#include <stack>
#include <queue>

int main() {
    std::stack<int> s;
    s.push(1); s.push(2); s.push(3);
    std::cout << s.top() << std::endl;   // 3 — LIFO: last in, first out
    s.pop();

    std::queue<int> q;
    q.push(1); q.push(2); q.push(3);
    std::cout << q.front() << std::endl;   // 1 — FIFO: first in, first out
    q.pop();

    return 0;
}
```

**Container quick reference:**

| Container | Ordered | Unique | Use when |
|---|---|---|---|
| `vector` | Insertion order | No | General-purpose dynamic array |
| `array` | Insertion order | No | Fixed-size, known at compile time |
| `map` | Sorted by key | Yes (keys) | Key-value lookup with sorted order |
| `set` | Sorted | Yes | Unique values, sorted membership |
| `stack` | LIFO | No | Undo operations, recursion simulation |
| `queue` | FIFO | No | Task processing, breadth-first search |

---

### STL Algorithms

The `<algorithm>` header provides ready-made functions that operate on containers through iterators, so common tasks do not need to be written from scratch.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {40, 10, 30, 20};

    std::sort(numbers.begin(), numbers.end());   // sorts in place: 10 20 30 40

    auto biggest  = std::max_element(numbers.begin(), numbers.end());
    auto smallest = std::min_element(numbers.begin(), numbers.end());
    auto found    = std::find(numbers.begin(), numbers.end(), 30);

    std::cout << *biggest << std::endl;                       // 40
    std::cout << *smallest << std::endl;                      // 10
    std::cout << (found != numbers.end()) << std::endl;       // 1 (true)

    return 0;
}
```

All these functions take `.begin()` and `.end()` as range arguments — iterators that describe "all elements" of the container. An iterator is a small object that behaves like a pointer and is used to step through a container's elements.

`max_element` and `min_element` return iterators, so `*biggest` dereferences to get the actual value — same as dereferencing a pointer.

**Custom sort using a lambda** (an inline anonymous function):

```cpp
std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
    return a > b;   // return true if a should come before b
});
// numbers: 40 30 20 10
```

| Algorithm | What it does |
|---|---|
| `std::sort(b, e)` | Sorts the range in ascending order |
| `std::sort(b, e, cmp)` | Sorts with a custom comparator |
| `std::reverse(b, e)` | Reverses the range in place |
| `std::find(b, e, val)` | Returns iterator to first match, or `.end()` if not found |
| `std::count(b, e, val)` | Counts how many times `val` appears |
| `std::max_element(b, e)` | Iterator to the largest element |
| `std::min_element(b, e)` | Iterator to the smallest element |
| `std::fill(b, e, val)` | Sets every element to `val` |

---

### Class Templates

Just as a function template lets one function work with any type, a class template lets an entire class work with any type. This is exactly what `std::vector<T>` is under the hood:

```cpp
#include <iostream>
#include <string>

template <typename T>
class Box {
private:
    T value;

public:
    Box(T v) { value = v; }
    T getValue() { return value; }
};

int main() {
    Box<int> intBox(10);
    Box<std::string> stringBox("Hello");

    std::cout << intBox.getValue() << std::endl;    // 10
    std::cout << stringBox.getValue() << std::endl; // Hello
    return 0;
}
```

`Box<int>` and `Box<std::string>` are two distinct types, both generated from the same `Box` blueprint at compile time.

---

### Common Headers

| Header | What it gives you |
|---|---|
| `<iostream>` | `std::cout`, `std::cin`, `std::cerr`, `std::endl` |
| `<string>` | `std::string`, `std::getline` |
| `<vector>` | `std::vector` |
| `<array>` | `std::array` |
| `<map>` | `std::map` |
| `<set>` | `std::set` |
| `<stack>` | `std::stack` |
| `<queue>` | `std::queue` |
| `<utility>` | `std::pair` |
| `<algorithm>` | `std::sort`, `std::find`, `std::reverse`, `std::max_element`, etc. |
| `<numeric>` | `std::accumulate`, `std::iota` |
| `<cmath>` | `sqrt`, `pow`, `fabs`, `floor`, `ceil` |
| `<cstring>` | C-style string functions: `strlen`, `strcmp`, `memcpy` |
| `<cctype>` | `isalpha`, `isdigit`, `toupper`, `tolower` |
| `<fstream>` | `std::ifstream`, `std::ofstream`, `std::fstream` |
| `<sstream>` | `std::stringstream` |
| `<stdexcept>` | `std::runtime_error`, `std::out_of_range`, etc. |
| `<memory>` | `std::unique_ptr`, `std::shared_ptr` (smart pointers) |

---

## File Handling With fstream

C-style file I/O (`fopen`, `fprintf`, `fgets`) works in C++ but is rarely used in new code. C++ provides an object-based alternative from `<fstream>` using the same stream style as `cout`/`cin`.

| Type | Purpose |
|---|---|
| `std::ofstream` | Writing to a file |
| `std::ifstream` | Reading from a file |
| `std::fstream` | Both reading and writing |

**Writing:**

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ofstream outFile("data.txt");   // opens (or creates) the file

    if (!outFile) {
        std::cerr << "Could not open file" << std::endl;
        return 1;
    }

    outFile << "Hello, file!" << std::endl;
    outFile << 42 << std::endl;

    outFile.close();
    return 0;
}
```

`<<` writes into the file exactly like `std::cout` writes to the terminal, because both are stream objects sharing the same overloaded `<<`. By default, `ofstream` overwrites the file. To append instead:

```cpp
std::ofstream outFile("data.txt", std::ios::app);
```

**Reading:**

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inFile("data.txt");

    if (!inFile) {
        std::cerr << "Could not open file" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }

    inFile.close();
    return 0;
}
```

`std::getline(inFile, line)` reads one line at a time, stopping at `\n`. The `while` loop runs until there are no more lines.

**File open modes:**

| Mode flag | Meaning |
|---|---|
| `std::ios::in` | Open for reading |
| `std::ios::out` | Open for writing |
| `std::ios::app` | Append — do not overwrite, add to end |
| `std::ios::trunc` | Truncate — erase existing content (default for `ofstream`) |
| `std::ios::binary` | Open in binary mode |

Modes can be combined with `|`:

```cpp
std::fstream file("data.bin", std::ios::in | std::ios::out | std::ios::binary);
```

---

## Exception Handling

Exception handling is a structured way to deal with run-time errors. Without it, a function that fails must return a special value or set a global flag — easy for a caller to forget to check. `throw` makes it much harder to silently ignore an error, since the program will not continue past the failure point unless something explicitly handles it.

### throw, try, catch

```cpp
#include <iostream>
#include <stdexcept>

int divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero");
    }
    return a / b;
}

int main() {
    try {
        int result = divide(10, 0);
        std::cout << result << std::endl;
    } catch (const std::runtime_error &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
// Output: Error: Division by zero
```

- `throw` — raises an exception, stops execution at that point, and unwinds back through the call stack until a matching `catch` is found.
- `try { ... }` — wraps code that might throw.
- `catch (const Type &e)` — catches a specific exception type. `e.what()` returns the error message.

If no `throw` happens, `catch` is skipped entirely and execution continues normally.

### Multiple catch Blocks

A single `try` can be followed by several `catch` blocks, checked top to bottom. The first matching one runs:

```cpp
try {
    throw std::out_of_range("Index too large");
} catch (const std::out_of_range &e) {
    std::cout << "Out of range: " << e.what() << std::endl;
} catch (const std::runtime_error &e) {
    std::cout << "Runtime error: " << e.what() << std::endl;
} catch (...) {
    std::cout << "Some other exception" << std::endl;   // catches anything
}
```

`catch (...)` is a catch-all — matches any exception type. Place it last as a final fallback.

### Standard Exception Types

| Exception | Meaning |
|---|---|
| `std::runtime_error` | Error detected at run time |
| `std::out_of_range` | Accessing outside valid bounds |
| `std::invalid_argument` | Invalid argument passed to a function |
| `std::bad_alloc` | `new` failed to allocate memory |
| `std::logic_error` | Error in program logic |

### Custom Exceptions

```cpp
#include <iostream>
#include <exception>

class InsufficientFundsException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Insufficient funds for withdrawal";
    }
};

void withdraw(int balance, int amount) {
    if (amount > balance) {
        throw InsufficientFundsException();
    }
}

int main() {
    try {
        withdraw(100, 500);
    } catch (const InsufficientFundsException &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
// Output: Insufficient funds for withdrawal
```

A custom exception inherits from `std::exception` and overrides `what()`. The signature `const noexcept override` is required to match what `std::exception` expects.

### Re-throwing An Exception

A bare `throw;` inside a `catch` block re-throws the same exception to an outer handler — useful for logging locally while letting a higher level handle it:

```cpp
void process() {
    try {
        throw std::runtime_error("Something failed");
    } catch (const std::runtime_error &e) {
        std::cout << "Logged: " << e.what() << std::endl;
        throw;   // re-throw the same exception onward
    }
}

int main() {
    try {
        process();
    } catch (const std::runtime_error &e) {
        std::cout << "Handled: " << e.what() << std::endl;
    }
    return 0;
}
// Output:
// Logged: Something failed
// Handled: Something failed
```

---

## Object-Oriented Programming (OOP)

Everything above this point works without ever writing a class. OOP is a different way of organizing code — bundling data and the functions that work on it into one single unit.

The four pillars of OOP in C++ are:

```
Encapsulation  → bundling data with the functions that operate on it, restricting direct access
Inheritance    → a class reusing and extending another class's members
Polymorphism   → the same interface behaving differently depending on the actual type
Abstraction    → hiding implementation detail behind a clean interface
```

---

### The Core Idea

Without OOP, data and functions are separate:

```cpp
int balance = 1000;

void withdraw(int &balance, int amount) {
    balance -= amount;
}
```

`balance` is an open variable. Any code anywhere can read or change it. Nothing actually ties `balance` to `withdraw` beyond convention.

OOP bundles them together:

```
Old way:  balance (data)  +  withdraw() (function)   -- separate, loosely connected
OOP way:  Account { balance, withdraw() }              -- one bundled unit
```

A **class** is the blueprint. An **object** is a real instance made from that blueprint — the same relationship as a type and a variable.

---

### Classes And Objects

```cpp
class Account {
public:
    int balance;
};
```

This only defines what an `Account` looks like. No actual object exists yet.

```cpp
#include <iostream>

class Account {
public:
    int balance;
};

int main() {
    Account david;          // an object built from the blueprint
    david.balance = 1000;   // set data on THIS specific object

    std::cout << david.balance << std::endl;   // 1000
    return 0;
}
```

Multiple objects from the same class are completely independent:

```cpp
Account sara;
sara.balance = 500;

std::cout << david.balance << std::endl;   // 1000 — untouched
std::cout << sara.balance << std::endl;    // 500
```

**Stack vs heap objects:**

```cpp
Account david;                    // stack — auto-destroyed when it goes out of scope, use .
Account *david = new Account();   // heap — must be freed with delete, use ->
david->balance = 1000;
delete david;
```

`->` is used instead of `.` when the variable is a pointer to an object — same as with `struct` pointers in C.

---

### Member Functions

A function written inside a class belongs to every object of that class. When called on an object, it automatically operates on that object's own data:

```cpp
#include <iostream>

class Account {
public:
    int balance;

    void withdraw(int amount) {
        balance -= amount;   // operates on THIS object's balance automatically
    }
};

int main() {
    Account david;
    david.balance = 1000;
    david.withdraw(200);
    std::cout << david.balance << std::endl;   // 800
    return 0;
}
```

`withdraw` uses `balance` directly with no parameter for it. When `david.withdraw(200)` is called, C++ automatically operates on `david`'s own `balance`. If a second object called `withdraw`, it would act only on its own data.

**Defining member functions outside the class body:**

For larger classes, the function signature is put inside the class and the definition is written outside using `::`:

```cpp
class Account {
public:
    int balance;
    void withdraw(int amount);   // declaration inside
};

void Account::withdraw(int amount) {   // definition outside
    balance -= amount;
}
```

---

### Encapsulation

Encapsulation means bundling data with the functions that control it, and restricting direct access from outside the class. It is the first pillar of OOP.

#### Access Specifiers

With everything `public`, nothing stops invalid data from being written directly:

```cpp
Account david;
david.balance = -50000;   // nothing stops this
```

`private` restricts a member so it can only be accessed from inside the class itself:

```cpp
#include <iostream>

class Account {
private:
    int balance;   // only accessible through the class's own functions

public:
    void deposit(int amount) {
        balance += amount;
    }

    void withdraw(int amount) {
        if (amount > balance) {
            std::cout << "Insufficient funds" << std::endl;
            return;
        }
        balance -= amount;
    }

    int getBalance() const {   // const — this function promises not to modify the object
        return balance;
    }
};

int main() {
    Account david;
    david.deposit(1000);
    david.withdraw(200);
    std::cout << david.getBalance() << std::endl;   // 800

    // david.balance = 5000;   // ERROR — private
    return 0;
}
```

The class can now enforce rules (like refusing an overdraft) that were impossible when `balance` was a wide-open variable.

```
public     → accessible from anywhere
private    → accessible only from this exact class
protected  → accessible from this class AND derived classes (covered in Inheritance)
```

If no access specifier is written, a `class` defaults to `private`. A `struct` defaults to `public` — one of the only real differences between them in C++.

#### Getters And Setters

The standard pattern for controlled access to private data: a **getter** reads it, a **setter** validates and writes it.

```cpp
class Account {
private:
    int balance;
    std::string owner;

public:
    // Getter — read-only, marked const
    int getBalance() const { return balance; }
    std::string getOwner() const { return owner; }

    // Setter — validates before writing
    void setBalance(int amount) {
        if (amount < 0) {
            std::cout << "Balance cannot be negative" << std::endl;
            return;
        }
        balance = amount;
    }
};
```

Not every member needs a getter and setter. Only expose what outside code genuinely needs access to.

---

### Constructors

A constructor is a special function that runs automatically the moment an object is created. It sets the object up properly instead of leaving it uninitialized.

```cpp
#include <iostream>

class Account {
private:
    int balance;

public:
    Account() {               // default constructor — no parameters
        balance = 0;
        std::cout << "Account created" << std::endl;
    }

    Account(int start) {      // parameterized constructor
        balance = start;
    }

    int getBalance() const { return balance; }
};

int main() {
    Account a;         // calls Account()      — balance = 0
    Account b(1000);   // calls Account(int)   — balance = 1000

    std::cout << a.getBalance() << std::endl;   // 0
    std::cout << b.getBalance() << std::endl;   // 1000
    return 0;
}
```

Rules for constructors:
- Same name as the class
- No return type at all — not even `void`
- Runs automatically when the object is created, never called manually
- A class can have multiple constructors (function overloading)

**Member initializer list** — a cleaner, often more efficient way to initialize members:

```cpp
class Account {
    int balance;
    std::string owner;
public:
    Account(int b, std::string o) : balance(b), owner(o) {}
    //                              ^^^^^^^^^^^^^^^^^^^^^^
    //                              initializes before the constructor body runs
};
```

The `: balance(b), owner(o)` part runs before the constructor body. This is required for `const` members, references, and base class constructors.

---

### Destructors

A destructor runs automatically when an object is destroyed. It is used for cleanup.

```cpp
#include <iostream>

class Account {
public:
    Account(int start) {
        std::cout << "Account created" << std::endl;
    }

    ~Account() {   // same name as the class, prefixed with ~
        std::cout << "Account destroyed" << std::endl;
    }
};

int main() {
    Account david(1000);   // constructor runs here
    return 0;
}   // destructor runs here — when david goes out of scope
```

Output:

```
Account created
Account destroyed
```

Rules:
- Same name as the class, prefixed with `~`
- No return type, no parameters
- A class has exactly one destructor

Destructors matter most when an object owns heap memory:

```cpp
class Buffer {
    int *data;
public:
    Buffer(int size) { data = new int[size]; }
    ~Buffer() { delete[] data; }   // heap memory freed automatically when Buffer is destroyed
};
```

Without the destructor, the heap memory would leak every time a `Buffer` object goes out of scope.

```
Constructor  → runs on creation    → setup
Destructor   → runs on destruction → cleanup
```

---

### The this Pointer

Every non-static member function secretly receives a hidden pointer to the specific object it was called on, named `this`. It is what allows a member function to know whose data to use.

The most common use is resolving a naming conflict between a parameter and a member:

```cpp
class Account {
public:
    int balance;

    void setBalance(int balance) {
        this->balance = balance;   // this->balance = the member
                                    // balance (no this->) = the parameter
    }
};
```

`this` is a pointer, so `->` is used to access members through it. `this` is also what gets passed behind the scenes when `david.withdraw(200)` is called — `withdraw` knows to operate on `david`'s data because of `this`.

**Method chaining** — returning `*this` allows calls to be chained:

```cpp
class Account {
    int balance = 0;
public:
    Account& deposit(int amount) {
        balance += amount;
        return *this;   // return reference to this object
    }

    int getBalance() const { return balance; }
};

int main() {
    Account a;
    a.deposit(100).deposit(200).deposit(300);
    std::cout << a.getBalance() << std::endl;   // 600
    return 0;
}
```

---

### Copy Constructor

Creating a new object from an existing one triggers the copy constructor. If you do not write one, C++ generates a default that copies each member as-is.

This default works fine for simple data. It is dangerous when a class owns heap memory:

```cpp
class Buffer {
public:
    int *data;
    Buffer(int size) { data = new int[size]; data[0] = 99; }
    ~Buffer() { delete[] data; }
};

int main() {
    Buffer a(5);
    Buffer b = a;   // default copy: copies the POINTER, not the data
                    // a.data and b.data now point to the SAME heap block
                    // when both are destroyed, delete[] is called twice → crash
    return 0;
}
```

This is a **shallow copy**. The fix is a **deep copy** — a custom copy constructor that allocates separate memory:

```cpp
Buffer(const Buffer &source) {
    data = new int[5];            // allocate NEW memory
    data[0] = source.data[0];    // copy the VALUE, not the address
}

// Now:
Buffer a(5);
Buffer b = a;   // calls the custom copy constructor — each has its own memory
```

```
Shallow copy (default): copies the pointer — both objects share the same heap block.
Deep copy (custom):     allocates new memory and copies the actual values — safe.
```

---

### Static Members

A `static` member variable is shared across every object of the class — one single copy exists no matter how many objects are created.

```cpp
#include <iostream>

class Account {
public:
    static int totalAccounts;   // declaration — shared by all objects

    Account() {
        totalAccounts++;
    }
};

int Account::totalAccounts = 0;   // definition — required once, outside the class

int main() {
    Account a, b, c;
    std::cout << Account::totalAccounts << std::endl;   // 3
    return 0;
}
```

Accessed with the class name and `::`, not through any object — because it does not belong to any single object.

A `static` member function can be called without any object existing. It has no `this` and can only access other `static` members:

```cpp
static int getTotal() { return totalAccounts; }
// called as:
Account::getTotal();
```

---

### Friend Functions

`private` blocks all outside access — even from otherwise unrelated functions. A `friend` function is an explicit exception granted by the class: an outside function that is allowed to access private members.

```cpp
#include <iostream>

class Account {
private:
    int balance;

public:
    Account(int b) : balance(b) {}

    friend bool isRicher(Account a, Account b);   // granting permission
};

bool isRicher(Account a, Account b) {
    return a.balance > b.balance;   // allowed because of friend
}

int main() {
    Account david(1000), sara(500);
    std::cout << isRicher(david, sara) << std::endl;   // 1 (true)
    return 0;
}
```

- Friend functions are NOT members — called normally, not with `.` or `->`.
- The class decides who its friends are. Friendship cannot be forced from outside.
- Friendship is one-way and not inherited.

---

### Inheritance

Inheritance lets one class reuse another class's data and functions as a starting point, while adding its own members on top. It is the second pillar of OOP.

#### Base And Derived Classes

```
Character  → the base class (also: parent class, superclass)
Wizard     → the derived class (also: child class, subclass)
```

```cpp
#include <iostream>
#include <string>

class Character {
public:
    std::string name;
    int health;

    Character(std::string n, int h) : name(n), health(h) {}

    void attack() {
        std::cout << name << " attacks!" << std::endl;
    }
};

class Wizard : public Character {
public:
    int mana;

    Wizard(std::string n, int h, int m) : Character(n, h), mana(m) {}

    void castSpell() {
        std::cout << name << " casts a spell!" << std::endl;
    }
};

int main() {
    Wizard gandalf("Gandalf", 100, 50);

    gandalf.attack();     // inherited from Character — works without being re-written
    gandalf.castSpell();  // Wizard's own function

    std::cout << gandalf.name << std::endl;   // inherited data
    std::cout << gandalf.mana << std::endl;   // Wizard's own data

    return 0;
}
```

`class Wizard : public Character` means: Wizard gets everything Character has as a starting point. `public` inheritance (the common case) keeps access levels working as expected.

The constructor chain `Wizard(n, h, m) : Character(n, h), mana(m)` explicitly calls Character's constructor first to set up `name` and `health`, then initializes `mana`.

**Constructor/destructor order:**

```
Creating a Wizard:    Character's constructor runs first → then Wizard's
Destroying a Wizard:  Wizard's destructor runs first → then Character's
```

**`protected` access specifier**

`private` blocks access from everywhere including derived classes. `protected` allows access from derived classes, but still blocks it from outside code:

```cpp
class Character {
protected:
    int health;   // Wizard can access this, but main() cannot
public:
    Character(int h) : health(h) {}
};

class Wizard : public Character {
public:
    Wizard(int h) : Character(h) {}
    void heal() { health += 10; }   // allowed — health is protected
};
```

```
public     → accessible from anywhere
protected  → accessible from this class AND derived classes, nowhere else
private    → accessible only from this exact class, not even derived classes
```

---

#### Multiple Inheritance

A class can inherit from more than one base class at once:

```cpp
#include <iostream>

class Swimmer {
public:
    void swim() { std::cout << "Swimming" << std::endl; }
};

class Runner {
public:
    void run() { std::cout << "Running" << std::endl; }
};

class Triathlete : public Swimmer, public Runner {
public:
    void compete() {
        swim();
        run();
    }
};

int main() {
    Triathlete t;
    t.swim();      // from Swimmer
    t.run();       // from Runner
    t.compete();   // Triathlete's own
    return 0;
}
```

**The Diamond Problem**

Multiple inheritance creates ambiguity when two base classes share a common ancestor. If both `Swimmer` and `Runner` inherited from `Athlete`, a `Triathlete` would contain two copies of `Athlete`'s members:

```cpp
class Athlete { public: int stamina; };
class Swimmer : public Athlete { ... };
class Runner  : public Athlete { ... };
class Triathlete : public Swimmer, public Runner { ... };

Triathlete t;
t.stamina;   // ERROR — ambiguous: Swimmer::stamina or Runner::stamina?
```

The fix is **virtual inheritance** — both intermediate classes declare their inheritance as `virtual`, so only one shared copy of the common ancestor's members exists:

```cpp
class Swimmer : virtual public Athlete { ... };
class Runner  : virtual public Athlete { ... };
class Triathlete : public Swimmer, public Runner { ... };

Triathlete t;
t.stamina;   // fine — only one copy now
```

Multiple inheritance is a powerful but complex feature. In practice it is used sparingly, most often for mixing in small independent capabilities (interfaces). The diamond problem is the main reason to reach for it cautiously.

---

#### The final Keyword

`final` prevents a class from being inherited from, or prevents a virtual function from being overridden further. It is applied after the class or function name:

```cpp
class Base {
public:
    virtual void doSomething() {}
};

class Derived : public Base {
public:
    void doSomething() override final {}  // no subclass can override this
};

class Further : public Derived {
public:
    void doSomething() override {}  // ERROR — doSomething is final in Derived
};
```

Sealing a whole class:

```cpp
class Singleton final {
    // no class can inherit from Singleton
};

class Attempt : public Singleton {};  // ERROR
```

Use `final` to signal that a class is complete and not intended as a base, or that a particular virtual function's override chain ends here.

---

### Polymorphism

Polymorphism means "many forms" — the same name or interface doing different things depending on what it is operating on. It is the third pillar of OOP. C++ has two kinds: compile-time polymorphism (resolved before the program runs) and run-time polymorphism (resolved while the program runs).

---

#### Compile-Time Polymorphism

The compiler resolves which function to call at compile time, based on the types it can see.

##### Function Overloading

Multiple functions share the same name, but have different parameter lists in number or type. The compiler picks the right one at compile time — this is called overload resolution:

```cpp
#include <iostream>

int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

std::string add(std::string a, std::string b) {
    return a + b;
}

int main() {
    std::cout << add(2, 3) << std::endl;             // calls int version → 5
    std::cout << add(2.5, 3.5) << std::endl;         // calls double version → 6
    std::cout << add("Hi ", "there") << std::endl;   // calls string version → Hi there
    return 0;
}
```

The same name (`add`) behaves differently depending on the types passed — that is compile-time polymorphism. The return type alone is not enough to distinguish overloads; the parameter list must differ.

---

##### Operator Overloading

The same mechanism applied to operators. You are defining what a symbol like `+`, `==`, or `<<` means for your own type:

```cpp
#include <iostream>

class Point {
public:
    int x, y;
    Point(int x, int y) : x(x), y(y) {}

    Point operator+(const Point &other) const {
        return Point(x + other.x, y + other.y);
    }

    bool operator==(const Point &other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Point &other) const {
        return !(*this == other);
    }
};

int main() {
    Point p1(1, 2), p2(3, 4);
    Point p3 = p1 + p2;   // calls operator+()
    std::cout << p3.x << ", " << p3.y << std::endl;   // 4, 6
    std::cout << (p1 == p2) << std::endl;              // 0
    std::cout << (p1 != p2) << std::endl;              // 1
    return 0;
}
```

`p1 + p2` is shorthand for `p1.operator+(p2)`. The operator's symbol stays the same — you are defining what it means for your type.

**Overloading `<<` for printing** — needs to be a `friend` since the left side is `ostream`, not your class:

```cpp
friend std::ostream& operator<<(std::ostream &out, const Point &p) {
    out << p.x << ", " << p.y;
    return out;   // return the stream to allow chaining
}

std::cout << p1 << std::endl;   // 1, 2
```

This is exactly what `std::string` does for `+` and `==`, and what `std::ostream` does for `<<` with built-in types — now written by hand for your own class.

**Key rules:**
- Only overload an operator when its new meaning matches its natural, expected meaning.
- Overloading `==` without also overloading `!=` creates inconsistent behavior — always do both.

**The `explicit` keyword**

Single-argument constructors can be called implicitly by the compiler in unexpected places — `explicit` blocks this:

```cpp
class Distance {
public:
    explicit Distance(double m) { meters = m; }
    double meters;
};

void print(Distance d) { std::cout << d.meters; }
print(5.5);              // ERROR — explicit blocks implicit conversion
print(Distance(5.5));    // correct — must be explicit
```

Without `explicit`, `print(5.5)` would silently convert `5.5` to a `Distance`. Use `explicit` on any single-argument constructor where that implicit conversion would be surprising.

---

#### Run-Time Polymorphism

The correct function is chosen while the program is running, based on the actual type of the object — not the type of the pointer or reference used to access it.

##### Virtual Functions And Overriding

**Function overriding** — a derived class provides its own version of a function that already exists in the base class:

```cpp
#include <iostream>

class Character {
public:
    void attack() {
        std::cout << "Character attacks" << std::endl;
    }
};

class Wizard : public Character {
public:
    void attack() {   // same name, same parameters — overrides the base version
        std::cout << "Wizard casts a spell" << std::endl;
    }
};

int main() {
    Wizard gandalf;
    gandalf.attack();   // "Wizard casts a spell"
    return 0;
}
```

Different from overloading: overriding reuses the exact same function signature in a derived class to replace the base behaviour.

**The virtual gap**

Overriding by itself has a problem — calling an overridden function through a base-class pointer calls the wrong version:

```cpp
Character *c = new Wizard();
c->attack();   // prints "Character attacks" — WRONG
```

Without `virtual`, C++ decides which function to call based on the pointer's declared type (`Character*`), not the object's actual type (`Wizard`). This is static binding, decided at compile time.

Adding `virtual` to the base class function fixes this:

```cpp
#include <iostream>

class Character {
public:
    virtual void attack() {
        std::cout << "Character attacks" << std::endl;
    }
};

class Wizard : public Character {
public:
    void attack() override {   // override is optional but strongly recommended
        std::cout << "Wizard casts a spell" << std::endl;
    }
};

class Warrior : public Character {
public:
    void attack() override {
        std::cout << "Warrior swings a sword" << std::endl;
    }
};

int main() {
    Character *c = new Wizard();
    c->attack();    // "Wizard casts a spell" — correct
    delete c;
    return 0;
}
```

Now the correct version runs based on the object's actual type, decided at run time — this is called **dynamic binding** or **dynamic dispatch**.

`override` tells the compiler this function is meant to override a virtual base function. If the signature does not match (e.g. a typo), the compiler raises an error. Without `override`, a typo silently creates a new function instead of overriding.

**Why run-time polymorphism matters:**

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<Character*> party;
    party.push_back(new Wizard());
    party.push_back(new Warrior());

    for (Character *member : party) {
        member->attack();   // correct version runs for each automatically
    }
    // Output:
    // Wizard casts a spell
    // Warrior swings a sword

    for (Character *member : party) {
        delete member;
    }
    return 0;
}
```

The loop does not know or care whether each `member` is a `Wizard` or a `Warrior`. `virtual` ensures the right version runs. This is impossible to achieve cleanly without run-time polymorphism.

**Virtual destructors**

If a class is used polymorphically (deleted through a base pointer), its destructor must be `virtual`. Without it, only the base destructor runs, skipping the derived class's cleanup:

```cpp
class Character {
public:
    virtual ~Character() {}   // virtual destructor
};

class Wizard : public Character {
public:
    ~Wizard() { /* Wizard-specific cleanup */ }
};

Character *c = new Wizard();
delete c;   // with virtual ~Character: Wizard's destructor runs first, then Character's
            // without it: only Character's destructor runs — leak
```

**Rule:** any class intended to be a base class should have a `virtual` destructor.

---

##### Abstract Classes And Pure Virtual Functions

Sometimes a base class only exists to be inherited from and should never be instantiated directly. A pure virtual function enforces this:

```cpp
class Character {
public:
    virtual void attack() = 0;   // pure virtual — no body, "= 0"
};
```

Any class with at least one pure virtual function is an **abstract class** — it cannot be instantiated. A derived class must override every pure virtual function to become instantiable:

```cpp
#include <iostream>

class Character {
public:
    virtual void attack() = 0;   // must be implemented by any concrete class
    virtual void defend() = 0;

    virtual ~Character() {}      // virtual destructor — always needed in a base class
};

class Wizard : public Character {
public:
    void attack() override {
        std::cout << "Wizard casts a spell" << std::endl;
    }
    void defend() override {
        std::cout << "Wizard raises a magic shield" << std::endl;
    }
};

int main() {
    // Character c;              // ERROR — cannot instantiate abstract class
    Wizard gandalf;              // fine — both pure virtuals are implemented
    gandalf.attack();

    Character *c = new Wizard(); // fine — used polymorphically through a pointer
    c->attack();
    delete c;
    return 0;
}
```

Abstract classes define a **contract**: every concrete subclass is guaranteed to have `attack()` and `defend()`, whatever they look like. The base class does not need to guess what those implementations do — it just demands that they exist.

This is C++'s version of an **interface**: a pure abstract class with no data and only pure virtual functions:

```cpp
class IAttackable {
public:
    virtual void attack() = 0;
    virtual void takeDamage(int amount) = 0;
    virtual ~IAttackable() {}
};
```

Any class that inherits from `IAttackable` and implements all its pure virtual functions satisfies the interface — a clean separation between what a type must do and how it does it.

---

## Errors

All error categories from the C readme apply directly in C++ — compile-time, linker, run-time, and logical errors. C++ adds a few new failure modes:

**Uncaught exception (run-time)**

If a `throw` happens and no matching `catch` exists anywhere in the call chain, the program terminates:

```cpp
int main() {
    throw std::runtime_error("Something went wrong");
}
// terminate called after throwing an instance of 'std::runtime_error'
//   what():  Something went wrong
// Aborted (core dumped)
```

**Mismatched new/delete (undefined behavior)**

```cpp
int *arr = new int[5];
delete arr;    // wrong — should be delete[] arr
               // may crash or silently corrupt memory
```

**Double free from shallow copy (run-time)**

```cpp
class Buffer {
    int *data;
public:
    Buffer(int size) { data = new int[size]; }
    ~Buffer() { delete[] data; }
};

Buffer a(5);
Buffer b = a;   // default shallow copy — both share same pointer
// both destructors call delete[] on the same address
// free(): double free detected → Aborted (core dumped)
```

Fix: write a custom deep copy constructor.

**Object slicing (logical)**

Assigning a derived object to a base object by value silently discards the derived-specific parts:

```cpp
Wizard w;
Character c = w;   // slicing — c only gets name and health, mana is gone
                    // no error, no warning — data is just lost
```

Avoided by using pointers or references to the base class instead of copying by value.

**Diamond problem without virtual inheritance (logical/compile-time)**

```cpp
class Triathlete : public Swimmer, public Runner { ... };
t.stamina;   // ERROR — ambiguous without virtual inheritance
```

Fix: use `virtual public` on both intermediate base classes.

**Common mistakes summary:**

| Mistake | Category | Symptom |
|---|---|---|
| Uncaught exception | Run-time | `Aborted (core dumped)` |
| `delete` on `new[]` memory | Undefined behavior | Crash or silent corruption |
| Missing deep copy constructor | Run-time | Double free crash |
| Object slicing | Logical | Lost data, no error message |
| Abstract class instantiation | Compile-time | Compiler error |
| Non-virtual destructor in base | Run-time | Derived destructor never runs — leak |
| Missing `override` keyword | Logical | Typo creates a new function instead of overriding |
| `using namespace std` in a header | Logical | Name collisions spread to every file that includes it |
| Diamond inheritance without `virtual` | Compile-time / Logical | Ambiguous member access or duplicate data |
| Implicit conversion from single-arg constructor | Logical | Silent unexpected type conversion |