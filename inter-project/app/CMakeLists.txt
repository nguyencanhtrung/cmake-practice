add_executable(exe main.cc)

# Link the library to executable target
target_link_libraries(exe PUBLIC lib_1)