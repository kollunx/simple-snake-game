#include "Game.h"
#include <ctime>
#include <iostream>

Game::Game()
    : m_window(gameTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight),
      m_renderer(m_window), m_isRunning(true) {}

void Game::handleEvents() {
  m_gameState->handleEvents();
}

void Game::update() {
  m_gameState->update();
}

void Game::draw() {
  m_gameState->draw(m_renderer);
}

Game::~Game() {
  SDL_Quit();
}