# Variables and options in CMake

## Create variables

```cmake
set(LIB_NAME lib_hello)
```

CMAKE is smart enough, donot need to add quotion mark `"lib_hello"` to indicate `string`. We can pass number (`integer`) as values.

**Best practice**: set these variables in the top-level `CMakeLists.txt`.

## Important setup for CMAKE

```cmake
set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)
```

To ensure to use the same CPP Standard (C++11, C++14, C++17 ...) in all platforms, a good practice is to overwrite default setting `CMAKE_CXX_STANDARD` in `CMakeLists.txt`.

`CMAKE_CXX_STARDARD_REQUIRED`, when set to ON, it ensures that the compiler is required to support the specified standard. If the compiler does not support it, CMake will generate an error.

`CMAKE_CXX_EXTENSIONS`, when set OFF, only the features specified by the standard will be allowed, avoiding any compiler-specific extensions.

**Best practice**: It's recommended to define these variables for clarity in the project's build configuration and to ensure the expected behavior across different environments.

## Options

```cmake
option(COMPILE_EXECUTABLE "Whether to compile the executable" OFF)
```

Example:

```cmake
cmake_minimum_required(VERSION 3.20)
project(robot LANGUAGES CXX C VERSION 0.1.0)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

set(EXE_NAME exe)

option(COMPILE_EXECUTABLE "Whether to compile the executable" OFF)
add_subdirectory(src)

if (COMPILE_EXECUTABLE)
    add_subdirectory(app)
else()
    message(STATUS "Skipping the compilation of the executable")
endif()
```

### How to integrate it into CMake flow?

Change option value in project generation of CMake flow with `-D*` (No space then option-name)

```bash
cmake -DCOMPILE_EXECUTABLE=ON ..
```

## CMake cache

There is another way to change these option without embedded it into Command Lines.

`cmake ..` generates `CMakeCache.txt` which contains all variables, options to build a project. Hence, we just need to open and modify these options' value, then rebuild the project.

```cmake
...
CMAKE_VERBOSE_MAKEFILE:BOOL=FALSE

//Whether to compile the executable
COMPILE_EXECUTABLE:BOOL=ON

...
```
