cmake_minimum_required(VERSION 3.6)
project(DataStruct)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp exercise/LinkListMergeSort.cpp exercise/LinkListQuickSort.cpp graph/MetrixGraph.c)
add_executable(DataStruct ${SOURCE_FILES})