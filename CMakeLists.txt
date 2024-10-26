cmake_minimum_required(VERSION 3.10)


project(FileRenamer VERSION 1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

include_directories(include)


file(GLOB SOURCES "*.c")

set(SOURCES
main.c
option/option.c
sort/sort.c
opener/opener.c

)

add_executable(FileRenamer ${SOURCES})
