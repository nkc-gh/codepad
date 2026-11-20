/**
 * @file hello_world.cpp
 * @brief Prints "Hello, World!" to standard output.
 */

/// Provides std::cout for console output.
#include <iostream>

/**
 * @brief Starts the program and prints a greeting.
 *
 * @details
 * The program entry point writes Hello, World! to the standard output stream.
 * The empty parameter list means that the function accepts no arguments.
 *
 * @return 0 when the program completes successfully.
 */
int main() {
    /// Writes Hello, World to standard output.
    std::cout << "Hello, World!\n";

    /// Report successful program completion to the operating system.
    return 0;
}