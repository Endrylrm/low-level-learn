cmake_minimum_required(VERSION 3.23)
project(cpp-learn VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/main.cpp
    src/Person.cpp
)

add_executable(main ${SOURCES})

target_include_directories(main PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)