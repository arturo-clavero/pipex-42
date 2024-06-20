# Pipex

## Table of Contents
- [Introduction](#introduction)
- [Installation](#installation)
- [Features](#features)
- [Skills Learnt](#skills-learnt)
- [Requirements](#requirements)

## Introduction
Pipex is a project developed for 42 School that involves creating a simplified version of the Unix pipeline. It aims to deepen your understanding of process creation, inter-process communication, and file descriptor manipulation in Unix-like operating systems.

## Installation
To install and compile the Pipex project, follow these steps:

1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/pipex.git
   cd pipex
   ```
2. Compile project:
   ```sh
    make
   ```
3. Run program:

    The general syntax is as follows:
     ```sh
     ./pipex file1 cmd1 cmd2 file2
     ```
    This example reads from file named "infile.txt", runs grep '42', then wc -l, and writes the output to file named "outfile.txt".
     ```sh
     ./pipex infile.txt "grep '42'" "wc -l" outfile.txt
     ```

## Features
* Simulates a Unix pipeline with multiple (two or more) commands.
* Handles file input and output redirection.
* Demonstrates the use of pipe(), fork(), dup2(), and execve() system calls.

## Skills learnt
* **Process Management:** Creating and managing processes using fork().
* **Inter-Process Communication:** Using pipe() to enable communication between processes.
* **File Descriptor Manipulation:** Redirecting input and output using dup2().
* **System Calls:** Executing commands with execve().

## Requirements
* A Unix-like operating system (macOS or Linux).
* GCC or Clang compiler.
* Make utility.
