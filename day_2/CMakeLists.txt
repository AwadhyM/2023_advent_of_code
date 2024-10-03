project(day-2)

add_executable(day-2 source/main.cpp source/day_2.cpp)

target_include_directories(day-2
	PUBLIC
		include
)

target_link_libraries(day-2
	PUBLIC
		utilities
)
