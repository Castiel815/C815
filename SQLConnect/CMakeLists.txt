cmake_minimum_required(VERSION 3.30)
project(sqlConnect)

set(CMAKE_CXX_STANDARD 17)

add_library(sqlConnect SHARED library.cpp)
