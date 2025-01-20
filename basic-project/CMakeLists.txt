cmake_minimum_required(VERSION 3.28)

project(basic-project VERSION 1.0.0 LANGUAGES C CXX)

# Define the library target
add_library(lib_1 STATIC my_lib.cc)

# Define the executable target
add_executable(exe main.cc)

# Link the library to executable target
target_link_libraries(exe PUBLIC lib_1)