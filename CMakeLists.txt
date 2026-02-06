cmake_minimum_required(VERSION 4.1)
project(StudentGradeTracker)

set(CMAKE_CXX_STANDARD 20)

add_executable(StudentGradeTracker src/main.cpp
        include/calculation.h
        include/input.h
        include/storage.h
        src/calculation.cpp
        src/input.cpp
        include/input.h
        src/storage.cpp)
