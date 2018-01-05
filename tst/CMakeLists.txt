#include files including headers in the src
include_directories(../src)
set(CMAKE_INCLUDE_CURRENT_DIR, ON)

file(GLOB TEST_SOURCES *.c)

enable_testing()

foreach(filename ${TEST_SOURCES})

	string(REGEX REPLACE ".*/" "" testname "${filename}" )
	string(REGEX REPLACE ".c" "" testname "${testname}" )

  add_executable(${testname} ${OBJECTS} ${filename})

	add_test(${testname} ${testname})
	message("${testname} ${filename}")

endforeach(filename)

add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} --verbose)
