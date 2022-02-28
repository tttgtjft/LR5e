cmake_minimum_required(VERSION 3.20)
project(lR5e C)

set(CMAKE_C_STANDARD 11)

add_executable(lR5e main.c)

add_library(str string/string_.h string/string_.c)

target_link_libraries(lR5e str)

