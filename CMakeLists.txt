cmake_minimum_required(VERSION 3.15)
project(lab_11)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(lab_11 main.cpp src/employees.cpp include/employees.h)