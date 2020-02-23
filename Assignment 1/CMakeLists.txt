cmake_minimum_required(VERSION 3.15)
project(Assignment1 C)

set(CMAKE_C_STANDARD 99)

add_executable(Assignment1 shell.c interpreter.c shellmemory.c interpreter.h shellmemory.h shell.h)