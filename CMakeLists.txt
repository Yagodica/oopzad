cmake_minimum_required(VERSION 3.27)

project(oopzad VERSION 1.0
        DESCRIPTION "test"
        LANGUAGES CXX)



set(SOURCES
        zad7and8/book.cpp
        zad7and8/book.h
        zad7and8/main.cpp
        zad7and8/catalog_book.cpp
        zad7and8/catalog_book.h
)


add_executable(my_exe ${SOURCES})

