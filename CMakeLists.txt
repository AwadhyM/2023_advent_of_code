cmake_minimum_required(VERSION 3.15)

project(advent-of-code-2023)

add_library(utilities utils/source/utils.cpp)

target_include_directories(utilities
	PUBLIC
		utils/include)
