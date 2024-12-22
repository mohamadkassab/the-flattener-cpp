# The Flattener

**Programming Language**: C++

## Purpose

The main goal of this project is to process and transform a nested JSON object into a flat JSON object by iterating over all its components.

## Key Features

- **JSON Iteration**: Efficient traversal of JSON structures regardless of their depth or complexity.
- **Transformation**: Converts a deeply nested JSON object into a single-level flat structure.
- **Multiple Compiler Support**: Tested with both the Visual Studio default compiler and `g++` for performance comparison.

## Performance Benchmarks

### Using the Visual Studio Default Compiler:

- A JSON object with **10,000 fields**: **100 seconds**
- A JSON object with **20,000 fields**: **300 seconds**
- A JSON object with **100,000 fields**: **500 seconds**

### Using the `g++` Compiler:

- A JSON object with **10,000 fields**: **1.7 seconds**
- A JSON object with **20,000 fields**: **7.7 seconds**
- A JSON object with **100,000 fields**: **25 seconds**

## Technology Highlights

- **C++ Programming**: Offers object-oriented features and abstractions, reducing the need for additional error-handling code compared to C.
- **Library Management**: Leveraged **vcpkg** to install and manage required libraries efficiently.
- **Build System**: Used **CMake** to streamline the project build process with the `g++` compiler.

## Advantages

- **Simplified Code**: C++ provides more abstractions, reducing the need for additional boilerplate code compared to C.

## Disadvantages

- **Performance Variability**: While the code is simpler and more maintainable, it may be slower than the C version, especially when using certain compilers.
