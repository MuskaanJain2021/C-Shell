# C-Shell: A Custom UNIX Command-Line Interpreter in C

A lightweight, portable UNIX shell built from scratch in C, demonstrating core concepts of operating systems including process management, system calls, and memory handling.

-----

## About The Project

This project is a fully functional command-line interpreter that mimics the core behavior of shells like `bash` or `zsh`. It was developed to apply and deepen understanding of low-level systems programming. The shell can parse user input, execute system commands, and handle built-in functions, making it a robust example of C programming in a systems context.

-----

## Technical Skills Showcase

This project demonstrates proficiency in:

  * **C Programming**: Implemented using modern, clean C (C11 standard) with a focus on memory safety and portability.
  * **Operating Systems Concepts**:
      * **Process Management**: Utilizes `fork()` and `execvp()` to create and manage child processes for command execution.
      * **System Calls**: Interacts directly with the kernel using calls like `chdir()`, `waitpid()`, and `signal()` for core functionality.
      * **Signal Handling**: Implements custom handlers for `SIGINT` (Ctrl-C) to ensure shell stability.
  * **Memory Management**: Employs dynamic memory allocation (`malloc`, `realloc`, `free`) for efficient handling of commands and arguments of any length.
  * **Software Design**: Structured with a modular, multi-file architecture (parser, executor, shell core) and documented with Doxygen for maintainability.

-----

## Features

  * **Command Execution**: Runs any command located in the system's `$PATH`.
  * **Built-in Commands**:
      * `cd`: Changes the current directory.
      * `exit`: Terminates the shell.
  * **Robust I/O**: Reads user input of any length using `getline()`.
  * **Dynamic Argument Handling**: Parses command lines with a variable number of arguments.

-----

## Installation & Usage

### Prerequisites

  * A C compiler (e.g., GCC)
  * A UNIX-like environment (Linux, macOS)

### Build Instructions

1.  **Clone the repository:**
    ```sh
    git clone https://github.com/your-username/your-repo-name.git
    cd your-repo-name
    ```
2.  **Compile the source code:**
    ```sh
    gcc -Wall -Wextra -std=c11 -o my_shell main.c shell.c parser.c execute.c
    ```

### Running the Shell

1.  **Execute the compiled program:**
    ```sh
    ./my_shell
    ```
2.  **Start using the shell:**
    ```sh
    x > ls -l
    x > pwd
    x > exit
    ```

-----

## Project Structure

The project is organized into logical modules for clarity and separation of concerns:

  * `main.c`: Entry point of the program.
  * `shell.c` / `shell.h`: Core REPL (Read-Eval-Print Loop) and signal handling.
  * `parser.c` / `parser.h`: Functions for tokenizing user input into commands and arguments.
  * `execute.c` / `execute.h`: Logic for executing built-in and external commands.
