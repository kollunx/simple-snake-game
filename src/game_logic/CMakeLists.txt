add_library(game_logic)

target_sources(game_logic
  PRIVATE
    Snake.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS .
    FILES
      Snake.h
)
