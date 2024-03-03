cmake_minimum_required(VERSION 3.27)
project(ex_PROG C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ex_PROG
        "Ficha 1/ex1.c"
        "Ficha 1/ex2.c"
        "Ficha 1/ex3.c"
        "Ficha 2/ex1.c"
        "Ficha 2/ex2.c"
        "Ficha 2/ex3.c"
        "Ficha 2/ex6.c"
        "Ficha 2/ex8.c")
