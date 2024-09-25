cmake_minimum_required(VERSION 3.29)
project(Ayudantia69)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ayudantia69 main.cpp
        MaterialBibliografico.cpp
        Libro.h
        Libro.cpp
        Revista.h
        Revista.cpp
        Usuario.h
        Usuario.cpp
        Sistema.h
        Sistema.cpp)
