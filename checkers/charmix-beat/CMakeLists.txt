cmake_minimum_required(VERSION 3.28)

project(charmix-beat)

add_executable(charmix-beat checker.cpp)

include_directories(../testlib/)