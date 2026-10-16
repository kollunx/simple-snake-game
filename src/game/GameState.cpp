#include "Game.h"
#include "GameState.h"

GameState::GameState(Game &game, Screen screen) : m_game(game) {
  m_game.changeLogicScreen(screen);
}

void GameState::changeState(std::unique_ptr<GameState> gameState) {
  m_game.changeGameState(std::move(gameState));
}

void GameState::quit() {
  m_game.quit();
}
