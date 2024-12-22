cmake_minimum_required(VERSION 3.10)

# Set the C and C++ compilers
set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin")

# Set the project name
project(TheFlattener)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add include directories
include_directories("C:/Users/mhmdk/Desktop/Projects/vcpkg-master/vcpkg-master/installed/x64-windows/include")

# Add the executable
add_executable(TheFlattener-C++ TheFlattener-C++.cpp)
