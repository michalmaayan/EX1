cmake_minimum_required(VERSION 3.8)
project(EX1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES osm.cpp osm.h)
add_executable(EX1 ${SOURCE_FILES})