cmake_minimum_required(VERSION 3.19)
project(Hash_table C)

set(CMAKE_C_STANDARD 11)
include_directories(include)

add_compile_options(
        -Werror

        -Wall
        -Wextra
        -Wpedantic

        -Wcast-align
        -Wcast-qual
        -Wconversion
        -Wenum-compare
        -Wfloat-equal
        -Wredundant-decls
        -Wsign-conversion
)

add_executable(Hash_table tests/main.c tests/tests.c src/hash_table.c tests/tests.h include/hash_table.h)