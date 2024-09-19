project(day-1)

add_executable(day-1 source/main.cpp source/day_1.cpp)

target_include_directories(day-1
	PUBLIC
		include
)

target_link_libraries(day-1
	PUBLIC
		utilities
)
