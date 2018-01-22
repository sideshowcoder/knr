# KNR Excercises

Setup for CMake and Clang adapted
from [cmake-boilerplate](https://github.com/arunoda/cmake-boilerplate)

## Ubuntu

install cmake, llvm and clang

## Build

```
$ cmake . && make
```

## Test

Is done via minunit

```
$ cmake . && make && make check
```

use `make check` for verbose output `make test` to get a simple fail or success.


## Getting irony-mode to fine the headers

Irony will not by default pickup the `knr.h` header when looking at
`knr_tests.c` to make this work cmake needs to output a `compile_commands.json`
in the root.

```
$ cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .
```

in the root of the project will do that, this likely does not need to be rebuild
often.

## Compileing with Debug Symbols

Debug information is not included by default to compile with debug symbols. 

For using [LLDB see this gist](https://gist.github.com/gregmalcolm/9042234)
and [LLDB Tutorial](https://lldb.llvm.org/tutorial.html).

