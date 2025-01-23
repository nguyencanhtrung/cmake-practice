cmake_minimum_required(VERSION 3.20)

project(robot LANGUAGES CXX C VERSION 0.1.0)

# Overwrite the default CMAKE_INSTALL_PREFIX
set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)


# Setup variables
set(LIB1_NAME lib_hello)
set(EXE_NAME exe)

option(COMPILE_EXECUTABLE "Whether to compile the executable" OFF)

add_subdirectory(src)

if (COMPILE_EXECUTABLE)
    add_subdirectory(app)
else()
    message(STATUS "Skipping the compilation of the executable")
endif()
