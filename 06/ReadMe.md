# Project Readme

This project contains two tasks: Task1 and Task2. Follow the instructions below to build and run them.

## Task 1

Task 1 can be built and run directly using the CMakeLists file provided in the project.

### Build and Run Task 1

1. Make sure you have CMake and a C++ compiler installed on your system.
2. Navigate to the project directory.
3. Create a build directory and navigate to it:

   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ./Task1

# Task 2

Task 2 can be built and run inside a Docker container, especially if you are using Windows.

## Build and Run Task 2 (Using Docker on Windows)

1. Make sure you have Docker installed on your Windows system.

2. Open a command prompt or terminal and navigate to the project directory.

3. Build the Docker image for Task 2:

   ```bash
   docker-compose build
   docker-compose up

4. Or just normally if you have boost installed:
     ```bash
   mkdir build
   cd build
   cmake ..
   make
   ./Task1```
   
