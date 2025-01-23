# CMake project configuration

This is a way to expose CMAKE project information to the program.

## **Step 1: Setup a header file with CMake placeholders**

In the folder `configured`, creating `config.hpp.in` to store generated options that we want to expose.

```cpp
static constexpr std::string_view project_name = "@CMAKE_PROJECT_NAME@";
static constexpr std::string_view project_version = "@CMAKE_PROJECT_VERSION@";

static constexpr std::uint32_t project_version_major{@CMAKE_PROJECT_VERSION_MAJOR@};
static constexpr std::uint32_t project_version_minor{@CMAKE_PROJECT_VERSION_MINOR@};
static constexpr std::uint32_t project_version_patch{@CMAKE_PROJECT_VERSION_PATCH@};
```

These 5 predefined variables are the most used. To know exact name of these placeholders, please view `CMakeCache.txt` file. These placeholders `@...@` will be replaced by actual values after generate the CMake project.

## **Step 2: Setup CMake to replace placeholders by actual values**

Creating `CMakeLists.txt` in the same folder containing following content:

```cmake
configure_file(
    "config.hpp.in"
    "${CMAKE_BINARY_DIR}/configured_files/include/config.hpp" ESCAPE_QUOTES
)
```

This script configures the file `config.hpp.in` by replacing the placeholders (e.g., `@...@`) with actual values defined in the CMake project. The resulting file is saved to `${CMAKE_BINARY_DIR}/configured_files/include/config.hpp`. The `ESCAPE_QUOTES` option ensures that any quotes in the input file are properly escaped in the output file.

## **Step 3: Integrate this into CMake flow**

Add the directory `configure` into CMake flow

```cmake
..
add_subdirectory(src)
add_subdirectory(configured)
..
```

To check these steps can be executed correctly, just need to run:

```bash
mkdir build
cd build
cmake ..
```

You can see the folder `configured_files` is generated as expectation

```bash
.
├── ..
├── configured_files
│   └── include
│       └── config.hpp
└── ..
```

If checking `config.hpp`, these placeholders are replaced by actual values which is setup in the top `CMakeLists.txt`

```cmake
project(robot LANGUAGES CXX C VERSION 0.1.0)
```

```cpp
#pragma once

#include <cstdint>
#include <string_view>

static constexpr std::string_view project_name = "robot";
static constexpr std::string_view project_version = "0.1.0";

static constexpr std::uint32_t project_version_major{0};
static constexpr std::uint32_t project_version_minor{1};
static constexpr std::uint32_t project_version_patch{0};

```

## **Step 4: Programming with this `config.hpp` header**

Just need to add the path of this header to any library linked to executable. Here is an example

```cmake
add_library(lib_goodbye STATIC goodbye.cc)

target_include_directories(lib_goodbye PUBLIC 
    "./"
    "${CMAKE_BINARY_DIR}/configured_files/include/")
```

Then, we can use these variables in our application.