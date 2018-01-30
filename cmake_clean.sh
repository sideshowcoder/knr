#!/bin/bash

printf "removing all generated files..."

#clean project folder
rm CMakeCache.txt -f
rm Makefile -f
rm CMakeFiles -rf
rm Testing -rf
rm cmake_install.cmake -f
rm CTestTestfile.cmake -f
rm compile_commands.json -f

#clean src folder
rm src/Makefile -f
rm src/CMakeFiles -rf
rm src/cmake_install.cmake -f
rm src/CTestTestfile.cmake -f
rm src/knr -f

#clean test folder
rm tst/Makefile -f
rm tst/CMakeFiles -rf
rm tst/cmake_install.cmake -f
rm tst/CTestTestfile.cmake -f
rm tst/Testing -rf

echo " done."
