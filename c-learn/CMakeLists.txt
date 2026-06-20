cmake_minimum_required(VERSION 3.23)
project(c-learn VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(SOURCES
    src/main.c
    src/person.c
	src/car.c
	src/linkedlist.c
	src/logging.c
	src/binarytree.c
)

add_executable(main ${SOURCES})

target_include_directories(main PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)