set(CMAKE_INCLUDE_CURRENT_DIR, ON)

file(GLOB_RECURSE SOURCES *.c)

# Seperate object files from sources
foreach(filename ${SOURCES})
	if("${filename}" MATCHES "main.c")

	else("${filename}" MATCHES "main.c")
		list(APPEND OBJECTS ${filename})
	endif("${filename}" MATCHES "main.c")
endforeach(filename ${SOURCES})

add_executable(knr ${SOURCES})
