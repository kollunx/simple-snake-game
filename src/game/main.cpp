#include "Game.h"
#include "GameplayState.h"
#include <SDL2/SDL.h>

int main(int argc, char *argv[]) {
  constexpr int fps = 60;
  constexpr int frameDelay = 1000 / fps;

  Uint32 frameStart{};
  int frameTime{};

  Game game;
  game.changeGameState(std::make_unique<GameplayState>(game));

  while (game.isRunning()) {
    frameStart = SDL_GetTicks();

    game.handleEvents();
    game.update();
    game.draw();

    frameTime = static_cast<int>(SDL_GetTicks() - frameStart);

    if (frameDelay > frameTime) {
      SDL_Delay(frameDelay - frameTime);
    }
  }

  return 0;
}
