add_library(Vector
			"${CMAKE_CURRENT_SOURCE_DIR}/Vector.h"
			"${CMAKE_CURRENT_SOURCE_DIR}/Vector.cpp"
		)

target_include_directories(Vector PUBLIC  "${CMAKE_CURRENT_SOURCE_DIR}")
