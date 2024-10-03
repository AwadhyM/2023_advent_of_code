cmake_minimum_required(VERSION 3.15)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
SET(CMAKE_CXX_FLAGS "-std=c++20")

project(advent-of-code-2023)

add_library(utilities utils/source/utils.cpp)

target_include_directories(utilities
	PUBLIC
		utils/include)

add_subdirectory(day_1)
add_subdirectory(day_2)
