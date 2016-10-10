cmake_minimum_required(VERSION 3.6)
project(DataStruct)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES tree/BinaryTreeTest.cpp algorithm/LinkListMergeSort.cpp algorithm/LinkListQuickSort.cpp graph/MetrixGraphTest.c graph/AdjacencyListGraphTest.c)
add_executable(DataStruct ${SOURCE_FILES})