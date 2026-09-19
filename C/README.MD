# C

C is a general-purpose programming language.

It is used to write programs that are fast, efficient, and close to the computer's hardware. C gives the programmer a lot of control over memory, data, and how the program runs.

C lets us write human-readable code that can be compiled into machine code, which the computer can directly execute.

C is technically a high-level programming language, but it is often called a middle-level language because it gives low-level control over memory and hardware.

Simple idea:

```text
C is a high-level language with low-level control.
```

## Index

- [History](#history)
- [Why C Was Created](#why-c-was-created)
- [Why C Is Still Popular](#why-c-is-still-popular)
- [Where C Is Used](#where-c-is-used)
- [A Basic C Program](#a-basic-c-program)
- [Taking Input](#taking-input)
- [How C Code Becomes A Program](#how-c-code-becomes-a-program)
- [Inspecting Compiled Code](#inspecting-compiled-code)
- [Variables And Data Types](#variables-and-data-types)
- [Operators And Precedence](#operators-and-precedence)
- [Control Flow](#control-flow)
- [Functions](#functions)
- [Pointers And Memory](#pointers-and-memory)
- [Arrays](#arrays)
- [Strings](#strings)
- [Structures](#structures)
- [Enums And Typedef](#enums-and-typedef)
- [Dynamic Memory Management](#dynamic-memory-management)
- [Standard Library Overview](#standard-library-overview)
- [File Operations](#file-operations)
- [Errors](#errors)

## History

C was created by Dennis Ritchie in the early 1970s at Bell Labs.

It was developed while working on the Unix operating system. In the early days, Unix was written mostly in assembly language.

Assembly language is very close to the CPU. Different computers can have different CPU instructions, so assembly code written for one type of computer may not work on another type of computer.

C made Unix more portable. Most of Unix could be written once in C and then recompiled for different computers using a C compiler. Only the machine-specific parts needed changes.

Simple idea:

```text
Assembly code is tied closely to one machine.
C code can be recompiled for different machines.
```

## Why C Was Created

C was created to make system programming easier.

Before C, a lot of system software was written in assembly language. Assembly gives strong control over hardware, but it is hard to write, hard to read, and not portable between different computers.

C gave programmers a better balance. It was close enough to hardware to write operating systems, compilers, and low-level programs, but it was also easier to read and maintain than assembly.

This made C a good language for building Unix and other system software.

## Why C Is Still Popular

C is still popular because it is fast, simple, portable, and powerful.

C programs are compiled into machine code, so they can run very efficiently. C also gives direct control over memory, which is important for operating systems, embedded systems, device drivers, compilers, databases, and performance-critical software.

C has influenced many other languages, such as C++, Java, C#, JavaScript, Go, and Rust. Learning C helps in understanding how computers, memory, and programs work under the surface.

## Where C Is Used

C is used where speed, control, and efficiency are important.

Common uses of C:

- operating systems
- embedded systems
- device drivers
- compilers
- databases
- networking software
- command-line tools
- game engines
- firmware

## A Basic C Program

A simple C program looks like this:

```c
#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    return 0;
}
```

`main` is the starting point of a C program. When the program runs, execution begins from `main`.

`int` means `main` returns an integer value to the operating system. This returned value is called the exit status.

`void` means `main` takes no arguments.

`printf` prints output. Here, it sends `Hello, World!` to standard output, and the terminal displays it.

`\n` means newline.

`return 0` means the program ended successfully.

Usually:

```text
0 = success
non-zero = error or abnormal ending
```

## Taking Input

`scanf` reads input from the keyboard (standard input) and stores it into a variable, using format specifiers similar to `printf`.

```c
#include <stdio.h>

int main(void) {
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("You are %d years old\n", age);

    return 0;
}
```

Output (user types `25`):

```text
Enter your age: 25
You are 25 years old
```

### The `&` In scanf

`scanf` needs the **address** of the variable, not the variable itself, because it has to write a value directly into that variable's memory location. This is why `&age` is used instead of just `age`.

```text
&age = address of age
scanf writes the entered value directly into that address
```

Forgetting the `&` is one of the most common beginner mistakes with `scanf`, and often does not cause a compiler error, only a run-time crash or garbage value.

### Format Specifiers

The specifier passed to `scanf` must match the variable's type, same as with `printf`.

```c
int a;
float b;
char c;
double d;

scanf("%d", &a);    // int
scanf("%f", &b);    // float
scanf("%c", &c);     // char
scanf("%lf", &d);   // double, note: %lf here, not %f
```

`double` uses `%lf` with `scanf`, even though `printf` uses `%f` for both `float` and `double`. This is a common source of confusion.

### Reading Multiple Values

`scanf` can read several values in one call, separated by spaces or newlines when entered.

```c
#include <stdio.h>

int main(void) {
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Sum: %d\n", a + b);

    return 0;
}
```

Output (user types `3 5`):

```text
Enter two numbers: 3 5
Sum: 8
```

### Reading A String With scanf

```c
char name[20];

printf("Enter your name: ");
scanf("%s", name);
```

For strings, `&` is **not** needed, because an array name already acts as a pointer to its first element (as covered in Arrays).

`%s` with `scanf` stops reading at the first space. It cannot read a full line containing spaces — for that, `fgets` is used instead.

```c
char fullName[50];

printf("Enter your full name: ");
fgets(fullName, sizeof(fullName), stdin);
```

Simple idea:

```text
scanf reads input using format specifiers, matching printf's types.
Variables need & (address). Arrays (like strings) do not.
fgets is used instead of scanf to read a full line, including spaces.
```

## How C Code Becomes A Program

A C program does not run directly as source code.

When we write C code, we write it in a human-readable form. The CPU cannot directly understand C source code. The code must first be converted into machine code, which is the binary instruction form the CPU can execute.

The full journey looks like this:

```text
C Source Code
    |
    v
Preprocessing
    |
    v
Compilation
    |
    v
Assembly Code
    |
    v
Object Code
    |
    v
Linking
    |
    v
Executable File
    |
    v
Run Time
```

On Ubuntu, we commonly use `gcc` to build C programs.

Example:

```bash
gcc hello.c -o hello
```

Here, `gcc` acts like a driver. It manages the full build process:

```text
preprocessing -> compilation -> assembly -> linking
```

GCC does not do every step alone. Internally, it can call other tools like the preprocessor, compiler, assembler, and linker.

Other C compilers also exist, such as Clang, MSVC, and TinyCC.

### 1. Preprocessing

Preprocessing happens before actual compilation.

The preprocessor handles instructions that start with `#`.

Examples:

```c
#include <stdio.h>
#define PI 3.14
```

`#define` can replace values before compilation.

Example:

```c
#define PI 3.14
```

Wherever `PI` is used, the preprocessor can replace it with `3.14`.

`#include` includes another file before compilation.

Example:

```c
#include <stdio.h>
```

This includes the `stdio.h` header file.

This is important:

```text
stdio.h does not contain the full machine code of printf.
```

It mainly contains declarations.

A declaration tells the compiler that something exists and how it should be used.

For example, `stdio.h` declares `printf`. It tells the compiler:

```text
printf exists.
printf returns an int.
printf can take a string and extra values.
```

Simple idea:

```text
Header file = declaration
Library file = actual compiled code
```

### 2. Compilation

After preprocessing, the compiler gets the expanded C code.

The compiler checks the code and converts it into assembly code.

During this stage, the compiler checks things like:

- syntax
- types
- declarations
- function usage
- missing semicolons
- wrong return types
- missing braces

Errors found here are called compile-time errors.

Example:

```c
int main(void) {
    int x = 10
    return 0;
}
```

This gives a compile-time error because the semicolon is missing after `10`.

Simple idea:

```text
Compilation checks C code and converts it into assembly code.
```

### 3. Assembly Code And Object Code

Assembly code is low-level human-readable code.

It is closer to the CPU than C, but it is still not machine code.

Example idea:

```asm
mov eax, 0
call printf
ret
```

The CPU cannot directly run assembly text. It must be converted into machine code.

The assembler converts assembly code into object code.

Object code is machine code stored inside an object file.

On Linux, object files usually have a `.o` extension:

```text
hello.o
```

Object code is already machine code, but it is usually not complete yet.

For example, our program uses:

```c
printf("Hello\n");
```

But we did not write the actual code of `printf`.

So the object file may contain something like:

```text
main is here.
printf is needed, but its final location is not fixed yet.
```

Simple idea:

```text
Assembly code = readable low-level instructions
Object code = machine code stored in a file
```

### 4. Linking

Linking connects all the needed machine-code pieces together.

Our code uses `printf`, but `printf` is not written inside our `hello.c` file.

The declaration of `printf` comes from:

```text
/usr/include/stdio.h
```

The actual compiled machine code of `printf` comes from the C standard library.

On Ubuntu, this is usually:

```text
/lib/x86_64-linux-gnu/libc.so.6
```

So:

```text
stdio.h tells the compiler what printf looks like.
libc.so.6 contains the actual compiled printf code.
the linker connects our program with that code.
```

There are two main types of linking.

Static linking copies needed library machine code into the final executable.

```text
your object code + library code = final executable
```

Dynamic linking does not copy the full library code into the executable. Instead, the executable stores a reference saying it needs a shared library like `libc.so.6`.

At run time, the operating system loads that shared library and connects the function calls.

On Ubuntu, normal C programs are usually dynamically linked by default.

Simple idea:

```text
Static linking copies library code.
Dynamic linking loads shared library code at run time.
```

### 5. Executable File And Run Time

After linking, we get the final executable file.

On Linux:

```bash
gcc hello.c -o hello
```

creates:

```text
hello
```

We run it using:

```bash
./hello
```

On Windows, executable files usually have `.exe`, like:

```text
hello.exe
```

A `.o` file contains machine code that still needs linking.

An executable contains linked machine code and extra information the operating system needs to load and run the program.

Compile time is when the program is being built.

Run time is when the program is actually running.

At run time, the operating system loads the executable into memory. If the program is dynamically linked, the dynamic loader also loads required shared libraries, such as `libc.so.6`.

Then it connects function calls like `printf` to the actual code in memory.

Simple idea:

```text
Compile time = before the program runs.
Run time = while the program is running.
```

## Inspecting Compiled Code

`objdump -d` converts machine code back into assembly text — it reads the raw binary instructions already sitting in a compiled file and displays them as readable assembly. It doesn't create anything new, just translates what's already there.

Common `objdump` variations:

```bash
objdump -d file       # disassemble: machine code -> assembly text
objdump -T file        # show dynamic symbol table (function names + their offsets)
objdump -t file         # show symbol table (local + global symbols)
objdump -h file          # show section headers (.text, .data, .bss, etc.)
objdump -x file           # show all headers (file, section, symbol)
```

If you want to see the **actual raw binary** (0s and 1s) instead of assembly, use `xxd`:

```bash
xxd file            # default hex dump, 16 bytes per line
xxd -b file          # binary mode — shows actual 0s and 1s instead of hex, 6 bytes per line
xxd -c N file         # show N bytes per line (e.g. -c 8, -c 20)
xxd -l N file          # limit output to first N bytes only
xxd -s N file           # start reading from byte offset N (skip ahead)
xxd -p file              # plain hex dump, no offsets/ASCII column, just continuous hex
xxd -r file               # reverse — convert a hex dump back into binary
```

Example — build a binary first, then inspect its raw bits:
```bash
gcc hello.c -o a.out
objdump -d a.out
xxd -b a.out
```

## Variables And Data Types

A variable is a named location in memory that stores a value.

Before a variable can be used, it must be declared with a type. The type tells the compiler how much memory to reserve and how to interpret the bits stored there.

```c
int age = 25;
```

Here:

```text
int  = data type
age  = variable name
25   = value stored
```

### Basic Data Types

```c
int a = 10;
float b = 3.14f;
double c = 3.14159265;
char d = 'A';
```

```text
int     = whole numbers, typically 4 bytes
float   = decimal numbers, single precision, typically 4 bytes
double  = decimal numbers, double precision, typically 8 bytes
char    = a single character, 1 byte, stored internally as a number
```

`char` is really just a small integer. Every character has a numeric value behind it.

```c
#include <stdio.h>

int main(void) {
    char letter = 'A';
    printf("%d\n", letter);
    return 0;
}
```

Output:

```text
65
```

`'A'` is stored as the number 65, its ASCII value.

### Size Depends On The System

Exact sizes of `int`, `float`, and other types can vary between systems and compilers. The `sizeof` operator checks the actual size on the current system.

```c
#include <stdio.h>

int main(void) {
    printf("%lu\n", sizeof(int));
    printf("%lu\n", sizeof(double));
    return 0;
}
```

Simple idea:

```text
A data type tells the compiler how much memory to use and how to read it.
```

### Type Modifiers

Modifiers adjust the range or sign of a base type.

```c
unsigned int a = 10;
short int b = 5;
long int c = 100000;
long long int d = 10000000000;
```

```text
signed    = can store negative and positive values (default for int)
unsigned  = can only store zero and positive values, doubles the positive range
short     = smaller range, uses less memory
long      = larger range, uses more memory
```

### Constants

A constant is a value that cannot change after it is set.

```c
const int MAX = 100;
```

Trying to reassign `MAX` after this line causes a compile-time error.

Simple idea:

```text
const locks a variable's value after initialization.
```

### Type Casting

Type casting converts a value from one type to another.

```c
int a = 10;
int b = 3;
float result = (float) a / b;
```

Without the cast, `a / b` would perform integer division and discard the decimal part, giving `3` instead of `3.333...`. The cast forces the division to happen using floating point math.

Simple idea:

```text
Casting tells the compiler to treat a value as a different type, temporarily.
```

## Operators And Precedence

Operators perform actions on values, called operands.

### Arithmetic Operators

```c
int a = 10, b = 3;

a + b;   // addition
a - b;   // subtraction
a * b;   // multiplication
a / b;   // division
a % b;   // modulus, remainder of division
```

`%` only works with integers. It gives the remainder left over after division.

### Relational Operators

These compare two values and produce `1` (true) or `0` (false). C does not have a true boolean type built in the way some languages do; comparisons just produce integers.

```c
a == b;   // equal to
a != b;   // not equal to
a > b;    // greater than
a < b;    // less than
a >= b;   // greater than or equal to
a <= b;   // less than or equal to
```

### Logical Operators

```c
a && b;   // logical AND, true if both are true
a || b;   // logical OR, true if either is true
!a;       // logical NOT, flips true/false
```

### Assignment Operators

```c
a = 10;   // assign
a += 5;   // a = a + 5
a -= 5;   // a = a - 5
a *= 5;   // a = a * 5
a /= 5;   // a = a / 5
```

### Increment And Decrement

```c
a++;   // post-increment, use then increase
++a;   // pre-increment, increase then use
a--;   // post-decrement
--a;   // pre-decrement
```

Example showing the difference:

```c
#include <stdio.h>

int main(void) {
    int a = 5;
    printf("%d\n", a++);
    printf("%d\n", a);
    return 0;
}
```

Output:

```text
5
6
```

`a++` returns the old value of `a` first, then increases it afterward.

### Operator Precedence

Precedence decides which operator runs first when multiple operators appear in one expression.

```c
int result = 2 + 3 * 4;
```

`*` has higher precedence than `+`, so multiplication happens first.

```text
result = 2 + (3 * 4) = 14
```

Common precedence order, from higher to lower:

```text
()                  parentheses, evaluated first
* / %               multiplication, division, modulus
+ -                 addition, subtraction
< <= > >=           relational
== !=               equality
&&                  logical AND
||                  logical OR
=                   assignment, evaluated last
```

Parentheses can always be used to force a specific order, and make code easier to read.

```c
int result = (2 + 3) * 4;
```

Simple idea:

```text
Precedence decides order of operations.
Parentheses override precedence.
```

## Control Flow

Control flow determines the order in which statements execute. Without it, a program just runs top to bottom, once, with no decisions and no repetition.

### if / else

`if` runs a block only when a condition is true (nonzero).

```c
#include <stdio.h>

int main(void) {
    int age = 20;

    if (age >= 18) {
        printf("Adult\n");
    } else {
        printf("Minor\n");
    }

    return 0;
}
```

Output:

```text
Adult
```

`else if` chains multiple conditions together, checked in order, top to bottom.

```c
int marks = 75;

if (marks >= 90) {
    printf("A\n");
} else if (marks >= 75) {
    printf("B\n");
} else if (marks >= 50) {
    printf("C\n");
} else {
    printf("Fail\n");
}
```

Only the first true condition runs. The rest are skipped, even if they would also be true.

Simple idea:

```text
if checks a condition. else runs when it is false.
```

### switch

`switch` compares one value against several possible exact matches. It is often clearer than a long `else if` chain when checking a single variable against fixed values.

```c
#include <stdio.h>

int main(void) {
    int day = 3;

    switch (day) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        default:
            printf("Unknown\n");
    }

    return 0;
}
```

Output:

```text
Wednesday
```

`break` stops execution from continuing into the next case. Without it, execution falls through into the following cases.

```c
int day = 2;

switch (day) {
    case 1:
        printf("Monday\n");
    case 2:
        printf("Tuesday\n");
    case 3:
        printf("Wednesday\n");
        break;
    default:
        printf("Unknown\n");
}
```

Output:

```text
Tuesday
Wednesday
```

Execution enters at `case 2` and keeps running every line below it until it hits a `break`.

Simple idea:

```text
switch matches a value against fixed cases.
Without break, execution falls through into the next case.
```

### while

`while` repeats a block as long as a condition stays true. The condition is checked before each run of the loop body.

```c
#include <stdio.h>

int main(void) {
    int i = 1;

    while (i <= 5) {
        printf("%d\n", i);
        i++;
    }

    return 0;
}
```

Output:

```text
1
2
3
4
5
```

If the condition is false from the start, the loop body never runs at all.

### do-while

`do-while` also repeats a block while a condition is true, but checks the condition after each run. This guarantees the body runs at least once.

```c
#include <stdio.h>

int main(void) {
    int i = 10;

    do {
        printf("%d\n", i);
        i++;
    } while (i <= 5);

    return 0;
}
```

Output:

```text
10
```

Even though `10 <= 5` is false, the body still ran once, because the check happens after the body, not before.

Simple idea:

```text
while checks the condition first.
do-while checks the condition after, so it always runs at least once.
```

### for

`for` combines initialization, condition, and update into one line. It is commonly used when the number of iterations is known in advance.

```c
#include <stdio.h>

int main(void) {
    for (int i = 1; i <= 5; i++) {
        printf("%d\n", i);
    }

    return 0;
}
```

Output:

```text
1
2
3
4
5
```

```text
int i = 1   -> runs once, before the loop starts
i <= 5      -> checked before every iteration
i++         -> runs after every iteration
```

### break And continue

`break` exits a loop immediately, skipping any remaining iterations.

```c
for (int i = 1; i <= 10; i++) {
    if (i == 5) {
        break;
    }
    printf("%d\n", i);
}
```

Output:

```text
1
2
3
4
```

`continue` skips the rest of the current iteration and moves to the next one, without exiting the loop entirely.

```c
for (int i = 1; i <= 5; i++) {
    if (i == 3) {
        continue;
    }
    printf("%d\n", i);
}
```

Output:

```text
1
2
4
5
```

Simple idea:

```text
break exits the loop completely.
continue skips to the next iteration.
```

### Nested Loops

Loops can be placed inside other loops. The inner loop completes all of its iterations for every single iteration of the outer loop.

```c
#include <stdio.h>

int main(void) {
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 3; j++) {
            printf("i=%d j=%d\n", i, j);
        }
    }

    return 0;
}
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

## Functions

A function is a block of code that performs a specific task.

Functions help us divide a program into smaller parts instead of writing everything inside one place.

Example:

```c
#include <stdio.h>

void greet(void) {
    printf("Hello\n");
}

int main(void) {
    greet();
    return 0;
}
```

Here, `greet` is a function. When we call `greet()`, the code inside the `greet` function runs.

### `main` Is Also A Function

`main` is a special function in C.

It is special because program execution starts from `main`. When we run a C program, the operating system starts the program and control eventually reaches the `main` function.

But `main` is still a function.

Like other functions, it has:

- a return type
- a name
- parameters
- a body

Example:

```c
int main(void) {
    return 0;
}
```

Here:

```text
int = return type
main = function name
void = takes no arguments
{ } = function body
return 0 = exit status
```

### Function Return Type

A function can return a value.

Example:

```c
int add(int a, int b) {
    return a + b;
}
```

Here, `int` means the function returns an integer.

If a function does not return anything, we use `void`.

Example:

```c
void greet(void) {
    printf("Hello\n");
}
```

### Function Parameters And Arguments

Parameters are variables written in the function definition.

Arguments are the actual values passed when calling the function.

Example:

```c
int add(int a, int b) {
    return a + b;
}

int main(void) {
    int result = add(2, 3);
    return 0;
}
```

Here:

```text
a and b are parameters.
2 and 3 are arguments.
```

### Function Declaration And Definition

A function declaration tells the compiler that a function exists.

Example:

```c
int add(int a, int b);
```

A function definition contains the actual body of the function.

Example:

```c
int add(int a, int b) {
    return a + b;
}
```

Simple idea:

```text
Declaration = tells what the function looks like.
Definition = contains the actual function code.
```

### Call By Value

C uses call by value by default.

This means when we pass a variable to a function, the function receives a copy of the value.

Example:

```c
#include <stdio.h>

void change(int x) {
    x = 20;
}

int main(void) {
    int a = 10;

    change(a);

    printf("%d\n", a);

    return 0;
}
```

Output:

```text
10
```

Here, `change` gets a copy of `a`. It changes the copy, not the original variable.

### Pointer-Based Reference

C does not have true call by reference like some other languages.

But C can achieve reference-like behavior using pointers.

Example:

```c
#include <stdio.h>

void change(int *x) {
    *x = 20;
}

int main(void) {
    int a = 10;

    change(&a);

    printf("%d\n", a);

    return 0;
}
```

Output:

```text
20
```

Here:

```text
&a gives the address of a.
int *x stores that address.
*x accesses the value at that address.
```

So the function can change the original variable.

Simple idea:

```text
Call by value passes a copy.
Pointer-based reference passes an address.
```

## Pointers And Memory

A pointer is a variable that stores the memory address of another variable.

Example:

```c
int a = 10;
int *p = &a;
```

Here:

```text
a stores the value 10.
&a gives the memory address of a.
p stores the address of a.
*p gives the value stored at that address.
```

Example:

```c
#include <stdio.h>

int main(void) {
    int a = 10;
    int *p = &a;

    printf("%d\n", a);
    printf("%p\n", (void *)p);
    printf("%d\n", *p);

    return 0;
}
```

Output will look something like:

```text
10
0x7ff...
10
```

The address may be different each time the program runs.

Pointers are important because they allow C programs to work directly with memory.

They are used for:

- changing original values inside functions
- arrays
- strings
- dynamic memory
- data structures
- system programming

Simple idea:

```text
A pointer stores an address.
Using that address, we can access or change data in memory.
```

## Arrays

An array is a collection of values of the same type, stored next to each other in memory.

```c
int numbers[5];
```

This reserves space for 5 integers, all next to each other in memory.

### Declaring And Initializing

```c
int numbers[5] = {10, 20, 30, 40, 50};
```

Each value is accessed using an index, starting at 0.

```c
#include <stdio.h>

int main(void) {
    int numbers[5] = {10, 20, 30, 40, 50};

    printf("%d\n", numbers[0]);
    printf("%d\n", numbers[4]);

    return 0;
}
```

Output:

```text
10
50
```

The first element is at index 0. The last element is at index `size - 1`.

Simple idea:

```text
Array index starts at 0, not 1.
```

### Arrays And Pointers

An array name, on its own, acts like a pointer to its first element.

```c
int numbers[5] = {10, 20, 30, 40, 50};
int *p = numbers;

printf("%d\n", *p);
printf("%d\n", *(p + 1));
```

Output:

```text
10
20
```

`p + 1` moves the pointer forward by one element's worth of memory, not necessarily one byte. The compiler knows the element size from the pointer's type.

### Out Of Bounds Access

C does not automatically check if an array index is valid.

```c
int numbers[5];
numbers[10] = 1;
```

This writes into memory outside the array. It may not immediately crash, but it can corrupt other data or cause a segmentation fault later.

Simple idea:

```text
C does not stop you from accessing memory outside an array.
```

## Strings

C does not have a built-in string type. A string in C is just an array of `char`, ending with a special character, `\0`, called the null terminator.

```c
char name[6] = "Hello";
```

This actually stores 6 characters: `H`, `e`, `l`, `l`, `o`, and `\0`. The null terminator marks where the string ends.

### Printing Strings

```c
#include <stdio.h>

int main(void) {
    char name[] = "Hello";
    printf("%s\n", name);
    return 0;
}
```

`%s` tells `printf` to keep printing characters until it hits `\0`.

### Why The Null Terminator Matters

Functions that work with strings rely on `\0` to know where the string ends. Without it, a function might keep reading past the intended data, into whatever memory happens to follow.

```text
"Hello" as stored in memory: H e l l o \0
```

### Common String Functions

These come from `string.h`.

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    char a[20] = "Hello";
    char b[] = "World";

    printf("%lu\n", strlen(a));

    strcat(a, b);
    printf("%s\n", a);

    printf("%d\n", strcmp(a, b));

    return 0;
}
```

```text
strlen(a)     = length of the string, not counting \0
strcat(a, b)  = appends b onto the end of a
strcmp(a, b)  = compares two strings, returns 0 if equal
```

Simple idea:

```text
A C string is a char array that ends with \0.
```

## Structures

A structure groups multiple variables, possibly of different types, under one name.

```c
struct Person {
    char name[20];
    int age;
};
```

This defines a new type, `struct Person`, but does not create a variable yet.

### Creating And Using A Structure

```c
#include <stdio.h>
#include <string.h>

struct Person {
    char name[20];
    int age;
};

int main(void) {
    struct Person p1;

    strcpy(p1.name, "Alice");
    p1.age = 30;

    printf("%s\n", p1.name);
    printf("%d\n", p1.age);

    return 0;
}
```

Output:

```text
Alice
30
```

The `.` operator accesses a member of a structure variable.

### Structures And Pointers

```c
struct Person p1;
struct Person *ptr = &p1;

ptr->age = 25;
```

`->` accesses a member through a pointer to a structure. It is shorthand for `(*ptr).age`.

Simple idea:

```text
struct groups related variables into one custom type.
```

## Enums And Typedef

### Enums

An enum defines a set of named integer constants, making code more readable than using raw numbers.

```c
enum Day { MON, TUE, WED, THU, FRI, SAT, SUN };
```

Each name is automatically assigned an integer, starting at 0 unless specified otherwise.

```c
#include <stdio.h>

enum Day { MON, TUE, WED, THU, FRI, SAT, SUN };

int main(void) {
    enum Day today = WED;

    printf("%d\n", today);

    return 0;
}
```

Output:

```text
2
```

`MON` is 0, `TUE` is 1, `WED` is 2, and so on.

Custom starting values or specific values can be assigned:

```c
enum Day { MON = 1, TUE, WED, THU, FRI, SAT, SUN };
```

Here `MON` is 1, and every following name increases by 1 automatically, so `TUE` is 2, `WED` is 3, and so on.

Simple idea:

```text
enum gives readable names to a set of related integer constants.
```

### typedef

`typedef` creates an alias for an existing type, often used to simplify long or repetitive type names.

```c
typedef unsigned int uint;

uint age = 25;
```

`uint` now means the same thing as `unsigned int`.

`typedef` is commonly used with structs, to avoid writing `struct` every time.

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
} Person;

int main(void) {
    Person p1;

    strcpy(p1.name, "Alice");
    p1.age = 30;

    printf("%s\n", p1.name);

    return 0;
}
```

Without `typedef`, this would require writing `struct Person p1;` every time a variable of this type is declared. With `typedef`, just `Person p1;` is enough.

Simple idea:

```text
typedef creates a new, shorter name for an existing type.
```

## Dynamic Memory Management

Variables declared normally (like `int a = 10;`) live on the stack, and their memory is fixed in size and automatically freed when they go out of scope.

Dynamic memory is different. It is allocated manually, at run time, from a separate region called the heap, and it stays allocated until explicitly freed.

This matters when the amount of memory needed is not known until the program is running, such as reading a file of unknown size, or building a data structure that grows over time.

### malloc

`malloc` (memory allocation) reserves a block of memory of a given size, in bytes, and returns a pointer to it. The memory is not initialized, it may contain leftover garbage values.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *p = malloc(5 * sizeof(int));

    if (p == NULL) {
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        p[i] = i * 10;
    }

    for (int i = 0; i < 5; i++) {
        printf("%d\n", p[i]);
    }

    free(p);

    return 0;
}
```

Output:

```text
0
10
20
30
40
```

`sizeof(int)` gives the size of one `int` on this system. Multiplying by 5 reserves enough space for 5 integers.

`malloc` returns `NULL` if the allocation fails, for example if the system is out of memory. This should always be checked before using the pointer.

### calloc

`calloc` (contiguous allocation) also allocates memory, but takes the number of elements and their size separately, and initializes all of it to zero.

```c
int *p = calloc(5, sizeof(int));
```

This is equivalent to `malloc(5 * sizeof(int))`, except every element starts at `0` instead of containing garbage values.

### realloc

`realloc` resizes a block of memory that was previously allocated with `malloc` or `calloc`, without losing the existing data (up to the smaller of the old and new sizes).

```c
int *p = malloc(5 * sizeof(int));
p = realloc(p, 10 * sizeof(int));
```

This grows the block from holding 5 integers to holding 10, keeping the original 5 values intact.

`realloc` may move the memory to a new location if it cannot grow in place. The returned pointer should always be used going forward, and the old pointer should not be used directly again.

### free

`free` releases memory that was allocated with `malloc`, `calloc`, or `realloc`, returning it to the system so it can be reused.

```c
int *p = malloc(sizeof(int));
free(p);
```

Every successful allocation should eventually be paired with exactly one `free`. Forgetting to free causes a memory leak. Freeing twice, or using memory after it has been freed, causes undefined behavior.

Simple idea:

```text
malloc/calloc reserve memory on the heap.
realloc resizes it.
free releases it.
Every allocation needs exactly one matching free.
```

## Standard Library Overview

C's standard library is split across several headers, each providing a related set of functions. `#include` makes the declarations from a given header available to the compiler.

```text
stdio.h    input and output: printf, scanf, fopen, fgets, fprintf
stdlib.h   general utilities: malloc, calloc, realloc, free, exit, atoi, rand
string.h   string handling: strlen, strcpy, strcat, strcmp, strchr
math.h     mathematical functions: sqrt, pow, sin, cos, fabs
ctype.h    character checks and conversion: isalpha, isdigit, toupper, tolower
time.h     date and time: time, clock, difftime
assert.h   run-time assertions: assert
```

A few commonly used functions, briefly:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(void) {
    printf("%d\n", atoi("42"));         // string to int
    printf("%f\n", sqrt(16.0));         // square root
    printf("%d\n", isdigit('5'));       // checks if character is a digit
    printf("%c\n", toupper('a'));       // converts to uppercase

    exit(0);                            // ends the program immediately
}
```

`exit()` terminates the program right away, from anywhere in the code, without needing to return through every calling function first.

Simple idea:

```text
Each standard header groups related functions.
Include only the headers a program actually needs.
```

## File Operations

C can read from and write to files using functions from `stdio.h`. A file is accessed through a `FILE` pointer.

### Writing To A File

```c
#include <stdio.h>

int main(void) {
    FILE *fp = fopen("data.txt", "w");

    if (fp == NULL) {
        return 1;
    }

    fprintf(fp, "Hello, file!\n");

    fclose(fp);

    return 0;
}
```

```text
fopen("data.txt", "w")   opens the file for writing, creates it if it does not exist
fprintf(fp, ...)         writes formatted text into the file
fclose(fp)               closes the file, saving changes
```

### Reading From A File

```c
#include <stdio.h>

int main(void) {
    FILE *fp = fopen("data.txt", "r");
    char line[100];

    if (fp == NULL) {
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }

    fclose(fp);

    return 0;
}
```

`fgets` reads one line at a time until the end of the file is reached.

### File Modes

```text
"r"   read only, file must exist
"w"   write only, creates file or overwrites existing content
"a"   append, writes are added to the end of the file
"r+"  read and write, file must exist
```

Simple idea:

```text
fopen opens a file and returns a FILE pointer.
Always check if that pointer is NULL before using it.
Always close a file after use with fclose.
```

## Errors

C errors generally fall into a few categories, based on *when* they happen: while compiling, while linking, or while the program is actually running.

### Compile-Time Errors

These happen when the compiler cannot understand or validate your code. The program never gets built at all.

**Missing semicolon**

```c
int main(void) {
    int x = 10
    return 0;
}
```
```text
error: expected ';' before 'return'
```

**Undeclared variable**

```c
int main(void) {
    x = 10;
    return 0;
}
```
```text
error: 'x' undeclared (first use in this function)
```

**Type mismatch**

```c
int main(void) {
    int x = "hello";
    return 0;
}
```
```text
error: incompatible types when initializing type 'int' using type 'char *'
```

**Missing header / implicit declaration**

```c
int main(void) {
    printf("Hi\n");
    return 0;
}
```
```text
warning: implicit declaration of function 'printf'
```
Without `#include <stdio.h>`, older compilers may only warn; modern compilers often treat this as an error.

**Mismatched braces**

```c
int main(void) {
    if (1) {
        printf("Hi\n");
    return 0;
}
```
```text
error: expected '}' at end of input
```

Simple idea:

```text
Compile-time errors mean the compiler could not translate your code at all.
The program is never built.
```

### Linker Errors

These happen after compilation succeeds, when the linker cannot find the actual code for something your program calls.

**Undefined reference**

```c
int add(int a, int b);

int main(void) {
    int result = add(2, 3);
    return 0;
}
```
```text
undefined reference to 'add'
```
The compiler accepted the declaration, but no definition for `add` exists anywhere, so the linker cannot connect the call to any actual code.

**Missing `main`**

```c
#include <stdio.h>

void greet(void) {
    printf("Hi\n");
}
```
```text
undefined reference to 'main'
```
Every executable needs exactly one `main` function. Without it, linking fails.

**Multiple definitions**

```c
// defined in two different .c files, both compiled into the same program
int add(int a, int b) {
    return a + b;
}
```
```text
multiple definition of 'add'
```

Simple idea:

```text
Linker errors mean your code compiled fine on its own,
but the pieces could not be connected into one program.
```

### Run-Time Errors

These happen while the program is actually executing. Compiling and linking succeed; the program builds and starts, then fails partway through.

**Segmentation fault**

```c
int *p = NULL;
*p = 10;
```
```text
Segmentation fault (core dumped)
```
The program tried to access memory it is not allowed to touch.

**Division by zero**

```c
int a = 10, b = 0;
int result = a / b;
```
```text
Floating point exception (core dumped)
```
Integer division by zero crashes the program at run time. (Floating-point division by zero does not crash; it produces `inf` or `nan` instead.)

**Stack overflow**

```c
void loop(void) {
    loop();
}

int main(void) {
    loop();
    return 0;
}
```
```text
Segmentation fault (core dumped)
```
Infinite recursion keeps using stack memory until none is left.

**Buffer overflow**

```c
char name[5];
strcpy(name, "This is way too long");
```
No error may appear immediately. This silently writes past the end of `name`, corrupting nearby memory. It may crash later, or not at all, making it especially dangerous.

**Use after free**

```c
int *p = malloc(sizeof(int));
free(p);
*p = 10;
```
May crash immediately, may not crash at all, or may corrupt unrelated memory. Undefined behavior — there's no guaranteed outcome.

**Memory leak**

```c
void createLeak(void) {
    int *p = malloc(sizeof(int));
}
```
No crash, no error message. Memory is allocated and never freed. Over time, repeated leaks can exhaust available memory.

Simple idea:

```text
Run-time errors happen after the program starts running.
The compiler and linker cannot catch these in advance.
```

### Logical Errors

The program compiles, links, and runs without crashing, but produces the wrong result. No error message appears at all, because nothing is technically broken from the compiler or OS's point of view.

```c
int add(int a, int b) {
    return a - b;
}
```
This compiles and runs fine. It just gives the wrong answer, because the logic itself is incorrect.

Simple idea:

```text
Logical errors are the hardest to catch, because the program never complains.
```