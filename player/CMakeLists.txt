add_library(player
    "${CMAKE_CURRENT_SOURCE_DIR}/player.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/player.h"
)

target_link_directories(player PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ../GameObject)
