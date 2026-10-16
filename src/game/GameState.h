#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <memory>

class Game;
struct Screen;
class Renderer;

class GameState {
public:
  explicit GameState(Game &game, Screen screen);
  GameState(const GameState &) = delete;
  GameState(GameState &&) = delete;
  GameState &operator=(const GameState &) = delete;
  GameState &operator=(GameState &&) = delete;

  virtual ~GameState() = default;

  virtual void handleEvents() = 0;
  virtual void update() = 0;
  virtual void draw(Renderer &renderer) = 0;

protected:
  void changeState(std::unique_ptr<GameState> gameState);
  void quit();

public:
  Game &m_game; // temporary
};

#endif
