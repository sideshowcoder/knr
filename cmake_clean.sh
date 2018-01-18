#!/bin/bash

#clean project folder
rm CMakeCache.txt
rm Makefile
rm CMakeFiles -rf
rm Testing -rf
rm cmake_install.cmake
rm CTestTestfile.cmake 2> /dev/null

#clean src folder
rm src/Makefile
rm src/CMakeFiles -rf
rm src/cmake_install.cmake
rm src/CTestTestfile.cmake 2> /dev/null
rm src/knr

#clean test folder
rm tst/Makefile
rm tst/CMakeFiles -rf
rm tst/cmake_install.cmake
rm tst/CTestTestfile.cmake 2> /dev/null
rm tst/Testing -rf
