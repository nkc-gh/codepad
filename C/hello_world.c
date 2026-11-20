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
    /// Write Hello World to the standard output stream.
    printf("Hello World\n");

    /// Report successful program completion to the operating system.
    return 0;
}