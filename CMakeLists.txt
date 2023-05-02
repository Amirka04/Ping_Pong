cmake_minimum_required(VERSION 3.0)

project(ping_pong)


find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)


# Подключу папку
add_subdirectory(Vector)
add_subdirectory(GameObject)
add_subdirectory(player)
add_subdirectory(Ball)


add_executable(ping_pong main.cpp)



target_link_libraries(ping_pong player GameObject Vector Ball)
target_link_libraries(ping_pong sfml-graphics sfml-window sfml-system GL)

