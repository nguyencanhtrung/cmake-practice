add_executable(${EXE_NAME} main.cc)

target_link_libraries(exe PUBLIC lib_hello)
target_link_libraries(exe PUBLIC lib_goodbye)