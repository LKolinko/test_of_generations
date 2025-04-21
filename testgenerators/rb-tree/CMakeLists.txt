cmake_minimum_required(VERSION 3.28)

project(rb-tree)

add_executable(rb-tree gen.cpp)

include_directories(../testlib/)