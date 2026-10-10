# Task Manager (C++)

A command-line task manager written in C++17. Tasks are saved to a file, so they are still there when you close and reopen the program.

## Features

- Add, list, complete, and delete tasks
- Tasks are saved automatically to a file and loaded on startup
- Input validation, so typing letters instead of numbers does not crash the program

## Built with

- C++17
- Standard library only (vector, string, fstream)

## How to build and run

You need a C++ compiler such as g++. Then run:

    git clone https://github.com/umedaraimabasi-debug/task-manager.git
    cd task-manager
    g++ -std=c++17 src/main.cpp -o taskmanager
    ./taskmanager

## Example

    1. Add task
    2. List tasks
    3. Complete task
    4. Delete task
    5. Quit
    > 1
    Title: Learn C++
    > 2
    1. [ ] Learn C++

## What I learned

- Structuring data with structs and std::vector
- Reading and writing files with fstream
- Validating user input safely
- Using Git and GitHub for version control

## Planned improvements

- Split the code into separate files and classes
- Add priorities and due dates
- Add unit tests
