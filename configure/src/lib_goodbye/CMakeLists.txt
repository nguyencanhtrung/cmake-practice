add_library(lib_goodbye STATIC goodbye.cc)

target_include_directories(lib_goodbye PUBLIC 
    "./"
    "${CMAKE_BINARY_DIR}/configured_files/include/")