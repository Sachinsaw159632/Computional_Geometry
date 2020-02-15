cmake_minimum_required(VERSION 3.15)
project(comGeo)

set(CMAKE_CXX_STANDARD 14)

add_executable(comGeo main.cpp line.h point.h point.cpp line.cpp vec.h vec.cpp circle.h circle.cpp triangle.h triangle.cpp polygon.h polygon.cpp)