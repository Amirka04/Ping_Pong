add_library(Ball
    "${CMAKE_CURRENT_SOURCE_DIR}/Ball.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/Ball.cpp"
)

target_include_directories(Ball PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
