# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.

project(AdventOfCode2020)
cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 20)

add_executable(aoc2020 main.cpp macros day1.cpp day1.hpp day2.cpp day2.hpp day3.cpp day3.hpp day5 day4.cpp day4.hpp day6.cpp day6.hpp macros.cpp day5.cpp)