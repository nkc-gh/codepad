# Java

Java is a general-purpose, object-oriented programming language.

Java code is compiled into an intermediate form called bytecode, and that bytecode is run by the JVM. This is how Java achieves "write once, run anywhere."

Simple idea:

```text
Java source code compiles to bytecode.
Bytecode runs on any machine that has a JVM.
```

## Index

- [History](#history)
- [Why The Java Filename Must Match The Public Class Name](#why-the-java-filename-must-match-the-public-class-name)
- [JDK, JRE, JVM](#jdk-jre-jvm)
- [How Java Code Really Compiles And Runs](#how-java-code-really-compiles-and-runs)


## History

Java was created by James Gosling and his team at Sun Microsystems.

Development started in 1991. It was originally called "Oak," then briefly "Green," before being renamed Java. It was originally built for embedded systems and consumer electronics, like set-top boxes, not for the internet.

Java was publicly released in 1995. It became popular quickly because of the rise of the web — Java applets could run inside web browsers, which was a big deal at the time.

Sun Microsystems was acquired by Oracle in 2010. Oracle now owns and maintains Java.

## Why The Java Filename Must Match The Public Class Name

There is a rule in Java that the name of the public class must be the same as the file name, the reason is...

In C, the linker automatically searches through every compiled file to find a function named `main`, wherever it happens to be. Filenames don't matter — `main.c`, `xyz.c`, `banana.c`, anything works — because the linker's job is to scan everything given to it and locate `main` on its own, once, at build time. That decision gets permanently baked into the final executable.

```bash
gcc main.c helper.c -o myprogram
```
The linker checks both files, finds `main` inside whichever one has it, and wires the program to start there.

Java has no equivalent step. There is no linker, and the JVM never scans `.class` files looking for one that contains `main`. It does the opposite: you must tell the JVM the exact class name yourself, every time you run a program.

```bash
java Payload
```

The JVM does not search anything. It opens only one file — the one matching the name you typed — and checks only that class for a `main` method. If that exact class doesn't have one, it fails immediately. It will never look at other `.class` files sitting in the same folder, even if one of them has a perfectly valid `main`.

```text
C:    linker SEARCHES all files to FIND main automatically, at build time.
Java: JVM does NOT search. YOU name the exact class, every single run.
```

This is the actual root of the rule. Because Java never built an automatic "find main" search step the way C's linker does, the burden shifts entirely onto the class name you type. That name has to convert into an exact file to open, with zero guessing — and the only way to guarantee that conversion always works is to enforce, back at compile time, that a public class's name and its filename are always identical.

If Java had instead given the JVM a C-style linker that auto-scans every `.class` file to find whichever one has `main`, this rule would have no reason to exist — filenames could be anything, the same way they can in C. The rule only exists because Java deliberately chose not to build that automatic search, and instead made the filename itself the lookup key.

## JDK, JRE, JVM

**JVM (Java Virtual Machine)**
The program that actually executes Java bytecode. It's "virtual" because it behaves like a computer without being a real one — it reads bytecode instructions and either interprets them live or JIT-compiles frequently-run code into temporary machine code, in memory, while the program runs. It's platform-specific (a Linux JVM, a Windows JVM), which is exactly what makes bytecode itself portable — the JVM absorbs the platform difference, not your code.

**JRE (Java Runtime Environment)**
JVM + the compiled standard library classes (`System`, `String`, `ArrayList`, `PrintStream`, and thousands more). Bytecode alone can't run real programs — it constantly relies on these built-in classes. A JRE lets you **run** compiled Java programs, but not compile new ones — no `javac` included.

**JDK (Java Development Kit)**
JRE + development tools: `javac` (compiler), `jshell` (interactive shell for quick testing), `javadoc` (generates documentation from code comments), `jdb` (debugger), and more. This is what's required to actually **write and compile** Java code.

```text
JDK
 ├── javac, jshell, javadoc, jdb   (dev tools)
 └── JRE
       ├── JVM                     (executes bytecode)
       └── standard library .class files (System, String, etc.)
```

- For Installation of all these refer to internet as the version changes every few months so download the stable and usefull version.

## How Java Code Really Compiles And Runs

```java
public class HelloWorld {
    public static void main(String[] args) {
        System.out.println("Hello, World!");
    }
}
```

### 1. The Source File

This is saved as `HelloWorld.java` — plain, human-readable text. At this stage nothing is executable. The CPU has no idea what to do with this file, and neither does the OS. It only means something to a Java compiler.

The filename must exactly match the public class name (`HelloWorld.java` for `public class HelloWorld`). This isn't a loose style convention — it's a rule enforced by the compiler itself, and the reason for it becomes clear once you understand how Java finds and runs classes (covered further down).

### 2. Compiling — `javac`

```bash
javac HelloWorld.java
```

`javac` does the following, in order:
- Checks syntax — matched braces, semicolons, valid structure.
- Checks types — e.g., does `println` actually accept a `String` argument?
- Translates the source into **bytecode** — an intermediate instruction format. Not text, not real CPU machine code either — something in between, understood only by the JVM.
- Writes that bytecode into a new file: `HelloWorld.class`.

Errors caught here are compile-time errors — the classic missing-semicolon or type-mismatch failures.

### 3. What's Actually Inside `HelloWorld.class`

This file is binary. Inspecting it with `javap -c HelloWorld` shows the real instructions:

```text
public static void main(java.lang.String[]);
    Code:
       0: getstatic     #7    // Field java/lang/System.out:Ljava/io/PrintStream;
       3: ldc           #13   // String Hello, World!
       5: invokevirtual #15   // Method java/io/PrintStream.println:(Ljava/lang/String;)V
       8: return
```

This is the important, easy-to-miss part: **this file does not contain `println`'s actual working code.** It only contains name references — "call the method named `println`, on the field named `out`, from the class named `System`." Nothing from the standard library gets copied into your `.class` file at compile time. It's just a note saying what to call, not the thing itself.

### 4. Why C Doesn't Work This Way — And Why That Matters For Step 5

In C, this same situation is handled completely differently. When you `#include <stdio.h>` and call `printf`, the header only gives the compiler a declaration — a promise that `printf` exists. The actual compiled machine code for `printf` lives in `libc.so.6`, compiled separately, long before you ever wrote your program. At build time, the **linker** actively scans through every file it's given and finds wherever `main` and any needed library functions live, then wires everything — your code and the library code — into one single, self-contained executable. This happens once. After that, the executable never needs to search for anything again; the answer is permanently baked in.

Java has no equivalent step. There is no linker. Nothing gets merged in advance. This single design choice is the root cause of two things covered next: why the filename rule exists, and why classes load the way they do at runtime.

### 5. Running — `java`, And Why The Filename Rule Exists

```bash
java HelloWorld
```

This starts the JVM. Because there's no linker to have already found `main` for you (unlike C, where the linker automatically locates `main` regardless of what any file is named), the JVM instead requires **you** to name the exact class to start with. It then needs to convert that name into an actual file, with zero ambiguity, in one step — no scanning, no guessing.

This is the actual reason the filename-must-match-classname rule exists: it guarantees that typing `java HelloWorld` always maps to exactly one file, `HelloWorld.class`, without the JVM ever having to open and inspect the contents of every `.class` file sitting in the folder to figure out which one has the class you meant. It's a deliberate design trade-off, not a technical necessity — C proves a language can work without any such rule, by handling the lookup entirely differently, at build time instead of run time.

The JVM's class loader opens **only** `HelloWorld.class`, loads it, and looks for `public static void main(String[] args)` — the fixed, required entry point. Execution begins there.

### 6. Lazy, On-Demand Class Loading

Execution proceeds instruction by instruction. Nothing else gets loaded until it's actually needed. When execution reaches `System.out.println(...)`:

- The class loader realizes `System` and `PrintStream` aren't loaded yet.
- It goes and loads `System.class` / `PrintStream.class` at that exact moment — these files live inside the JDK installation, not inside your program.
- Only now does the real, working `println` code enter memory and become available to run.

This can be proven directly: compiling two classes where one calls the other, then running with `-verbose:class`, shows the second class's load happening mid-execution — right after the first `println` fires, not before. Nothing is loaded "just in case." Everything loads lazily, exactly when first used.

This is the direct consequence of Java having no linker: instead of merging everything into one file before the program starts (C's approach), Java loads each class independently, live, while the program is already running.

### 7. Execution — Interpreting Or JIT-Compiling

The JVM now actually runs the loaded bytecode — both yours and the standard library's, no distinction between them at this point. It does this one of two ways:

- **Interpretation** — reads and carries out each bytecode instruction directly, live, one at a time. This is what happens for code that only runs once or a few times, like a simple Hello World.
- **JIT (Just-In-Time) compilation** — if a chunk of bytecode runs repeatedly (a loop executing thousands of times, for example), the JVM notices this and translates that specific part into real machine code — but only temporarily, in memory, for the duration of that run.

Critically, **nothing produced here is ever saved to disk.** Unlike C's `.exe`, which is built once and can be run again tomorrow without recompiling, every single run of a Java program starts fresh from `HelloWorld.class` and rebuilds whatever machine code it needs, live, from scratch, in memory only.

### 8. Output

`println`'s bytecode executes, making an OS-level system call to write to standard output. The terminal displays:

```text
Hello, World!
```

`main` finishes, the JVM shuts down, and everything loaded into memory during this run — your class, `System`, `PrintStream`, any JIT-compiled machine code — is discarded entirely.
