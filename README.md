# Composer Database Engine

A lightweight, file-based database engine written in C++. This project implements a simple in-memory database with persistent storage capabilities.

## Overview

This database engine provides a straightforward way to store, retrieve, and manage information. It features an in-memory data structure with file persistence, making it suitable for small to medium-sized datasets.

## Project Structure

```
Database/
├── infomation.h         # Composer class declaration
├── infomation.cpp       # Composer class implementation
├── database.h           # Database class declaration
├── database.cpp         # Database class implementation
├── data/
│   └── data.frm        # Database storage file
├── test/
│   ├── testDatabase.cpp    # Database test cases
│   └── testInformation.cpp  # Information test cases 
└── README.md           # This file
```

## Classes

### Composer Class

Represents an individual composer with the following attributes:

- **ID**: Unique identifier (auto-assigned)
- **First Name**: Composer's first name
- **Last Name**: Composer's last name
- **Age**: Composer's age
- **Email**: Composer's email address

#### Methods

- `setFirstName(string)` / `firstName()`: Set/get first name
- `setLastName(string)` / `LastName()`: Set/get last name
- `setAge(int)` / `age()`: Set/get age
- `setEmail(string)` / `email()`: Set/get email
- `setId(int)` / `id()`: Set/get ID
- `display()`: Display composer information

### Database Class

Manages a collection of composer records with the following operations:

#### Methods

- `AddComposer(firstName, lastName, age, email)`: Add a new composer to the database
- `getComposer(lastName)`: Retrieve a composer by last name
- `displayAll()`: Display all composers in the database
- `write()`: Persist database to file

## Prerequisites

- C++ compiler with C++11 support (g++, clang++, MSVC)
- Standard C++ library
- CMake 3.10 or higher (optional, but recommended)

## Building the Project

### Option 1: Using CMake (Recommended)

CMake provides a cross-platform build system that works on Windows, Linux, and macOS.

```bash
# Configure the build (first time or when CMakeLists.txt changes)
cmake -B build

# Build the project
cmake --build build

# Run tests
cd build && ctest --verbose
```

Or on Windows with PowerShell:
```powershell
# Configure and build
cmake -B build
cmake --build build

# Run tests
cd build; ctest --verbose
```

The executables will be in the `build` directory (or `build/Debug` on Windows with MSVC).

### Option 2: Manual Compilation

If you prefer not to use CMake, you can compile manually:

```bash
# Using g++
g++ -o test/testDatabase test/testDatabase.cpp database.cpp infomation.cpp -std=c++11

# Using clang++
clang++ -o test/testDatabase test/testDatabase.cpp database.cpp infomation.cpp -std=c++11

# On Windows with MSVC
cl /EHsc /Fetest\testDatabase.exe test\testDatabase.cpp database.cpp infomation.cpp
```

## Future Enhancement

- Working on implamenting a deletion method 
- Working on creating a query scripts


## License

This project is under the MIT License. See [LICENSE](https://github.com/JJC3321/Database-Engine?tab=MIT-1-ov-file) for more information.

