cmake_minimum_required(VERSION 3.27)

project(oopzad VERSION 1.0
        DESCRIPTION "test"
        LANGUAGES CXX)



set(SOURCES zad5and6/src/Canvas.cpp zad5and6/zad5.cpp zad5and6/include/Canvas.h)

add_executable(my_exe ${SOURCES})

