# Contributing

This file explains the rules for contributing code and documentation to this
repository.

## Commit Messages

Use this format for commit messages:

```text
<Action>: [<file or directory>]

<description of the change>

- 
- 
```

Use one of these actions:

| Action | Use |
| --- | --- |
| `Add` | Add a new file, document, program, or feature |
| `Update` | Change existing code or documentation |
| `Fix` | Correct a bug or incorrect behavior |
| `Remove` | Delete a file, program, or feature |

Examples:

```text
Add: [C/binary_search.c]

- Add binary search program in c.

Update: [C/README.md]

- Added compilation steps and flags.

Fix: [C/binary_search.c]

- Correct midpoint calculation to prevent integer overflow.

Remove: [C/old_program.c]

- Deleted unused example file.
```

**When changing multiple files in one commit , use this format :**

```text
Update: [C/binary_search.c, hello_world.c ; C++/README.md]

- Updated binary_search.c with overflow-safe midpoint calculation.
- Added Doxygen documentation in hello_world.c.
- Added compilation instructions in C++/README.md.
```

**Points to remember before committing:**

- Keep commits focused on one logical change.
- If changes are unrelated, separate them into different commits.
- Keep the first line short and descriptive; put additional explanation in the
  commit body.
- Use bullet points instead of long paragraphs when more detail is needed.
- Mention relevant tests or validation in the commit body.

## C and C++

### Naming Convention

Use snake_case for C and C++ filenames.

Examples:
1. `hello_world.cpp`
2. `add_two_numbers_hard_coded.cpp`
3. `hello_world.c`
4. `add_two_numbers_user_taken.c`

### Documentation

For comments in C and C++ files, use Doxygen-style comments.

#### Installing Doxygen

On Ubuntu or Debian, install Doxygen and the tools required to generate both
HTML and PDF documentation:

```bash
sudo apt update
sudo apt install doxygen make texlive-latex-base texlive-latex-extra
```

The packages provide:

- `doxygen` for reading documentation comments and generating documentation
- `make` for building the generated LaTeX files
- `texlive-latex-base` for the basic LaTeX system
- `texlive-latex-extra` for additional LaTeX packages used by Doxygen

Check that the tools are installed:

```bash
doxygen --version
pdflatex --version
make --version
```

Each command should print its installed version.

All C and C++ source files should use Doxygen-style comments. Doxygen reads
these comments and can generate documentation in formats such as HTML and
PDF.

Doxygen comments use either `/** ... */` or `///`.

#### Multi-line Doxygen comments

```cpp
/**
 * @file hello_world.cpp
 * @brief Prints a greeting to standard output.
 */
```

#### Single-line Doxygen comments

```cpp
/// @brief Prints a greeting to standard output.
```

Use the comment immediately before the file, function, class, or other item
that it documents.

#### Initial Tags

The following tags are currently used in this repository:

| Tag | Purpose |
| --- | --- |
| `@file` | Identifies the file being documented |
| `@brief` | Gives a short description |
| `@details` | Gives a longer explanation of the brief statement |
| `@return` | Describes a function's return value |

Example:

```cpp
/**
 * @file hello_world.c
 * @brief Prints "Hello World" to standard output.
 */

/// Provides declarations for standard input and output functions.
#include <stdio.h>

/**
 * @brief Starts the program and prints Hello World.
 *
 * @details
 * The program entry point writes Hello World to the standard output stream.
 * The `(void)` parameter list means that the function accepts no arguments.
 *
 * @return 0 when the program completes successfully.
 */
int main(void) {
    /// Writes Hello World to the standard output stream.
    printf("Hello World\n");

    /// Reports successful program completion to the operating system.
    return 0;
}
```

### Checking the Documentation

The following commands should be run from the repository root.

Create a Doxygen configuration file:

```bash
doxygen -g Doxyfile
```

Edit `Doxyfile` and set the input and output options:

```text
PROJECT_NAME = "Codepad"
INPUT = .
FILE_PATTERNS = *.c *.h *.cpp *.hpp *.cc *.cxx *.hxx
RECURSIVE = YES
OUTPUT_DIRECTORY = docs
GENERATE_HTML = YES
GENERATE_LATEX = YES
```

Generate the documentation:

```bash
doxygen Doxyfile
```

#### HTML documentation

Open the generated HTML documentation:

```bash
xdg-open docs/html/index.html
```

#### PDF documentation

Build the PDF from the generated LaTeX files:

```bash
cd docs/latex
make
```

The PDF is created at `docs/latex/refman.pdf`. Open it with:

```bash
xdg-open refman.pdf
```

The generated HTML and PDF documentation should contain the documented files
and descriptions from their Doxygen comments.

## DSA

When adding a Data Structures and Algorithms problem, follow the structure
below:

### Platform and File Organization

Place each problem in the directory for its specific platform. For example:

| Platform | Directory |
| --- | --- |
| Codeforces | `DSA/CodeForces/` |
| LeetCode | `DSA/LeetCode/` |

Add one problem per source file.

### File Naming

Use the following filename format:

```text
<problem-number>.<Problem_Name>.<extension>
```

The extension must match the language used for the solution. For example:

```text
DSA/LeetCode/1.Two_Sum.cpp
```

### Solution Structure

Every solution should follow this structure:

```text
Problem Metadata
(Difficulty, Date of Submission, Tags)
        ↓
Problem Statement
(Input, Output, Constraints, Examples)
        ↓
Solution Code
        ↓
Solution in My Words
        ↓
Complexity Analysis
```

### Validation

Preserve the function signature required by the online judge. Before
contributing, verify that the solution compiles and follows the expected
format for its platform.

## JavaScript

### Naming Convention

Use snake_case for JavaScript filenames.

Examples:
1. `hello_world.js`
2. `add_two_numbers_hard_coded.js`
3. `add_two_numbers_user_taken.js`

### Documentation

For comments in JavaScript files, use JSDoc-style comments.

#### Installing JSDoc

Install JSDoc globally or use it with `npx` via Node.js:

```bash
npm install -g jsdoc
```

Check that the tool is installed:

```bash
jsdoc --version
```

All JavaScript source files should use JSDoc-style comments where documentation
is needed. JSDoc reads these comments and can generate documentation in HTML
format.

JSDoc comments use `/** ... */`.

#### Multi-line JSDoc comments

```javascript
/**
 * @file hello_world.js
 * @description Prints a greeting to standard output.
 */
```

Use the comment immediately before the file, function, class, or other item
that it documents.

#### Initial Tags

The following tags are currently used in this repository:

| Tag | Purpose |
| --- | --- |
| `@file` | Identifies the file being documented |
| `@description` | Gives a detailed explanation of the file or function |
| `@param` | Describes a function parameter along with its `{type}` |
| `@returns` | Describes a function's return value along with its `{type}` |

Example:

```javascript
/**
 * @file hello_world.js
 * @description Prints "Hello World" to standard output.
 */

/**
 * Starts the program and prints Hello World.
 *
 * @description
 * The program entry point writes Hello World to the standard output / console.
 *
 * @returns {void}
 */
function main() {
    // Write Hello World to the standard output / console.
    console.log("Hello World");
}

// Execute the main program entry point.
main();
```

### Checking the Documentation

Run the following command from the repository root or the JavaScript directory:

```bash
npx jsdoc JavaScript/ -d docs/js
```

#### HTML documentation

Open the generated HTML documentation:

```bash
xdg-open docs/js/index.html
```

The generated HTML documentation will contain the documented files and
descriptions from their JSDoc comments.
