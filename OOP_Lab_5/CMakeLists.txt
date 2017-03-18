cmake_minimum_required(VERSION 3.6)
project(OOP_Lab_5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    OOP_Lab_5/Figure.h
    OOP_Lab_5/Hexagon.cpp
    OOP_Lab_5/Hexagon.h
    OOP_Lab_5/Iterator.h
    OOP_Lab_5/main.cpp
    OOP_Lab_5/NTree.h
    OOP_Lab_5/NTreeNode.h
    OOP_Lab_5/Octagon.cpp
    OOP_Lab_5/Octagon.h
    OOP_Lab_5/Triangle.cpp
    OOP_Lab_5/Triangle.h)

add_executable(OOP_Lab_5 ${SOURCE_FILES})