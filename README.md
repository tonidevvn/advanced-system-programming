# Advanced C Programming Repository

Hello 👋.
This repository contains sample C code covering key concepts and practical implementations for advanced C programming, Unix systems programming, and client-server communication. Each section focuses on a specific topic, providing both theoretical explanations and working examples.

## Table of Contents

1. [Advanced C Programming Techniques](#advanced-c-programming-techniques)
2. [Unix Input/Output](#unix-inputoutput)
3. [Process Management and Control](#process-management-and-control)
4. [Signals](#signals)
5. [Multithreading](#multithreading)
6. [Client-Server Applications](#client-server-applications)

---

## 1. Advanced C Programming Techniques

This section demonstrates advanced concepts in C programming, such as:

- **Dynamic Memory Management**: Examples using `malloc`, `calloc`, and `free`.
- **Function Pointers**: Implementing callback functions.
- **Bit Manipulation**: Operations for low-level programming.
- **File Handling**: Efficient reading and writing of files.

---

## 2. Unix Input/Output

Covers low-level Unix I/O system calls and file operations, including:

- **open, read, write, and close** system calls.
- **File Descriptors**: Working with `dup` and `dup2` for I/O redirection.

---

## 3. Process Management and Control

Illustrates process creation, termination, and management using:

- **Forking Processes**: Creating child processes with `fork()`.
- **Waiting for Processes**: Managing process termination with `wait()`.
- **exec Family**: Replacing process images with `execvp` and similar calls.

---

## 4. Signals

Explores Unix signal handling, including:

- **Signal Basics**: Sending and catching signals with `kill` and `signal`.
- **Signal Handlers**: Writing custom signal handlers.

---

## 5. Multithreading

Demonstrates thread creation and synchronization using POSIX threads:

- **Thread Basics**: Creating and joining threads with `pthread`.
- **Thread Synchronization**: Using mutexes, condition variables, and semaphores.
- **Thread Safety**: Writing thread-safe functions.

---

## 6. Client-Server Applications (Socket)

Presents examples of client-server communication using sockets:

- **TCP Server-Client**: Connection-oriented communication.
- **UDP Server-Client**: Connectionless communication.
- **Multithreaded Servers**: Handling multiple clients simultaneously.

---

## How to Run the Examples

1. Clone the repository:
   ```bash
   git clone https://github.com/tonidevvn/advanced-system-programming.git
   cd advanced-c-programming
   ```
2. Compile the desired file:
   ```bash
   gcc -o output_file filename.c -lpthread
   ```
3. Run the compiled executable:
   ```bash
   ./output_file
   ```

## Prerequisites

- A Unix-based system (Linux/Mac).
- GCC compiler installed.
- Basic understanding of C programming and Unix commands.
