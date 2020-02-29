cmake_minimum_required(VERSION 3.15)
project(Assignment_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment_2
        interpreter.c
        interpreter.h
        shell.c
        shellmemory.c
        shellmemory.h
        testfile.txt kernel.c cpu.c pcb.c ram.c shell.h ram.h pcb.h)
