#ifndef GAMEPLAY_STATE_H
#define GAMEPLAY_STATE_H

#include <SDL2/SDL.h>
#include "GameState.h"
#include "Snake.h"

class GameplayState : public GameState {
public:
  GameplayState(Game &game);

  void handleEvents() override;
  void update() override;
  void draw(Renderer &renderer) override;

private:
  Snake m_snake;
  Position m_apple;
  Uint32 m_timeDelay{};
  Uint32 m_timeElapsed{};
};

#endif
