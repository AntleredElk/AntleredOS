cmake_minimum_required(VERSION 3.15)
project(Assignment_2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Assignment_2
        cpu.c
        cpu.h
        interpreter.c
        interpreter.h
        kernel.c
        kernel.h
        pcb.c
        pcb.h
        ram.c
        ram.h
        shell.c
        shell.h
        shellmemory.c
        shellmemory.h)
