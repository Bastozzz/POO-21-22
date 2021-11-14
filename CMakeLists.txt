cmake_minimum_required(VERSION 3.20)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled main.cpp
        src/Recurso.cpp inc/Recurso.h
        src/Ferro.cpp inc/Ferro.h
        src/Edificio.cpp inc/Edificio.h
        src/Menus.cpp inc/Menus.h
        src/Ilha.cpp inc/Ilha.h
        src/MinaFerro.cpp inc/MinaFerro.h
        src/Mineiro.cpp inc/Mineiro.h
        src/Trabalhador.cpp inc/Trabalhador.h
        src/Zona.cpp inc/Zona.h
        inc/utils.h)
