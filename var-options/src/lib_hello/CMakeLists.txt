add_library(lib_hello STATIC hello.cc)

target_include_directories(lib_hello PUBLIC "./")