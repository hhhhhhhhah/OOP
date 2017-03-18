cmake_minimum_required(VERSION 3.6)
project(OOP_Lab_4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    OOP_Lab_4/Figure.h
    OOP_Lab_4/Hexagon.cpp
    OOP_Lab_4/Hexagon.h
    OOP_Lab_4/main.cpp
    OOP_Lab_4/NTree.h
    OOP_Lab_4/NTreeNode.h
    OOP_Lab_4/Octagon.cpp
    OOP_Lab_4/Octagon.h
    OOP_Lab_4/Triangle.cpp
    OOP_Lab_4/Triangle.h)

add_executable(OOP_Lab_4 ${SOURCE_FILES})