add_library(GameObject
			"${CMAKE_CURRENT_SOURCE_DIR}/object.h"
			"${CMAKE_CURRENT_SOURCE_DIR}/object.cpp")

target_include_directories(GameObject PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ../Vector)

