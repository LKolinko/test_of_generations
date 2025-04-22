cmake_minimum_required(VERSION 3.28)

project(pnp)

add_executable(pnp validator.cpp)

include_directories(../testlib/)