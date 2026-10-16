#ifndef GAME_H
#define GAME_H

#include "GameState.h"
#include "Renderer.h"
#include "Window.h"
#include <SDL2/SDL.h>
#include <memory>

class GameState;
class Renderer;

constexpr const char *gameTitle = "Snake Game";
constexpr int windowWidth = 500;
constexpr int windowHeight = 500;

class Game {
private:
  Window m_window;
  Renderer m_renderer;
  bool m_isRunning{};
  std::unique_ptr<GameState> m_gameState;

public:
  explicit Game();
  Game(const Game &) = delete;
  Game(Game &&) = delete;
  Game &operator=(const Game &) = delete;
  Game &operator=(Game &&) = delete;

  void handleEvents();
  void update();
  void draw();
  bool isRunning() const noexcept { return m_isRunning; }
  void quit() noexcept { m_isRunning = false; }

  void changeGameState(std::unique_ptr<GameState> gameState) { m_gameState = std::move(gameState); }

  void changeLogicScreen(Screen screen) { m_renderer.setScreen(screen); }

  ~Game();
};

#endif
