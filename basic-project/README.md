# Basic project structure

## Create executable target

```cmake
# CMakeLists.txt
add_executable(exe main.cc)
```

## Create others target aside from executable (libraries)

```cmake
# CMakeLists.txt
add_library(lib_1 STATIC my_lib.cc)
```

Then, we have to link the library target to executable target to make it compile successfully.

```cmake
target_link_libraries(exe PUBLIC lib_1)
```

## How to compile single target with cmake

```bash
cmake --build . --target lib_1
cmake --build . --target exe        #Note: this will auto compile dependencies target such as library
```

## Difference between STATIC vs SHARED
