# C++

C++ is a general-purpose programming language, built as an extension of C.

It keeps almost everything C can do — direct memory control, speed, closeness to hardware — and adds a large set of new tools on top: safer I/O, references, function overloading, generic programming with templates, exception handling, a large standard library of ready-made data structures and algorithms, and Object-Oriented Programming (OOP).

C++ is still a compiled language. Human-readable `.cpp` source code is converted into machine code before it can run, the same overall journey as C.

Simple idea:

```text
C++ = C + extra tools for writing safer, more reusable, more expressive code + OOP.
```

## Index

- [History](#history)
- [Why C++ Was Created](#why-c-was-created)
- [Where C++ Is Used](#where-c-is-used)
- [What C++ Upgrades From C](#what-c-upgrades-from-c)
- [A Basic C++ Program](#a-basic-c-program)
- [Topics Already Covered In C](#topics-already-covered-in-c)
- [Storage Classes](#storage-classes)
- [Namespaces](#namespaces)
- [std::cout And std::cin](#stdcout-and-stdcin)
- [The bool Type](#the-bool-type)
- [References](#references)
- [Function Overloading](#function-overloading)
- [Default Arguments](#default-arguments)
- [Inline Functions](#inline-functions)
- [const In C++](#const-in-c)
- [auto And Type Inference](#auto-and-type-inference)
- [Range-Based for Loops](#range-based-for-loops)
- [nullptr](#nullptr)
- [new And delete](#new-and-delete)
- [std::string](#stdstring)
- [The Scope Resolution Operator ::](#the-scope-resolution-operator-)
- [Function Templates](#function-templates)
- [The Standard Template Library (STL)](#the-standard-template-library-stl)
- [STL Algorithms](#stl-algorithms)
- [More STL Containers](#more-stl-containers)
- [File Handling With fstream](#file-handling-with-fstream)
- [Exception Handling](#exception-handling)
- [How C++ Code Becomes A Program](#how-c-code-becomes-a-program)
- [Errors](#errors)
- [Object-Oriented Programming (OOP)](#object-oriented-programming-oop)
  - [The Core Idea](#the-core-idea)
  - [Classes And Objects](#classes-and-objects)
  - [Stack vs Heap Objects](#stack-vs-heap-objects)
  - [Member Functions](#member-functions)
  - [Access Specifiers (public / private) And Encapsulation](#access-specifiers-public--private-and-encapsulation)
  - [Constructors](#constructors)
  - [Destructors](#destructors)
  - [The this Pointer](#the-this-pointer)
  - [Copy Constructor (Shallow vs Deep Copy)](#copy-constructor-shallow-vs-deep-copy)
  - [Friend Functions](#friend-functions)
  - [Static Members](#static-members)
  - [Inheritance](#inheritance)
  - [protected Access Specifier](#protected-access-specifier)
  - [Types Of Inheritance](#types-of-inheritance)
  - [Function Overriding](#function-overriding)
  - [Virtual Functions And Polymorphism](#virtual-functions-and-polymorphism)
  - [Virtual Destructors](#virtual-destructors)
  - [Abstract Classes And Pure Virtual Functions](#abstract-classes-and-pure-virtual-functions)
  - [Operator Overloading (Custom Classes)](#operator-overloading-custom-classes)
        - [Overloading Unary Operators](#overloading-unary-operators)
  - [OOP Errors](#oop-errors)

## History

C++ was created by Bjarne Stroustrup in the early 1980s at Bell Labs, the same place C was created a decade earlier.

Stroustrup was working with C but wanted a language that also supported the idea of grouping data and the functions that work on that data together, an idea called classes, which he had seen in a language called Simula. At first he called his creation "C with Classes."

The name was later changed to C++. The `++` is a small joke, borrowed from C's own increment operator, meaning "one step beyond C."

Simple idea:

```text
C++ started as C, plus the idea of classes, plus everything else that grew from there.
```

## Why C++ Was Created

C++ was created to add higher-level organization on top of C's low-level control.

C is powerful, but as programs grow large, plain C makes it harder to keep related data and the functions that operate on it organized together. Stroustrup wanted a language that kept C's speed and closeness to hardware, but also let programmers build bigger, more organized, more reusable systems.

C++ achieved this without throwing away C. Almost all valid C code is also valid C++ code, so programmers did not have to abandon their existing skills or codebases to move to it.

## Where C++ Is Used

C++ is used where speed and control still matter, but the software is large or complex enough to benefit from more structure than plain C offers.

Common uses of C++:

- game engines and game development
- operating system components
- browsers (large parts of Chrome and Firefox are C++)
- embedded systems
- high-frequency trading and financial systems
- compilers
- graphics and physics engines
- large desktop applications (e.g. Adobe products)

## What C++ Upgrades From C

Everything from the C readme still applies: variables, `if`/`else`, loops, functions, pointers, arrays, `struct`, `malloc`/`free`, file handling, and so on all work the same way in C++.

On top of that, C++ adds:

```text
- a different, object-based I/O system (std::cout / std::cin)
- references, an alternative to pointers for many uses
- function overloading and default arguments
- a real bool type
- auto, for type inference
- range-based for loops
- a built-in, safer string type (std::string)
- new / delete, replacing malloc / free
- templates, for writing generic, type-independent code
- the Standard Template Library (STL): ready-made containers and algorithms
- exception handling (try / catch / throw)
- namespaces, to avoid naming collisions
- classes and Object-Oriented Programming (OOP)
```

## A Basic C++ Program

A simple C++ program looks like this:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

`#include <iostream>` includes the input/output stream library, C++'s replacement for `stdio.h` in most cases.

`int main()` is the starting point, exactly like in C. Writing `main()` with empty parentheses in C++ is the same as writing `main(void)` in C — it means no arguments.

`std::cout` is used to print output, in place of `printf`. It is explained in full detail in its own section below, since it works very differently from `printf` under the hood.

`<<` sends data into `std::cout` to be printed. It is explained in the same section.

`std::endl` prints a newline, similar to `\n`, and is also explained further below.

`return 0` means the same thing it meant in C: the program ended successfully.

## Topics Already Covered In C

The following topics work the same way in C++ as they do in C, and are not repeated here. Refer back to the [C readme](../C/README.MD) for these:

- Variables and basic data types (`int`, `float`, `double`, `char`)
- Type modifiers (`signed`, `unsigned`, `short`, `long`)
- Type casting
- Arithmetic, relational, logical, and assignment operators
- Operator precedence
- `if` / `else` / `switch`
- `while`, `do-while`, `for`, `break`, `continue`, nested loops
- Function declarations, definitions, parameters, and arguments
- Call by value
- Pointer-based reference (passing an address to change a value)
- Pointers and memory addresses (`&`, `*`)
- Arrays and their relationship with pointers
- C-style strings (char arrays ending in `\0`) — though `std::string` is now usually preferred, covered below
- `struct`
- `enum` and `typedef`
- `malloc`, `calloc`, `realloc`, `free` (still valid in C++, though `new`/`delete` are now more common, covered below)
- File operations (`fopen`, `fprintf`, `fgets`, `fclose`)

## Storage Classes

A storage class controls two things about a variable: where it lives in memory, and how long it lives (its lifetime/scope), separate from its data type.

```cpp
auto int a = 10;      // automatic — default for local variables, rarely written explicitly
static int b = 10;    // retains its value between function calls
extern int c;          // declared here, defined in another file
register int d = 10;   // suggests storing in a CPU register for fast access
```

### static (storage duration, not the OOP "static member")

```cpp
#include <iostream>

void counter() {
    static int count = 0;   // initialized ONCE, keeps its value across calls
    count++;
    std::cout << count << std::endl;
}

int main() {
    counter();
    counter();
    counter();
    return 0;
}
```

Output:

```text
1
2
3
```

Without `static`, `count` would reset to `0` on every call, since a normal local variable is destroyed when the function returns. `static` makes it persist across calls, while still being scoped only inside `counter` (nothing outside can see it directly).

### extern

`extern` declares that a variable exists somewhere else (another file), without defining it here. Useful when a variable needs to be shared across multiple `.cpp` files.

```cpp
// file1.cpp
int sharedValue = 100;

// file2.cpp
extern int sharedValue;   // refers to the one defined in file1.cpp
```

### register

`register` suggests to the compiler that a variable should be stored in a CPU register instead of regular memory, for faster access — similar in spirit to how `inline` is a suggestion for functions. Modern compilers usually make this decision automatically, so `register` is rarely written today, but still appears in course material and older code.

Simple idea:

```text
auto     -> normal local variable (default, rarely written explicitly)
static   -> keeps its value between function calls, scoped to where it's declared
extern   -> declared here, defined in a different file
register -> suggests CPU-register storage for speed (a suggestion, like inline)
```

## Namespaces

A namespace is a named container for a group of names — functions, variables, types — used to prevent naming collisions.

Two different libraries might each define something called `add` or `Timer`. Without namespaces, the compiler would not know which one is meant. A namespace wraps a group of names so they can be referred to by a prefix instead of colliding.

```cpp
#include <iostream>

int main() {
    std::cout << "Hello" << std::endl;
    return 0;
}
```

Here, `cout` and `endl` both live inside a namespace called `std`, the standard namespace, which holds almost everything in C++'s standard library. `std::cout` means "the `cout` that lives inside the `std` namespace."

A namespace is not a rule and not a function — it is a labeled container. It doesn't run or enforce anything; it just groups a set of names under a shared prefix, the same way a folder groups files so two files can both be named `notes.txt` without colliding, as long as they live in different folders.

`std` itself is not built by one single header. Many headers each add their own pieces into the same shared `std` namespace: `<iostream>` adds `cout`/`cin`, `<string>` adds `string`, `<vector>` adds `vector`, and so on. A namespace can be "reopened" by multiple files this way — it is not sealed after being written once.

### using namespace

Typing `std::` in front of everything gets repetitive, so C++ allows bringing an entire namespace into scope with `using namespace`.

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello" << endl;
    return 0;
}
```

This works, but it defeats part of the purpose of namespaces: it brings every name from `std` into the current scope, increasing the chance of collisions if the program defines its own `cout`-like name, or uses another library that also has a `using namespace`. For that reason, many style guides recommend writing `std::` explicitly, especially in larger programs, or bringing in only specific names:

```cpp
using std::cout;
using std::endl;
```

Simple idea:

```text
A namespace groups related names under one prefix, to avoid naming collisions.
std is the namespace almost all of C++'s standard library lives in.
```

## std::cout And std::cin

`std::cout` looks like a function call with `printf`, but it is not a function at all. It is an **object**.

Specifically, `std::cout` is a pre-made object of the class `std::ostream` ("output stream"), created automatically and made available the moment `<iostream>` is included. It represents the standard output stream — normally, the terminal.

`std::cin` is a similarly pre-made object, of the class `std::istream` ("input stream"), representing standard input — normally, the keyboard.

`ostream` and `istream` are classes — blueprints, not usable by themselves. `cout` and `cin` are objects — actual, ready-made instances built from those blueprints, sitting there waiting to be used the moment `<iostream>` is included. (Classes and objects are explained fully in the OOP section later in this readme; for now, just think of `cout`/`cin` as two ready-made tools handed to every C++ program.)

Roughly, the standard library conceptually contains something like:

```cpp
namespace std {
    class ostream {
    public:
        ostream& operator<<(int value) {
            // convert value to text, send to terminal
            return *this;
        }
        ostream& operator<<(const char* text) {
            // send text to terminal
            return *this;
        }
        // ...many more overloaded versions: double, std::string, bool, etc.
    };

    ostream cout;   // an actual object, ready to use
}
```

### The `<<` And `>>` Operators

```cpp
std::cout << "Hello" << std::endl;
```

`<<` is, by default, the **left shift operator**, used on integers to shift their bits (`x << 1`). That is its original, built-in meaning and still works exactly that way between two numbers.

But when the left-hand side is an `ostream` object (like `cout`), C++ instead uses a completely different function: `ostream::operator<<`, written by the standard library to redefine what `<<` means in that specific situation. This is called **operator overloading** — a special case of function overloading (see [Function Overloading](#function-overloading)) applied to an operator symbol. Writing `x << y` is really shorthand the compiler expands into `operator<<(x, y)`; operator overloading just lets you define multiple versions of that function for different types, and write them using symbol syntax instead of a normal function call.

```text
int << int          -> built-in left shift, does bit math
ostream << int        -> overloaded version, prints the int
ostream << string     -> a different overloaded version, prints the string
```

The compiler decides which version to use by looking at the type on the left, the same overload-resolution process described in [Function Overloading](#function-overloading).

Because each of these overloaded functions **returns the same stream object it just wrote into** (`return *this;`), the result of `cout << "Hello"` is `cout` itself. This is what allows chaining:

```cpp
std::cout << "Age: " << 25 << std::endl;
```

This is really parsed as:

```text
(((std::cout << "Age: ") << 25) << std::endl)
```

Each `<<` writes its piece, then hands `cout` back so the next `<<` can use it again.

`std::cin` works the same way in reverse, using an overloaded `>>` operator, which reads a value from input into a variable, and also returns the stream, allowing chained reads:

```cpp
#include <iostream>

int main() {
    int age;
    std::cout << "Enter your age: ";
    std::cin >> age;
    std::cout << "You are " << age << " years old" << std::endl;
    return 0;
}
```

Note there is no `&age` here, unlike `scanf(&age)` in C. `std::cin >> age` uses references internally (covered below) instead of requiring the programmer to manually pass an address. The stream itself handles writing into the variable's memory.

### std::endl vs \n

`std::endl` inserts a newline, similar to `\n`, but it also **flushes** the output stream, meaning it forces any buffered output to actually be written out immediately, rather than sitting in memory waiting to be written later. `\n` alone does not flush. For most small programs the difference is not noticeable, but `\n` is slightly faster when flushing is not needed, since it skips this extra step.

```cpp
std::cout << "Line one\n";
std::cout << "Line two" << std::endl;
```

Simple idea:

```text
std::cout / std::cin are pre-made stream objects, not functions.
<< and >> are operators that have been overloaded to mean "insert into" and "extract from" a stream.
Each use returns the stream itself, which is what allows chaining multiple << or >> in one line.
```

## The bool Type

C does not have a true boolean type; comparisons just produce plain integers (`0` or `1`), and older C code just uses `int` with `0`/`1` by convention. (C99 added a workaround, `_Bool`, usable as `bool`/`true`/`false` only after including `<stdbool.h>` — but it is bolted on, not a native keyword.) C++ adds a dedicated, native `bool` type, no header required.

```cpp
bool isAdult = true;
bool isMinor = false;
```

`true` and `false` are built-in keywords in C++. Internally, `true` still behaves like `1` and `false` like `0`, and a `bool` can be printed or used in arithmetic like an integer, but using `bool` for yes/no values makes code clearer to read than using a plain `int`.

```cpp
#include <iostream>

int main() {
    int age = 20;
    bool isAdult = (age >= 18);

    std::cout << isAdult << std::endl;

    return 0;
}
```

Output:

```text
1
```

`std::cout` prints a `bool` as `1` or `0` by default.

## References

A reference is an alias — another name — for an existing variable. It is not a copy, and it is not exactly a pointer either, though it is closely related to one.

```cpp
int a = 10;
int &ref = a;
```

Here, `ref` is not a new variable with its own memory. It is another name for the exact same memory location as `a`. Changing `ref` changes `a`, and vice versa, because they refer to the same thing.

```cpp
#include <iostream>

int main() {
    int a = 10;
    int &ref = a;

    ref = 20;

    std::cout << a << std::endl;

    return 0;
}
```

Output:

```text
20
```

### References vs Pointers

Recall from the C readme that changing a variable inside a function required passing a pointer to it (`int *x`, then `*x = 20`). C++ allows the same result using a reference instead, with simpler syntax:

```cpp
#include <iostream>

void change(int &x) {
    x = 20;
}

int main() {
    int a = 10;

    change(a);

    std::cout << a << std::endl;

    return 0;
}
```

Output:

```text
20
```

Notice there is no `&a` at the call site, and no `*x` inside the function. The reference handles that automatically.

Key differences from a pointer:

```text
A pointer can be reassigned to point somewhere else. A reference cannot; it is permanently tied to the variable it was initialized with.
A pointer can be NULL, meaning it points to nothing. A reference must always refer to something valid.
A pointer needs & to create and * to use. A reference is used exactly like a normal variable, no special syntax needed at the point of use.
```

Pointers can technically do everything a reference does, plus more (reassignment, `nullptr`, pointer arithmetic) — but that extra power is exactly where common bugs come from. A reference is a deliberately narrower, safer tool for the very common case of "let this function use the real variable, without any of that extra risk." Use a reference when a variable will always refer to something real and never needs to be reassigned or nulled; use a pointer when you need that flexibility (optional/nullable values, reassignable targets, pointer arithmetic, or data structures like linked lists).

Simple idea:

```text
A reference is another name for an existing variable, not a copy.
It behaves like a simpler, safer alternative to a pointer in many common situations.
```

## Function Overloading

In C, a function name must be unique; you cannot define two different functions with the same name. C++ allows multiple functions to share the same name, as long as their parameter lists differ, either in number or type of parameters. This is called function overloading.

```cpp
#include <iostream>

int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int main() {
    std::cout << add(2, 3) << std::endl;
    std::cout << add(2.5, 3.5) << std::endl;

    return 0;
}
```

Output:

```text
5
6
```

The compiler decides which `add` to call by matching the types of the arguments given, at compile time. This process is called overload resolution.

Operator overloading (seen above with `<<`, and again later with `std::string`'s `+`/`==`) is this same mechanism, just applied to functions named `operatorX` for some symbol `X`, invoked using symbol syntax instead of a normal function call.

Simple idea:

```text
Function overloading lets the same function name be reused, as long as the parameters differ.
The compiler chooses the correct version based on the arguments passed in.
```

## Default Arguments

A function parameter can be given a default value, used automatically when the caller does not provide that argument.

```cpp
#include <iostream>

void greet(std::string name = "Guest") {
    std::cout << "Hello, " << name << std::endl;
}

int main() {
    greet("Alice");
    greet();

    return 0;
}
```

Output:

```text
Hello, Alice
Hello, Guest
```

Default arguments must come after any parameters without defaults, in the parameter list, and once a parameter has a default, every parameter after it must also have one.

```cpp
void example(int a, int b = 5, int c = 10);   // valid
void example(int a = 5, int b);                // invalid
```

## Inline Functions

The `inline` keyword suggests to the compiler that, instead of generating a normal function call (which has a small overhead — jumping to another location in memory, then jumping back), the function's code should be copied directly into the place it is called from.

```cpp
inline int square(int x) {
    return x * x;
}

int main() {
    int a = square(5);    // compiler may rewrite this directly as: int a = 5 * 5;
    int b = square(10);   // and this as:                            int b = 10 * 10;
    return 0;
}
```

Without `inline`, every call to `square` means: jump away to `square`'s code, run it, jump back to exactly where execution left off. That jumping is the small "call overhead." With `inline`, the compiler instead pastes `square`'s code directly at each call site — no jump, no jump back — at the cost of the compiled program being slightly larger, since the code is duplicated everywhere it's used instead of existing once.

`inline` is only a suggestion. Modern compilers are often smart enough to make this decision on their own, with or without the keyword, so it is used far less often today than it used to be, but it still appears in real code and headers.

## const In C++

`const` exists in C too, but C++ uses it more heavily and strictly, especially together with references and pointers.

```cpp
const int MAX = 100;
```

This works exactly like in C: `MAX` cannot be reassigned after this line.

### const References

A very common pattern in C++ is passing a reference as `const`, to get the efficiency of a reference (no copying) without allowing the function to modify the original value.

```cpp
#include <iostream>

void printValue(const int &x) {
    std::cout << x << std::endl;
}

int main() {
    int a = 10;
    printValue(a);

    return 0;
}
```

Here, `x` refers directly to `a` with no copy made, but the `const` guarantees the function cannot accidentally modify `a` through `x`. Trying to do `x = 20;` inside `printValue` would cause a compile-time error.

Simple idea:

```text
const int &x means: a reference to an int, that cannot be used to change that int.
This is the common way to pass data efficiently, without letting a function alter it by mistake.
```

## auto And Type Inference

`auto` tells the compiler to figure out a variable's type automatically, based on the value assigned to it, instead of the programmer stating the type explicitly.

```cpp
auto a = 10;        // compiler infers int
auto b = 3.14;       // compiler infers double
auto c = "Hello";    // compiler infers const char*
```

This is resolved entirely at compile time; `auto` does not make C++ a dynamically typed language. The type is still fixed once decided, it is just written for you.

```cpp
#include <iostream>

int main() {
    auto age = 25;
    std::cout << age << std::endl;

    return 0;
}
```

`auto` is most useful when the actual type is long, complicated, or not particularly important to state explicitly, which becomes more common once templates and STL containers (covered below) are introduced.

Simple idea:

```text
auto asks the compiler to work out the type from the assigned value, at compile time.
```

## Range-Based for Loops

C++ adds a shorter `for` loop syntax, for looping over every element of a collection (like an array), without manually managing an index.

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

Output:

```text
10
20
30
40
50
```

`for (int n : numbers)` reads as "for each element in `numbers`, call it `n`." There is no index variable, no manual bounds checking, and no risk of an out-of-bounds access, unlike a traditional `for (int i = 0; i < 5; i++)` loop.

This only works on things you can iterate over — arrays, `std::vector`, `std::string`, `std::array`, and similar containers — not on a single plain variable like a lone `int`, since there is nothing "inside" it to loop over.

`auto` is commonly combined with this:

```cpp
for (auto n : numbers) {
    std::cout << n << std::endl;
}
```

## nullptr

In C, a pointer that points to nothing is usually set to `NULL`, which is really just `0` in disguise. This can cause ambiguity: the compiler sometimes cannot tell whether `0` is meant as the integer zero or as a null pointer, which matters when combined with function overloading.

C++ introduces `nullptr`, a dedicated keyword that means "a pointer to nothing," and nothing else. It is not the same as the integer `0`, even though it behaves similarly in a boolean check.

```cpp
int *p = nullptr;

if (p == nullptr) {
    // p does not point to anything valid
}
```

Simple idea:

```text
nullptr replaces NULL in C++. It exists specifically to represent "no address," without the ambiguity of also meaning the number 0.
```

## new And delete

C++ provides its own operators for dynamic memory, `new` and `delete`, as alternatives to C's `malloc` and `free`.

```cpp
int *p = new int;
*p = 10;

delete p;
```

`new int` allocates enough memory for one `int` on the heap and returns a pointer to it, similar to `malloc(sizeof(int))`, but there is no need to specify a size manually or cast the result — `new` already knows the type and returns the correct pointer type directly.

```cpp
int *p = new int(10);   // allocate and initialize in one step
```

`delete p;` frees memory allocated with `new`, similar to `free(p)`.

### new[] And delete[]

For arrays, a different pair is used:

```cpp
int *arr = new int[5];

for (int i = 0; i < 5; i++) {
    arr[i] = i * 10;
}

delete[] arr;
```

`new[]` must always be matched with `delete[]`, not plain `delete`, and `new` (single object) must always be matched with plain `delete`, not `delete[]`. Mismatching them is undefined behavior.

### new vs malloc

```text
new returns a correctly-typed pointer.        malloc returns void*, needs a cast in C++.
new can initialize the value immediately.      malloc leaves memory uninitialized.
new throws an exception on failure.            malloc returns NULL on failure.
delete / delete[] free new-allocated memory.   free() frees malloc-allocated memory.
```

`new` and `malloc` memory should never be mixed: memory from `new` must be released with `delete`, and memory from `malloc` must be released with `free`. Using `free` on `new`-allocated memory, or `delete` on `malloc`-allocated memory, is undefined behavior.

Simple idea:

```text
new / delete are C++'s type-safe replacements for malloc / free.
new[] / delete[] are used specifically for arrays.
```

## std::string

C has no built-in string type, only char arrays ending in `\0`, as covered in the C readme. C++ provides a real string type, `std::string`, from the `<string>` header, which handles memory management automatically.

```cpp
#include <iostream>
#include <string>

int main() {
    std::string name = "Alice";

    std::cout << name << std::endl;

    return 0;
}
```

Unlike a C-style char array, a `std::string` can grow and shrink automatically, does not require a fixed size to be declared upfront, and does not need a manually tracked `\0` terminator, though one still exists internally.

### Common Operations

```cpp
#include <iostream>
#include <string>

int main() {
    std::string first = "Hello";
    std::string second = "World";

    std::string combined = first + " " + second;   // concatenation with +

    std::cout << combined << std::endl;
    std::cout << combined.length() << std::endl;    // length
    std::cout << combined.substr(0, 5) << std::endl; // substring
    std::cout << (first == "Hello") << std::endl;    // comparison with ==

    return 0;
}
```

Output:

```text
Hello World
11
Hello
1
```

Notice `+` and `==` both work directly on `std::string`, unlike C-style strings, which needed functions like `strcat` and `strcmp` for the same tasks. This is again operator overloading: the `std::string` class defines its own versions of `+` and `==`. (Once you reach [Operator Overloading (Custom Classes)](#operator-overloading-custom-classes) later in this readme, you'll be able to write this exact kind of thing yourself, for your own classes.)

### std::string And cin

```cpp
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cout << "Hello, " << name << std::endl;

    return 0;
}
```

Like `scanf("%s", ...)`, `std::cin >> name` stops reading at the first space. To read a full line, including spaces, `std::getline` is used instead:

```cpp
std::string fullName;
std::cout << "Enter your full name: ";
std::getline(std::cin, fullName);
```

Simple idea:

```text
std::string is a built-in, resizeable string type.
It supports operators like + and == directly, and manages its own memory.
```

## The Scope Resolution Operator ::

`::` has already been used throughout this readme, in `std::cout`, `std::cin`, `std::string`. It is called the scope resolution operator, and its job is to say "look inside this specific scope for the following name."

```cpp
std::cout
```

means: "look inside the `std` namespace, and find `cout` there."

In the OOP section later in this readme, `::` is also used to define a class's functions outside the class body, and to access things that belong to a specific class rather than to any particular object of it. For now, it is enough to recognize `::` as meaning "belongs to this namespace/class" wherever it appears.

## Function Templates

A function template lets a single function definition work with multiple different data types, without needing function overloading to write a separate version for each type manually.

Recall the overloaded `add` function from earlier, one version for `int`, one for `double`. A template can express that same idea in one definition:

```cpp
#include <iostream>

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(2, 3) << std::endl;
    std::cout << add(2.5, 3.5) << std::endl;

    return 0;
}
```

Output:

```text
5
6
```

`template <typename T>` declares that `T` is a placeholder for some type, to be decided later. `T` can be read as "some type," and is filled in by the compiler based on the arguments actually passed in.

When `add(2, 3)` is called, the compiler sees two `int` arguments, and generates a version of `add` with `T` replaced by `int`, at compile time. When `add(2.5, 3.5)` is called, it generates a separate version with `T` replaced by `double`. This process is called template instantiation, and it happens automatically, without the programmer writing either version by hand.

`typename` can also be written as `class` in this context (`template <class T>`); both mean the same thing here and do not require `T` to actually be a class.

Simple idea:

```text
A template lets a function work with any type, by leaving the type as a placeholder (T),
which the compiler fills in automatically based on how the function is called.
```

### Class Templates

Just like a function template lets a function work with any type, a class template lets an entire class work with any type — this is exactly what `std::vector<T>` is, under the hood.

```cpp
#include <iostream>

template <typename T>
class Box {
private:
    T value;

public:
    Box(T v) {
        value = v;
    }

    T getValue() {
        return value;
    }
};

int main() {
    Box<int> intBox(10);
    Box<std::string> stringBox("Hello");

    std::cout << intBox.getValue() << std::endl;
    std::cout << stringBox.getValue() << std::endl;

    return 0;
}
```

Output:

```text
10
Hello
```

`template <typename T>` placed before the class works the same way as with a function — `T` is a placeholder, filled in when the class is actually used: `Box<int>` and `Box<std::string>` are two distinct types, both generated from the same one `Box` blueprint.

Every member function inside a class template implicitly uses `T` as well — no extra `template` keyword needed inside the class body, since it's already been declared for the whole class above it.

Simple idea:

```text
A class template lets a whole class work with any type, not just one function.
std::vector, std::array, and std::pair are all class templates you've already used.
```

## The Standard Template Library (STL)

The STL is a large collection of ready-made, template-based tools that come built into C++: containers (ways of storing groups of data), and algorithms (ready-made functions that operate on them). All of this exists independently of OOP, and can be used without ever writing a class.

The STL is really built from two kinds of templates working together:

```text
Containers (class templates)   -> vector, string, array, pair — templating a whole TYPE, not just one function
Algorithms (function templates) -> sort, find, max_element — plain function templates, working through iterators
```

### std::vector

`std::vector`, from `<vector>`, behaves like an array that can grow or shrink automatically at run time, unlike a plain C-style array, whose size is fixed once declared.

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {10, 20, 30};

    numbers.push_back(40);   // add to the end

    for (int n : numbers) {
        std::cout << n << std::endl;
    }

    std::cout << numbers.size() << std::endl;

    return 0;
}
```

Output:

```text
10
20
30
40
4
```

`std::vector<int>` uses template syntax: `<int>` tells the vector what type of elements it will hold. `vector` is itself a class template — `vector<int>` and `vector<double>` are effectively two different types generated from the same blueprint, the same way the `add<T>` function above generates different versions for different types, just applied to an entire class instead of a single function.

`push_back` adds an element to the end, resizing the underlying memory automatically as needed. `size()` returns the current number of elements stored.

Internally, `numbers[0]` still works on a `vector` exactly like it does on a plain array, since a `vector` stores its elements contiguously in memory, just like an array does, but with automatic resizing management layered on top.

### std::array

`std::array`, from `<array>`, is a fixed-size array, like a C-style array, but wrapped with a few extra conveniences, like `.size()`.

```cpp
#include <array>
#include <iostream>

int main() {
    std::array<int, 5> numbers = {10, 20, 30, 40, 50};

    std::cout << numbers.size() << std::endl;

    return 0;
}
```

Unlike `std::vector`, its size cannot change after creation, similar to a plain C array, but it still gains useful member functions.

### std::pair

`std::pair`, from `<utility>`, holds exactly two values, possibly of different types, together as one unit.

```cpp
#include <iostream>
#include <utility>

int main() {
    std::pair<std::string, int> person("Alice", 30);

    std::cout << person.first << std::endl;
    std::cout << person.second << std::endl;

    return 0;
}
```

Output:

```text
Alice
30
```

`.first` and `.second` access the two stored values. This is a lightweight alternative to writing a small `struct` for cases involving just two related values.

Simple idea:

```text
The STL provides ready-made, resizeable, type-flexible containers,
built using templates, so they work with any data type without rewriting them.
```

## STL Algorithms

The `<algorithm>` header provides ready-made functions that operate on containers like `vector` or `array`, so common tasks do not need to be written from scratch.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {40, 10, 30, 20};

    std::sort(numbers.begin(), numbers.end());

    for (int n : numbers) {
        std::cout << n << std::endl;
    }

    return 0;
}
```

Output:

```text
10
20
30
40
```

`sort` takes two arguments describing a range: `.begin()`, an iterator pointing to the first element, and `.end()`, an iterator pointing just past the last element. An iterator is a small object that behaves similarly to a pointer, used to step through a container's elements; the full concept is a topic on its own, but for now it is enough to know that `.begin()` and `.end()` describe "the whole container" to functions like `sort`.

A few other commonly used algorithms:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {40, 10, 30, 20};

    auto biggest = std::max_element(numbers.begin(), numbers.end());
    auto smallest = std::min_element(numbers.begin(), numbers.end());
    bool found = std::find(numbers.begin(), numbers.end(), 30) != numbers.end();

    std::cout << *biggest << std::endl;
    std::cout << *smallest << std::endl;
    std::cout << found << std::endl;

    return 0;
}
```

```text
std::sort           sorts a range in place
std::max_element     returns an iterator to the largest element
std::min_element     returns an iterator to the smallest element
std::find            returns an iterator to the first matching element, or .end() if not found
std::reverse          reverses a range in place
```

`max_element` and `min_element` return iterators, not the values directly, so `*biggest` (dereferencing, exactly as with a pointer) is used to get the actual value.

Simple idea:

```text
STL algorithms are ready-made functions that work on any compatible container,
operating over a range described by a begin and end iterator.
```

## More STL Containers

Beyond `vector`, `array`, and `pair`, a few more STL containers come up constantly.

### std::map

`std::map`, from `<map>`, stores key-value pairs, automatically sorted by key, with fast lookup by key.

```cpp
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> ages;

    ages["Alice"] = 30;
    ages["Bob"] = 25;

    std::cout << ages["Alice"] << std::endl;

    for (auto &pair : ages) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
```

Output:

```text
30
Alice: 30
Bob: 25
```

`ages["Alice"]` both reads and writes, similar to array indexing, but with a `std::string` as the "index" instead of a number. Each element, when iterated, is a `std::pair<key, value>` — hence `pair.first` and `pair.second`.

### std::set

`std::set`, from `<set>`, stores unique values only, automatically sorted, with no duplicates allowed.

```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> numbers;

    numbers.insert(30);
    numbers.insert(10);
    numbers.insert(30);   // duplicate — ignored

    for (int n : numbers) {
        std::cout << n << std::endl;
    }

    return 0;
}
```

Output:

```text
10
30
```

### std::stack And std::queue

`std::stack`, from `<stack>`, is Last-In-First-Out (LIFO). `std::queue`, from `<queue>`, is First-In-First-Out (FIFO).

```cpp
#include <iostream>
#include <stack>
#include <queue>

int main() {
    std::stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout << s.top() << std::endl;   // 3 — last one in, comes out first
    s.pop();

    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    std::cout << q.front() << std::endl;   // 1 — first one in, comes out first
    q.pop();

    return 0;
}
```

Output:

```text
3
1
```

Simple idea:

```text
map    -> key-value pairs, sorted by key, fast lookup by key
set    -> unique values only, automatically sorted
stack  -> LIFO — last in, first out
queue  -> FIFO — first in, first out
```

## File Handling With fstream

The C readme covers C-style file I/O (`fopen`, `fprintf`, `fgets`). C++ provides an object-based alternative, from `<fstream>`, using the same stream style as `cout`/`cin`.

```text
ofstream  -> "output file stream", for writing to a file
ifstream  -> "input file stream", for reading from a file
fstream    -> can do both reading and writing
```

### Writing With ofstream

```cpp
#include <fstream>
#include <iostream>

int main() {
    std::ofstream outFile("data.txt");

    if (!outFile) {
        std::cout << "Could not open file" << std::endl;
        return 1;
    }

    outFile << "Hello, file!" << std::endl;
    outFile << 42 << std::endl;

    outFile.close();

    return 0;
}
```

`std::ofstream outFile("data.txt")` opens (creating, if needed) `data.txt` for writing, and `<<` writes into it exactly like `std::cout` writes to the terminal — because both `ofstream` and `cout` are stream classes, sharing the same overloaded `<<`.

### Reading With ifstream

```cpp
#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream inFile("data.txt");

    if (!inFile) {
        std::cout << "Could not open file" << std::endl;
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

`std::getline(inFile, line)` reads one line at a time from the file, the same `getline` used earlier with `std::cin`, just given a file stream instead of `cin`.

Simple idea:

```text
fstream gives C++ its own object-based file I/O, using the same << / >> / getline style as cout / cin,
instead of C's fopen / fprintf / fgets.
```

## Exception Handling

Exception handling is a way of dealing with run-time errors in a structured, recoverable way, instead of letting the program crash outright, or having to manually check a return code after every single operation.

### throw, try, catch

```cpp
#include <iostream>

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
```

Output:

```text
Error: Division by zero
```

`throw` raises an exception, an object describing what went wrong, and immediately stops normal execution at that point, unwinding back through the calling functions until it finds a matching `catch` block.

`try { ... }` wraps code that might throw an exception.

`catch (const std::runtime_error &e) { ... }` catches a specific kind of exception, if one is thrown inside the matching `try` block. `e` is a reference to the caught exception object, and `.what()` returns a description of what went wrong. `std::runtime_error`, from `<stdexcept>`, is one of several built-in standard exception types.

If no `throw` happens inside the `try` block, the `catch` block is simply skipped, and execution continues normally after it.

### Multiple catch Blocks

A single `try` can be followed by several `catch` blocks, each handling a different exception type. They are checked top to bottom, and the first matching one runs.

```cpp
#include <iostream>
#include <stdexcept>

int main() {
    try {
        throw std::out_of_range("Index too large");
    } catch (const std::out_of_range &e) {
        std::cout << "Out of range: " << e.what() << std::endl;
    } catch (const std::runtime_error &e) {
        std::cout << "Runtime error: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Some other exception" << std::endl;   // catches ANYTHING else
    }

    return 0;
}
```

Output:

```text
Out of range: Index too large
```

`catch (...)` is a catch-all — it matches any exception type at all, regardless of what was thrown, and is typically placed last as a final fallback.

### Custom Exceptions

A custom exception class usually inherits from `std::exception` (or one of its derived types, like `std::runtime_error`), and overrides `what()` to describe the specific error.

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
```

Output:

```text
Insufficient funds for withdrawal
```

`what() const noexcept override` matches the exact signature `std::exception` expects: `const` (doesn't modify the object), `noexcept` (promises not to throw itself), and `override` (confirms it's overriding the base version — the same `override` keyword from Virtual Functions).

### Re-throwing An Exception

An exception caught in one `catch` block can be thrown again with a bare `throw;`, letting an outer `try`/`catch` (further up the call chain) handle it too — useful for logging an error locally before letting a higher level deal with it properly.

```cpp
#include <iostream>
#include <stdexcept>

void process() {
    try {
        throw std::runtime_error("Something failed");
    } catch (const std::runtime_error &e) {
        std::cout << "Logged: " << e.what() << std::endl;
        throw;   // re-throw the SAME exception onward
    }
}

int main() {
    try {
        process();
    } catch (const std::runtime_error &e) {
        std::cout << "Handled at top level: " << e.what() << std::endl;
    }

    return 0;
}
```

Output:

```text
Logged: Something failed
Handled at top level: Something failed
```

Simple idea:

```text
Multiple catch blocks handle different exception types from one try, checked top to bottom.
catch (...) catches anything, usually placed last as a fallback.
Custom exceptions inherit from std::exception and override what().
A bare "throw;" inside a catch block re-throws the same exception further up the call chain.
```

### Why This Matters

Without exceptions, a function like `divide` would have to signal an error some other way, for example returning a special value, or setting a global error flag, both of which are easy for a caller to forget to check. `throw` makes it much harder to silently ignore an error, since the program will not continue past the failure point unless something explicitly handles it with a matching `catch`.

Simple idea:

```text
throw signals that something has gone wrong.
try marks code that might throw.
catch handles a thrown exception, instead of letting the program crash.
```

## How C++ Code Becomes A Program

This is the same overall journey described in the C readme: preprocessing, compilation, assembly, object code, linking, and finally an executable file that runs at run time. Refer back to that section for the full explanation of each stage.

The only practical differences in C++ are:

### g++ Instead Of gcc
C++ programs are typically compiled using `g++` instead of `gcc`.

```bash
g++ hello.cpp -o hello
```

`g++` understands C++-specific syntax (like `std::cout`, templates, and classes), and automatically links against the C++ standard library, which `gcc` does not do by default.

### Name Mangling

In C, a function's name in the compiled object code matches its name in the source code fairly directly. In C++, because of function overloading, two functions can share the same name (like the two `add` functions shown earlier), so the compiler needs a way to keep their compiled versions distinct internally.

To solve this, C++ compilers perform name mangling: they encode extra information, such as parameter types, into the internal name stored in the object file. So `add(int, int)` and `add(double, double)` end up with different mangled internal names, even though the programmer wrote `add` both times. This is handled entirely automatically and is invisible during normal C++ programming; it is only relevant when inspecting compiled object code directly, using a tool like `objdump`, as covered in the C readme, or when linking C++ code together with C code.

## Errors

All error categories from the C readme still apply directly: compile-time errors, linker errors, run-time errors, and logical errors. A few C++-specific additions:

### Uncaught Exceptions

If a `throw` happens and there is no matching `catch` anywhere along the call chain, the program terminates.

```cpp
#include <stdexcept>

int main() {
    throw std::runtime_error("Something went wrong");
}
```

```text
terminate called after throwing an instance of 'std::runtime_error'
  what():  Something went wrong
Aborted (core dumped)
```

This is a run-time error: the program compiles and starts running, but ends abruptly because the exception was never handled.

### Mismatched new/delete

```cpp
int *p = new int[5];
delete p;   // should be delete[] p;
```

This is undefined behavior at run time: using plain `delete` on memory allocated with `new[]` (or the reverse) does not reliably produce an error message, but can corrupt memory or crash unpredictably, similar in spirit to the use-after-free and buffer overflow issues covered in the C readme.

Simple idea:

```text
Most C++ errors fall into the same categories as C.
Exceptions add one more failure mode: an exception thrown but never caught, which ends the program.
```

# Object-Oriented Programming (OOP)

Everything above this point works without ever writing a class. OOP is a different way of organizing code entirely, and it is C++'s biggest addition on top of C.

## The Core Idea

In everything covered so far, data and the functions that act on it are separate and only loosely connected:

```cpp
int balance = 1000;

void withdraw(int &balance, int amount) {
    balance -= amount;
}
```

`balance` is just a number sitting in the open. Any function, anywhere, can read or change it however it wants. Nothing actually ties `balance` to `withdraw` beyond convention.

OOP's core idea: bundle data and the functions that operate on that data into one single unit, called an **object**.

```text
Old way:  balance (data)  +  withdraw() (function)   -- separate, loosely connected
OOP way:  Account { balance, withdraw() }              -- one bundled unit
```

A **class** is the blueprint describing what this bundle looks like (an `Account` has a balance, and can withdraw). An **object** is an actual instance made from that blueprint (one specific account, with its own actual balance).

## Classes And Objects

```cpp
class Account {
public:
    int balance;
};
```

```text
class       -> keyword, "I'm defining a blueprint"
Account     -> the name of this blueprint
public:     -> controls who can access what follows (full detail below)
int balance -> a variable belonging to this blueprint
{ };        -> the class body — note the required semicolon at the end
```

This only defines what an `Account` *looks like*. No actual object exists yet, the same way writing `int` as a type doesn't create a variable.

```cpp
#include <iostream>

class Account {
public:
    int balance;
};

int main() {
    Account david;         // an OBJECT, built from the Account blueprint
    david.balance = 1000;   // setting data on THIS specific object

    std::cout << david.balance << std::endl;

    return 0;
}
```

Output:

```text
1000
```

`Account david;` creates one real object, exactly like `int age;` creates one real `int`. `david.balance` uses the same `.` already familiar from `struct` — at this basic level, a class is essentially a `struct` with extra rules layered on.

Multiple objects from the same class are completely independent:

```cpp
Account sara;
sara.balance = 500;

std::cout << david.balance << std::endl;  // still 1000
std::cout << sara.balance << std::endl;   // 500
```

## Stack vs Heap Objects

Objects follow the exact same stack/heap rule as any other variable in C or C++.

```cpp
int main() {
    Account david;          // stack — created here, auto-destroyed at end of scope
    david.balance = 1000;

    return 0;
}
```

```cpp
int main() {
    Account *david = new Account();   // heap — must be freed manually
    david->balance = 1000;

    std::cout << david->balance << std::endl;

    delete david;   // required — heap memory does not clean itself up

    return 0;
}
```

```text
Account david;                    -> stack, automatic cleanup, use . to access members
Account *david = new Account();   -> heap, manual cleanup with delete, use -> to access members
```

`->` is used instead of `.` because `david` here is a pointer to the object, not the object itself — the same `->` already seen with `struct` pointers in the C readme.

## Member Functions

A function written inside a class body belongs to every object created from that class, and is called a **member function**.

```cpp
#include <iostream>

class Account {
public:
    int balance;

    void withdraw(int amount) {
        balance -= amount;
    }
};

int main() {
    Account david;
    david.balance = 1000;

    david.withdraw(200);

    std::cout << david.balance << std::endl;

    return 0;
}
```

Output:

```text
800
```

Notice `withdraw` uses `balance` directly, with no parameter for it, no `&`, nothing. When `david.withdraw(200);` is called, C++ automatically operates on `david`'s own `balance`. If a second object called `withdraw`, it would act only on its own data:

```cpp
Account sara;
sara.balance = 500;
sara.withdraw(100);

std::cout << sara.balance << std::endl;   // 400
std::cout << david.balance << std::endl;  // still 800, untouched
```

Each member function secretly receives a hidden reference to the specific object it was called on — that hidden reference is called `this`, covered in detail below.

## Access Specifiers (public / private) And Encapsulation

With everything `public`, nothing stops invalid data from being written directly:

```cpp
Account david;
david.balance = -50000;   // nothing stops this
```

`private` restricts a member so it can only be accessed from inside the class itself.

```cpp
#include <iostream>

class Account {
private:
    int balance;

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

    int getBalance() {
        return balance;
    }
};

int main() {
    Account david;

    david.deposit(1000);
    david.withdraw(200);

    std::cout << david.getBalance() << std::endl;

    // david.balance = 5000;   // ERROR — balance is private

    return 0;
}
```

Output:

```text
800
```

```text
private:   -> everything below can ONLY be accessed from inside the class
public:    -> everything below can be accessed from anywhere, including main()
```

`balance` can now only be read or changed through the `public` functions the class chooses to expose, and those functions can enforce rules — like refusing to withdraw more than the balance holds — which was impossible when `balance` was a wide-open public variable.

This — hiding internal data, exposing only controlled access through functions — is called **encapsulation**, one of the main reasons OOP exists.

If no access specifier is written at all, a `class` defaults to `private` (a `struct` defaults to `public` — one of the only real differences between the two in C++).

## Constructors

A constructor is a special function that runs automatically the moment an object is created, used to set the object up properly instead of leaving it uninitialized.

```cpp
#include <iostream>

class Account {
private:
    int balance;

public:
    Account() {
        balance = 0;
        std::cout << "Account created" << std::endl;
    }

    void deposit(int amount) {
        balance += amount;
    }

    int getBalance() {
        return balance;
    }
};

int main() {
    Account david;   // constructor runs automatically here

    david.deposit(1000);
    std::cout << david.getBalance() << std::endl;

    return 0;
}
```

Output:

```text
Account created
1000
```

```text
- has the EXACT same name as the class
- has no return type at all, not even void
- runs automatically the instant the object is created — never called manually
```

This particular version (no parameters) is the **default constructor**. Constructors can also take parameters:

```cpp
#include <iostream>

class Account {
private:
    int balance;

public:
    Account(int startingBalance) {
        balance = startingBalance;
    }

    int getBalance() {
        return balance;
    }
};

int main() {
    Account david(1000);   // constructor runs immediately with 1000

    std::cout << david.getBalance() << std::endl;

    return 0;
}
```

Output:

```text
1000
```

A class can have multiple constructors (with different parameter lists) — this is function overloading, applied to constructors.

## Destructors

A destructor is the opposite of a constructor: a special function that runs automatically when an object is **destroyed**, used for cleanup.

```cpp
#include <iostream>

class Account {
private:
    int balance;

public:
    Account(int startingBalance) {
        balance = startingBalance;
        std::cout << "Account created" << std::endl;
    }

    ~Account() {
        std::cout << "Account destroyed" << std::endl;
    }

    int getBalance() {
        return balance;
    }
};

int main() {
    Account david(1000);
    std::cout << david.getBalance() << std::endl;

    return 0;
}   // david goes out of scope here — destructor runs automatically
```

Output:

```text
Account created
1000
Account destroyed
```

```text
~Account()   -> same name as the class, prefixed with ~
             -> no return type, just like a constructor
             -> takes NO parameters — a class has only ONE destructor
```

The destructor does not run "right after" the constructor — it runs only when the object's lifetime actually ends, no matter how much code runs in between:

```cpp
int main() {
    std::cout << "Before creating object" << std::endl;

    Account david(1000);   // constructor runs HERE

    std::cout << "After creating object" << std::endl;
    std::cout << "Still using david..." << std::endl;

    return 0;   // destructor runs HERE, only now
}
```

```text
Constructor runs  ---- (object lives, used normally, however long that takes) ----  Destructor runs
```

If an object is created inside a smaller block, it is destroyed as soon as that block ends, not at the end of `main`:

```cpp
int main() {
    {
        Account david(1000);
        std::cout << "Inside block" << std::endl;
    }   // david destroyed HERE

    std::cout << "Outside block, david is already gone" << std::endl;

    return 0;
}
```

Destructors matter most when an object holds something needing manual cleanup, like heap memory:

```cpp
#include <iostream>

class Buffer {
private:
    int *data;

public:
    Buffer(int size) {
        data = new int[size];
        std::cout << "Buffer allocated" << std::endl;
    }

    ~Buffer() {
        delete[] data;
        std::cout << "Buffer freed" << std::endl;
    }
};

int main() {
    Buffer b(10);
    return 0;
}   // destructor runs here, automatically calling delete[] for you
```

Output:

```text
Buffer allocated
Buffer freed
```

Without this, whoever uses `Buffer` would have to remember to manually free `data` every time — exactly the kind of thing that gets forgotten and causes a memory leak (covered in the C readme's Errors section).

```text
Constructor  -> runs automatically on creation -> used for setup
Destructor   -> runs automatically on destruction -> used for cleanup
```

## The this Pointer

Every non-static member function secretly receives a hidden pointer to the exact object it was called on, named `this`. It is what allows a member function to know "which object's data to use" without being told explicitly.

```cpp
#include <iostream>

class Account {
public:
    int balance;

    void setBalance(int balance) {
        this->balance = balance;   // this->balance = the object's member
                                     // balance (no this->) = the parameter
    }
};

int main() {
    Account david;
    david.setBalance(1000);

    std::cout << david.balance << std::endl;

    return 0;
}
```

Output:

```text
1000
```

Here the parameter is also named `balance`, which would otherwise be ambiguous with the class's own `balance` member. `this->balance` explicitly means "the balance belonging to this specific object," resolving the ambiguity. `this` is a pointer, which is why `->` is used to access members through it, exactly like any other pointer to an object.

`this` is also what conceptually gets passed behind the scenes whenever `david.withdraw(200)` is called — `withdraw` internally behaves as if it received a hidden `this` pointing at `david`, which is how it always knows to modify `david`'s `balance` and not `sara`'s.

Simple idea:

```text
this is a hidden pointer, automatically available inside every member function,
pointing to the specific object the function was called on.
```

## Copy Constructor (Shallow vs Deep Copy)

Creating a new object **from an existing one** triggers a special constructor called the **copy constructor**.

```cpp
#include <iostream>

class Account {
public:
    int balance;

    Account(int startingBalance) {
        balance = startingBalance;
    }
};

int main() {
    Account david(1000);
    Account copy = david;   // copy constructor runs here

    std::cout << copy.balance << std::endl;

    return 0;
}
```

Output:

```text
1000
```

No copy constructor was written here — C++ silently generates a default one, which copies each member variable over as-is. This works fine for simple data like `int`.

It becomes a problem when a class holds a pointer to heap memory:

```cpp
#include <iostream>

class Buffer {
public:
    int *data;

    Buffer(int size) {
        data = new int[size];
        data[0] = 99;
    }

    ~Buffer() {
        delete[] data;
    }
};

int main() {
    Buffer original(5);
    Buffer copy = original;   // default copy constructor: copies the POINTER, not the data

    return 0;
}   // both destructors run — both call delete[] on the SAME address — undefined behavior
```

The default copy constructor copies the pointer `data` itself, not the memory it points to — so `original.data` and `copy.data` end up pointing at the exact same heap block. This is called a **shallow copy**. When both objects are destroyed, both destructors call `delete[]` on the same address — a double free, one of the run-time errors covered in the C readme.

A **deep copy** fixes this, by writing a custom copy constructor that allocates separate memory:

```cpp
#include <iostream>

class Buffer {
public:
    int *data;

    Buffer(int size) {
        data = new int[size];
        data[0] = 99;
    }

    Buffer(const Buffer &source) {
        data = new int[5];          // allocate SEPARATE memory
        data[0] = source.data[0];    // copy the actual value, not the address
    }

    ~Buffer() {
        delete[] data;
    }
};

int main() {
    Buffer original(5);
    Buffer copy = original;   // now calls the custom copy constructor

    std::cout << copy.data[0] << std::endl;

    return 0;
}   // each object frees its OWN separate memory — safe
```

Output:

```text
99
```

```text
Buffer(const Buffer &source)
```

```text
- same name as the class
- takes a reference to another object of the same class
- const, since copying FROM something shouldn't allow changing it
```

```text
Shallow copy (default): copies members as-is — fine for simple data, dangerous for pointers.
Deep copy (custom): allocates its own memory and copies actual values — safe for pointers.
```

## Type Conversion With Classes

C++ allows defining how a custom class converts to/from other types, using either a converting constructor or a conversion operator.

### Converting Constructor (other type -> class)

A constructor that takes a single argument of another type can be used to automatically convert that type into your class.

```cpp
#include <iostream>

class Distance {
public:
    double meters;

    Distance(double m) {   // converting constructor: double -> Distance
        meters = m;
    }
};

void printDistance(Distance d) {
    std::cout << d.meters << " meters" << std::endl;
}

int main() {
    printDistance(5.5);   // 5.5 (a double) is automatically converted into a Distance

    return 0;
}
```

Output:

```text
5.5 meters
```

`5.5` is not a `Distance`, but since `Distance` has a constructor accepting one `double`, C++ automatically builds a temporary `Distance` object from it to satisfy `printDistance`'s parameter type.

### Conversion Operator (class -> other type)

The reverse direction — letting your class convert *into* another type — uses a special `operator TypeName()` member function.

```cpp
#include <iostream>

class Distance {
public:
    double meters;

    Distance(double m) {
        meters = m;
    }

    operator double() {     // conversion operator: Distance -> double
        return meters;
    }
};

int main() {
    Distance d(10.0);
    double m = d;            // automatically calls operator double()

    std::cout << m << std::endl;

    return 0;
}
```

Output:

```text
10
```

`operator double()` has no return type written before it (the return type IS the operator's name, `double`) and no parameters — it defines what happens when a `Distance` needs to become a `double`.

Simple idea:

```text
Converting constructor: lets another type be automatically turned into your class.
Conversion operator (operator Type()): lets your class be automatically turned into another type.
```

## Pitfalls Of Operator Overloading And Conversions

Overloading and implicit conversions are powerful, but easy to misuse:

```text
- Overloading an operator to do something UNRELATED to its normal meaning (e.g. overloading + to subtract) makes code deeply confusing — an operator's overloaded meaning should match the operator's intuitive meaning.
- Implicit converting constructors can trigger unwanted, invisible conversions the programmer didn't intend, e.g. accidentally passing an int where a class was expected, silently constructing a temporary object.
- Marking a single-argument constructor as `explicit` prevents this kind of implicit, accidental conversion:
```

```cpp
class Distance {
public:
    explicit Distance(double m) {   // explicit — blocks implicit conversion
        meters = m;
    }
    double meters;
};

void printDistance(Distance d) { std::cout << d.meters; }

int main() {
    printDistance(5.5);        // ERROR now — no implicit conversion allowed
    printDistance(Distance(5.5)); // must be explicit
    return 0;
}
```

```text
- Overloading == without also overloading != (or vice versa) leads to inconsistent, confusing comparison behavior.
- Returning a reference to a local variable from an overloaded operator causes undefined behavior (the local is destroyed once the function returns).
```

Simple idea:

```text
Only overload an operator when its new meaning matches its normal, expected meaning.
Use explicit on single-argument constructors to prevent accidental, invisible conversions.
```

## Friend Functions

`private` blocks all outside access to a class's members — even from another, unrelated function. A **friend function** is a deliberate, explicit exception: an outside function, not a member of the class, granted permission to access that class's `private` members.

```cpp
#include <iostream>

class Account {
private:
    int balance;

public:
    Account(int startingBalance) {
        balance = startingBalance;
    }

    friend bool isRicher(Account a, Account b);   // granting permission
};

bool isRicher(Account a, Account b) {
    return a.balance > b.balance;   // allowed, because of the friend declaration
}

int main() {
    Account david(1000);
    Account sara(500);

    std::cout << isRicher(david, sara) << std::endl;

    return 0;
}
```

Output:

```text
1
```

```text
friend bool isRicher(Account a, Account b);
```

This line lives inside the class body, but does not declare a member function — it declares that this specific outside function is trusted with private access. `isRicher` itself is written entirely normally, outside the class, and called normally too: `isRicher(david, sara)`, not `david.isRicher(sara)`.

```text
- friend functions are NOT members — they are called normally, not with . or ->
- the class itself decides who its friends are; friendship cannot be forced from outside
- friendship is one-way and not inherited
```

Simple idea:

```text
private normally blocks all outside access.
friend is an explicit, class-granted exception for one specific outside function.
```

## Static Members

Every object created from a class normally gets its own separate copy of each member variable — `david.balance` and `sara.balance` are two different pieces of memory. A `static` member is the opposite: it is shared across **every** object of that class, existing as a single copy no matter how many objects exist.

```cpp
#include <iostream>

class Account {
public:
    static int totalAccounts;   // declaration only — shared across all objects

    Account() {
        totalAccounts++;
    }
};

int Account::totalAccounts = 0;   // definition — required exactly once, outside the class

int main() {
    Account a;
    Account b;
    Account c;

    std::cout << Account::totalAccounts << std::endl;

    return 0;
}
```

Output:

```text
3
```

`totalAccounts` is not owned by `a`, `b`, or `c` individually — there is exactly one `totalAccounts`, shared by the whole class, incremented every time any `Account` is constructed. It is accessed using the class name directly (`Account::totalAccounts`), with `::`, rather than through any specific object, since it does not belong to any one object.

A `static` member function works similarly — it can be called without any object existing at all, and can only access other `static` members (it has no `this`, since it is not tied to any specific object):

```cpp
class Account {
public:
    static int totalAccounts;

    static int getTotal() {
        return totalAccounts;
    }
};

int Account::totalAccounts = 0;

int main() {
    std::cout << Account::getTotal() << std::endl;   // called via the class, no object needed
    return 0;
}
```

Simple idea:

```text
A normal member variable: one copy per object.
A static member variable: one single copy, shared by the entire class.
```

## Inheritance

Inheritance lets one class reuse another class's data and functions, instead of rewriting them, while adding its own extra members on top.

```text
Character  -> the base class (also: parent class, superclass)
Wizard     -> the derived class (also: child class, subclass)
```

```cpp
#include <iostream>

class Character {
public:
    std::string name;
    int health;

    Character(std::string n, int h) {
        name = n;
        health = h;
    }

    void attack() {
        std::cout << name << " attacks!" << std::endl;
    }
};

class Wizard : public Character {
public:
    int mana;

    Wizard(std::string n, int h, int m) : Character(n, h) {
        mana = m;
    }

    void castSpell() {
        std::cout << name << " casts a spell! Mana left: " << mana << std::endl;
    }
};

int main() {
    Wizard gandalf("Gandalf", 100, 50);

    gandalf.attack();       // inherited from Character
    gandalf.castSpell();    // Wizard's own function

    std::cout << gandalf.name << std::endl;    // inherited data
    std::cout << gandalf.mana << std::endl;    // Wizard's own data

    return 0;
}
```

Output:

```text
Gandalf attacks!
Gandalf casts a spell! Mana left: 50
Gandalf
50
```

```text
class Wizard : public Character {
```

`: public Character` is the inheritance itself: "Wizard gets everything Character has, as a starting point." (`public` here controls how inherited access levels carry over — `public` inheritance, the common case, keeps things working as expected.)

```text
Wizard(std::string n, int h, int m) : Character(n, h) {
    mana = m;
}
```

This is a constructor explicitly calling the base class's constructor. Since `Wizard` inherits `name` and `health` but doesn't own them directly, `Character`'s constructor must run first to actually set them up, before `Wizard`'s own constructor body runs and sets `mana`.

`gandalf.attack()` works even though `attack()` is written entirely inside `Character` — `Wizard` got it for free through inheritance.

### Constructor/Destructor Order With Inheritance

```text
Creating a Wizard:    Character's constructor runs first -> then Wizard's constructor body runs
Destroying a Wizard:  Wizard's destructor runs first -> then Character's destructor runs
```

This makes sense logically: the "generic character" part must exist before the wizard-specific part (`mana`) can be built on top of it, and must be torn down only after the wizard-specific part is gone.

Simple idea:

```text
Inheritance lets a derived class reuse a base class's data and functions, while adding its own new members.
Base constructor always runs before derived constructor.
Base destructor always runs after derived destructor.
```

## protected Access Specifier

`private` blocks access from everywhere outside the class, including derived classes. `protected` is a third access level, sitting between `public` and `private`, created specifically for inheritance: it allows derived classes to access the member directly, while still blocking access from unrelated outside code.

```cpp
#include <iostream>

class Character {
protected:
    int health;   // accessible to Character AND any class that inherits from it

public:
    Character(int h) {
        health = h;
    }
};

class Wizard : public Character {
public:
    Wizard(int h) : Character(h) {}

    void heal() {
        health += 10;   // allowed — health is protected, Wizard is derived from Character
    }
};

int main() {
    Wizard gandalf(100);
    gandalf.heal();

    // gandalf.health;   // still an ERROR — protected blocks access from OUTSIDE the class hierarchy

    return 0;
}
```

```text
public     -> accessible from anywhere
protected  -> accessible from this class AND any class derived from it, nowhere else
private    -> accessible only from this exact class, not even derived classes
```

## Types Of Inheritance

The `Character`/`Wizard` example is single inheritance — one base, one derived class. C++ supports a few different shapes:

```text
Single       ->  one base class, one derived class                (Character -> Wizard)
Multilevel   ->  a chain: derived class becomes a base itself      (Character -> Wizard -> ArchWizard)
Multiple     ->  one derived class inherits from more than one base class
Hierarchical ->  multiple derived classes, all from the same base  (Character -> Wizard, Character -> Warrior)
```

Multilevel example:

```cpp
class Character {
public:
    std::string name;
    Character(std::string n) { name = n; }
};

class Wizard : public Character {
public:
    int mana;
    Wizard(std::string n, int m) : Character(n) { mana = m; }
};

class ArchWizard : public Wizard {
public:
    int spellPower;
    ArchWizard(std::string n, int m, int sp) : Wizard(n, m) { spellPower = sp; }
};
```

`ArchWizard` inherits everything `Wizard` has (which itself inherited everything `Character` has), plus its own `spellPower`. Constructor order chains the same way: `Character` runs first, then `Wizard`, then `ArchWizard`.

Multiple inheritance (one class, two direct bases):

```cpp
class Flyer {
public:
    void fly() { std::cout << "Flying" << std::endl; }
};

class Swimmer {
public:
    void swim() { std::cout << "Swimming" << std::endl; }
};

class Duck : public Flyer, public Swimmer {
};

int main() {
    Duck d;
    d.fly();
    d.swim();
    return 0;
}
```

`Duck` inherits from both `Flyer` and `Swimmer` directly, gaining both `fly()` and `swim()`.

### Ambiguity In Multiple Inheritance (The Diamond Problem)

When a class inherits from two classes that both inherit from the same common base, that common base ends up duplicated — creating ambiguity about which copy to use.

```text
        Character
        /        \
    Wizard      Warrior
        \        /
       BattleMage
```

```cpp
class Character {
public:
    int health = 100;
};

class Wizard : public Character {};
class Warrior : public Character {};

class BattleMage : public Wizard, public Warrior {};

int main() {
    BattleMage bm;
    // bm.health;   // ERROR — ambiguous! Which health? Wizard's copy, or Warrior's copy?

    bm.Wizard::health = 50;    // must explicitly disambiguate with ::
    return 0;
}
```

`BattleMage` ends up with **two separate copies** of `Character`'s `health` — one inherited through `Wizard`, one through `Warrior`. Writing `bm.health` is ambiguous, since the compiler can't tell which copy is meant, and refuses to guess.

### Fix: Virtual Inheritance

```cpp
class Character {
public:
    int health = 100;
};

class Wizard : virtual public Character {};
class Warrior : virtual public Character {};

class BattleMage : public Wizard, public Warrior {};

int main() {
    BattleMage bm;
    bm.health = 75;   // no longer ambiguous — only ONE shared Character exists

    return 0;
}
```

`virtual` on the inheritance itself (`: virtual public Character`) tells C++ that `Wizard` and `Warrior` should **share a single copy** of `Character`, instead of each getting their own. This resolves the ambiguity, since there's now only one `health` to refer to.

Simple idea:

```text
Multiple inheritance can duplicate a shared base class, causing ambiguous access to its members.
virtual inheritance makes derived classes share a single copy of that common base, resolving the ambiguity.
```

## Function Overriding

Overriding is when a derived class provides its **own version** of a function that already exists in its base class, replacing the base version specifically for objects of the derived type.

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
    void attack() {   // overriding — same name, same signature, as the base version
        std::cout << "Wizard casts a spell" << std::endl;
    }
};

int main() {
    Wizard gandalf;
    gandalf.attack();   // Wizard's version runs, not Character's

    return 0;
}
```

Output:

```text
Wizard casts a spell
```

This is different from overloading: overriding reuses the exact same function name and parameters in a derived class, specifically to replace the base class's behavior for that type, rather than adding an alternate version alongside it.

## Virtual Functions And Polymorphism

Overriding by itself has a gap. Consider calling `attack()` through a base-class pointer:

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
    void attack() {
        std::cout << "Wizard casts a spell" << std::endl;
    }
};

int main() {
    Character *c = new Wizard();   // a Wizard, accessed through a Character pointer
    c->attack();

    return 0;
}
```

Output:

```text
Character attacks
```

Even though `c` actually points to a `Wizard` object, `Character attacks` is printed. Without the `virtual` keyword, C++ decides which `attack()` to call based on the **pointer's type** (`Character*`), not the object's **actual type** (`Wizard`) — this is called static binding, and it happens at compile time.

Adding `virtual` to the base class's function fixes this:

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
    void attack() override {
        std::cout << "Wizard casts a spell" << std::endl;
    }
};

int main() {
    Character *c = new Wizard();
    c->attack();

    delete c;
    return 0;
}
```

Output:

```text
Wizard casts a spell
```

Now the correct version runs, based on the object's **actual type**, decided at run time instead of compile time — this is called dynamic binding, and this whole behavior is called **polymorphism** ("many forms"): the same line of code, `c->attack()`, does different things depending on what `c` actually points to.

`override` (used in the derived class) is optional but recommended — it tells the compiler "this is meant to override a virtual base function," and produces a compile-time error if it doesn't actually match one (for example, due to a typo in the function name), catching a mistake that would otherwise fail silently.

### Why This Matters

Polymorphism is what makes code like this possible: a single function, or a single container, working correctly on many different derived types, without needing to know in advance exactly which one it's dealing with:

```cpp
#include <iostream>
#include <vector>

class Character {
public:
    virtual void attack() {
        std::cout << "Character attacks" << std::endl;
    }
};

class Wizard : public Character {
public:
    void attack() override {
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
    std::vector<Character*> party;
    party.push_back(new Wizard());
    party.push_back(new Warrior());

    for (Character *member : party) {
        member->attack();   // correct version runs for each, automatically
    }

    for (Character *member : party) {
        delete member;
    }

    return 0;
}
```

Output:

```text
Wizard casts a spell
Warrior swings a sword
```

The loop doesn't know or care whether each `member` is a `Wizard` or a `Warrior` — `virtual` ensures the right `attack()` runs automatically for whatever the object actually is.

Simple idea:

```text
virtual on a base class function enables polymorphism:
the derived class's overridden version runs, even when accessed through a base class pointer,
decided at run time based on the object's real type, not the pointer's declared type.
```

## Virtual Destructors

If a class is meant to be used polymorphically (deleted through a base class pointer, as in the example above), its destructor should also be `virtual`. Without this, deleting a derived object through a base pointer only runs the base class's destructor, skipping the derived class's cleanup.

```cpp
class Character {
public:
    virtual ~Character() {
        std::cout << "Character destroyed" << std::endl;
    }
};

class Wizard : public Character {
public:
    ~Wizard() {
        std::cout << "Wizard destroyed" << std::endl;
    }
};

int main() {
    Character *c = new Wizard();
    delete c;   // with virtual ~Character(): both destructors run, Wizard's first

    return 0;
}
```

Output:

```text
Wizard destroyed
Character destroyed
```

Without `virtual` on `~Character()`, only `Character destroyed` would print — `Wizard`'s own cleanup (potentially freeing its own heap memory) would be silently skipped, a real source of memory leaks in polymorphic code.

Simple idea:

```text
A base class meant to be used through pointers, with derived classes, should have a virtual destructor,
so deleting through a base pointer still runs the derived class's own destructor first.
```

## Abstract Classes And Pure Virtual Functions

Sometimes a base class only exists to be inherited from, and should never be instantiated directly — there's no meaningful way to create a plain, generic `Character` with no specific attack behavior of its own. A **pure virtual function** enforces this.

```cpp
class Character {
public:
    virtual void attack() = 0;   // pure virtual — no body, "= 0"
};
```

`= 0` marks `attack()` as pure virtual: `Character` provides no implementation for it at all, and any class containing at least one pure virtual function becomes an **abstract class** — it cannot be instantiated directly.

```cpp
int main() {
    Character c;   // ERROR — cannot instantiate an abstract class
    return 0;
}
```

A derived class must override every pure virtual function to become instantiable itself:

```cpp
#include <iostream>

class Character {
public:
    virtual void attack() = 0;   // pure virtual
};

class Wizard : public Character {
public:
    void attack() override {
        std::cout << "Wizard casts a spell" << std::endl;
    }
};

int main() {
    // Character c;       // still an ERROR
    Wizard gandalf;         // fine — Wizard implemented attack()
    gandalf.attack();

    Character *c = new Wizard();   // fine — used polymorphically through a pointer
    c->attack();

    delete c;
    return 0;
}
```

Output:

```text
Wizard casts a spell
Wizard casts a spell
```

This is useful for describing a common interface — "every `Character` must be able to `attack()`, somehow" — without the base class needing to guess what that attack actually looks like for every possible derived type.

Simple idea:

```text
A pure virtual function (= 0) has no implementation in the base class,
and makes that class abstract — it cannot be instantiated, only inherited from.
A derived class must override every pure virtual function to become instantiable.
```

## Operator Overloading (Custom Classes)

Earlier, `std::cout << x`, `std::string`'s `+`, and `==` were all shown as operator overloading done by the standard library. The same technique can be applied to a custom class.

```cpp
#include <iostream>

class Point {
public:
    int x, y;

    Point(int xVal, int yVal) {
        x = xVal;
        y = yVal;
    }

    Point operator+(const Point &other) {
        Point result(x + other.x, y + other.y);
        return result;
    }
};

int main() {
    Point p1(1, 2);
    Point p2(3, 4);

    Point p3 = p1 + p2;   // calls the overloaded operator+

    std::cout << p3.x << ", " << p3.y << std::endl;

    return 0;
}
```

Output:

```text
4, 6
```

```text
Point operator+(const Point &other) { ... }
```

This defines what `+` means specifically between two `Point` objects: `p1 + p2` is really shorthand for `p1.operator+(p2)`, where `p1` is `this` and `p2` is `other`. Without this, writing `p1 + p2` on a custom class would be a compile-time error — the compiler has no built-in idea of what "add two Points" should mean.

`<<` can be overloaded for a custom class too, though it needs to be written as a friend function, since the left-hand side (`std::cout`, an `ostream`) is not the custom class itself:

```cpp
#include <iostream>

class Point {
public:
    int x, y;

    Point(int xVal, int yVal) {
        x = xVal;
        y = yVal;
    }

    friend std::ostream& operator<<(std::ostream &out, const Point &p) {
        out << p.x << ", " << p.y;
        return out;
    }
};

int main() {
    Point p1(1, 2);
    std::cout << p1 << std::endl;   // now works, thanks to the overload

    return 0;
}
```

Output:

```text
1, 2
```

This is exactly the same pattern used internally by `std::string` for `+` and `==`, and by `std::ostream` itself for `<<` with `int`, `double`, and `const char*` — now written by hand, for a class you defined yourself.

Simple idea:

```text
Operator overloading on a custom class defines what an operator like +, ==, or << means for it,
by writing a function named operatorX, invoked using the operator's normal symbol syntax.
```

### Overloading Unary Operators

The `+` overload shown earlier is a **binary** operator (it works on two operands: `p1 + p2`). A **unary** operator works on just one operand, like `-x` (negation) or `++x` (increment). Overloading these follows the same idea, with one fewer parameter.

```cpp
#include <iostream>

class Point {
public:
    int x, y;

    Point(int xVal, int yVal) {
        x = xVal;
        y = yVal;
    }

    Point operator-() {              // unary minus — no parameter needed
        return Point(-x, -y);
    }

    Point& operator++() {             // prefix ++
        x++;
        y++;
        return *this;
    }
};

int main() {
    Point p1(3, 4);
    Point p2 = -p1;        // calls operator-()

    std::cout << p2.x << ", " << p2.y << std::endl;

    ++p1;                   // calls operator++()
    std::cout << p1.x << ", " << p1.y << std::endl;

    return 0;
}
```

Output:

```text
-3, -4
4, 5
```

Notice `operator-()` takes no parameters at all — there's only one operand (`p1`), and it's automatically `this`. Compare this to `operator+(const Point &other)` from before, which needed one parameter for the second operand.

Postfix `++` (`p1++`, as opposed to `++p1`) is distinguished using a dummy `int` parameter, purely as a marker the compiler uses to tell prefix and postfix apart:

```cpp
Point operator++(int) {   // postfix — the "int" here is just a marker, unused
    Point temp = *this;
    x++;
    y++;
    return temp;           // returns the OLD value, as postfix ++ normally does
}
```

Simple idea:

```text
Binary operator overload (a + b): one parameter, for the right-hand operand.
Unary operator overload (-a, ++a): no parameter (prefix) or a dummy int parameter (postfix).
```

## OOP Errors

A few error types specific to OOP, beyond those already covered in the C readme's Errors section and this readme's own Errors section:

### Instantiating An Abstract Class

```cpp
class Character {
public:
    virtual void attack() = 0;
};

int main() {
    Character c;   // compile-time error
    return 0;
}
```

```text
error: cannot declare variable 'c' to be of abstract type 'Character'
```

### Double Free From Shallow Copy

```cpp
class Buffer {
public:
    int *data;
    Buffer(int size) { data = new int[size]; }
    ~Buffer() { delete[] data; }
};

int main() {
    Buffer a(5);
    Buffer b = a;   // default (shallow) copy — both share the same pointer
    return 0;
}   // both destructors run delete[] on the SAME address
```

```text
free(): double free detected in tcache 2
Aborted (core dumped)
```

A run-time error, not caught by the compiler — the fix is a custom (deep) copy constructor, as shown earlier.

### Slicing

Assigning a derived object to a base object **by value** (not by pointer/reference) discards the derived-specific parts — this is called object slicing.

```cpp
class Character {
public:
    int health = 100;
};

class Wizard : public Character {
public:
    int mana = 50;
};

int main() {
    Wizard w;
    Character c = w;   // SLICING — c only gets health, mana is discarded

    return 0;
}
```

No error or warning by default — `c` simply becomes a plain `Character`, silently losing `mana`. This is a logical error, the kind covered in the C readme: the program compiles and runs fine, but does not do what was intended. Avoided by using pointers or references to the base class instead of copying by value, when polymorphic behavior is needed.

Simple idea:

```text
Most OOP errors are either compile-time (abstract class instantiation),
run-time (double free from a missing deep copy), or logical (slicing) —
the same three categories from the C readme's Errors section, just with new OOP-specific causes.
```