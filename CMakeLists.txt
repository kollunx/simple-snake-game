cmake_minimum_required(VERSION 3.25)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src/graphics)
add_subdirectory(src/game_logic)
add_subdirectory(src/game)

enable_testing()
add_subdirectory(tests)
