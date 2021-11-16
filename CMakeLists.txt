cmake_minimum_required(VERSION 3.13)

project(NengishTranslator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

if (UNIX AND NOT APPLE)
    set(CMAKE_EXECUTABLE_SUFFIX ".out")
endif()

if (MSVC)
    add_compile_options(/Wall)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

add_executable(nengish-translator)

add_subdirectory(Sources)