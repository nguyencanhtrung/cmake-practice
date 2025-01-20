# Getting started with CMake

## Generating a Project with CMAKE

1. Create source and CMakeLists.txt
2. $ mkdir build
3. $ cd build
4. $ cmake ..         - Generating the build files and configure the project
5. $ cmake --build .  - Building project
6. Run the app with $ ./exe

### Alternatives way to generate build project

```bash
cd build
cmake -S .. -B .   # Option 1
cmake ..           # Option 2
```

Syntax:

```bash
cmake -S  <path-to-source> -B <path-to-build>
```

After that, you can update the generated project with

```bash
cd build
cmake .
```

### Generate a Project with specified generator

```bash
cd build
cmake -S .. -B . -G "Unix Makefiles"    #Option 1
cmake .. -G "Unix Makefiles"            #Option 2
```

Get the list of generators

```bash
cmake --help
```

```bash
Generators

The following generators are available on this platform (* marks default):
  Green Hills MULTI            = Generates Green Hills MULTI files
                                 (experimental, work-in-progress).
* Unix Makefiles               = Generates standard UNIX makefiles.
  Ninja                        = Generates build.ninja files.
  Ninja Multi-Config           = Generates build-<Config>.ninja files.
  Watcom WMake                 = Generates Watcom WMake makefiles.
  CodeBlocks - Ninja           = Generates CodeBlocks project files
                                 (deprecated).
  CodeBlocks - Unix Makefiles  = Generates CodeBlocks project files
                                 (deprecated).
  CodeLite - Ninja             = Generates CodeLite project files
                                 (deprecated).
  CodeLite - Unix Makefiles    = Generates CodeLite project files
                                 (deprecated).
  Eclipse CDT4 - Ninja         = Generates Eclipse CDT 4.0 project files
                                 (deprecated).
  Eclipse CDT4 - Unix Makefiles= Generates Eclipse CDT 4.0 project files
                                 (deprecated).
  Kate - Ninja                 = Generates Kate project files (deprecated).
  Kate - Ninja Multi-Config    = Generates Kate project files (deprecated).
  Kate - Unix Makefiles        = Generates Kate project files (deprecated).
  Sublime Text 2 - Ninja       = Generates Sublime Text 2 project files
                                 (deprecated).
  Sublime Text 2 - Unix Makefiles
                               = Generates Sublime Text 2 project files
                                 (deprecated).
```

### Specify build type

By default, the standard type is in most cases the debug type. If you want to generate the project, for example, in release mode you have to set the build type.

```bash
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
```

### Passing options

If you have set some options in the CMakeLists, you can pass values in the command line.

```bash
cd build
cmake -DMY_OPTION=[ON|OFF] ..
```
