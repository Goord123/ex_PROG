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
        "Ficha 2/ex8.c"
        "Ficha 3/ex3.c"
        "Ficha 3/ex4.c"
        "Ficha 4/ex1.c"
        "Ficha 6/ex2.c"
        "Ficha 7/ex1.c"
        "Ficha 7/ex2.c"
        "Ficha 8/ex1.c"
        "Ficha 8/ex1.c"
        "Exames_Resolvidos/2223_Normal/1.c"
        "Ficha 11/ex2.c"
        "Ficha 11/ex3.c"
        Exames_Resolvidos/2223_Normal/2.c
        Exames_Resolvidos/2223_Normal/3.c
        Exames_Resolvidos/2122_Normal/1.c
)
