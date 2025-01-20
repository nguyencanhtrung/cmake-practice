# Intermediate project structure

Now the project structure will be separated into libraries stored in `src` and applications stored in `app`. The `CMake` flow also need to be adjusted to compile the project successfully.

## What need to do more?

Correcting the path to targets

```cmake
add_library(library STATIC src/my_lib1/my_lib.cc)
add_executable(exe app/main.cc)
```

But, it is not enough since compiling it prompts error

```bash
[ 75%] Building CXX object CMakeFiles/exe.dir/app/main.cc.o
/media/tesla/Data/training/cmake/cmake-practice/inter-project/app/main.cc:3:10: fatal error: my_lib.h: No such file or directory
    3 | #include "my_lib.h"
      |          ^~~~~~~~~~
compilation terminated.
gmake[2]: *** [CMakeFiles/exe.dir/build.make:76: CMakeFiles/exe.dir/app/main.cc.o] Error 1
gmake[1]: *** [CMakeFiles/Makefile2:111: CMakeFiles/exe.dir/all] Error 2
gmake: *** [Makefile:91: all] Error 2
```

How to fix?

Adding this line into the `CMakeLists.txt` file.

```cmake
target_include_directories(lib_1 PUBLIC "src/my_lib1")
```

## Best practices

It is not good to change the directory path in the main `CMakeLists.txt`. What we SHOULD do is as the following:

1. Create `CMakeLists.txt` in each directories.
2. Moving `add_*` into these `CMakeLists.txt`
3. Moving `target_link_libraries*` into `app` directory
4. In the main `CMakeLists.txt` add subdirectories with `add_subdirectory(src)` and `add_subdirectory(app)`. Note: dependencies must be defined first.
5. In the `CMakeLists.txt` of the dependencies, must specify `target_include_directories(lib_1 PUBLIC "./")` to indicate include directories for compilation

## Important notes

* Dependencies MUST be added with `add_subdirectory()` first
* A target must be added before its includes