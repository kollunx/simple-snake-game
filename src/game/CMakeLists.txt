add_executable(game)

target_sources(game
  PRIVATE
    main.cpp
    Game.cpp
    GameState.cpp
    GameplayState.cpp
)

target_link_libraries(game
  PRIVATE
    game_logic
    graphics
    SDL2::SDL2main
)
