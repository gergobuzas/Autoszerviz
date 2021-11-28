cmake_minimum_required(VERSION 3.20)
project(Autoszerviz C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Autoszerviz
        database.c
        database.h
        debugmalloc.h
        econio.c
        econio.h
        functions.c
        functions.h
        main.c
        menu.c
        menu.h)
