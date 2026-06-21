cmake_minimum_required(VERSION 3.23)
project(cpp-learn VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

foreach(CONFIG Debug Release RelWithDebInfo MinSizeRel)
    string(TOUPPER ${CONFIG} CONFIG_UPPER)

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CONFIG_UPPER}
        ${CMAKE_SOURCE_DIR}/out/${CONFIG}/bin)

    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${CONFIG_UPPER}
        ${CMAKE_SOURCE_DIR}/out/${CONFIG}/lib)

    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${CONFIG_UPPER}
        ${CMAKE_SOURCE_DIR}/out/${CONFIG}/obj)
endforeach()

set(SOURCES
    src/main.cpp
    src/Person.cpp
)

add_executable(main ${SOURCES})

target_include_directories(main PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)