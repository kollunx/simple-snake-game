#include "GameplayState.h"
#include "Renderer.h"
#include "Types.h"
#include <ctime>

constexpr Screen logicalScreen{20, 20};
constexpr Uint32 delay{200};
constexpr RGBA snakeColor{0, 255, 0, 255};
constexpr RGBA appleColor{255, 0, 0, 255};

GameplayState::GameplayState(Game &game)
    : GameState(game, logicalScreen), m_snake(logicalScreen.width / 2, logicalScreen.height / 2), m_apple{},
      m_timeDelay{delay} {
  srand(std::time(nullptr));
  m_apple = {rand() % logicalScreen.width, rand() % logicalScreen.height};
}

void GameplayState::handleEvents() {
  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type) {
  case SDL_QUIT:
    quit();
    break;
  default:
    break;
  }

  switch (event.key.keysym.sym) {
  case SDLK_UP:
    m_snake.setDirection(Snake::Direction::UP);
    break;
  case SDLK_DOWN:
    m_snake.setDirection(Snake::Direction::DOWN);
    break;
  case SDLK_LEFT:
    m_snake.setDirection(Snake::Direction::LEFT);
    break;
  case SDLK_RIGHT:
    m_snake.setDirection(Snake::Direction::RIGHT);
    break;
  default:
    break;
  }
}

void GameplayState::update() {
  Uint32 currentTime = SDL_GetTicks();

  if (currentTime - m_timeElapsed <= m_timeDelay) {
    return;
  }

  m_snake.move();

  if (m_snake.checkSelfCollision()) {
    quit();
  }

  if (m_snake.checkCollisionWith(m_apple)) {
    m_apple = {rand() % logicalScreen.width, rand() % logicalScreen.height};
    m_snake.grow();
    m_timeDelay -= 1;
  }

  if (m_snake.getHeadPosition().x >= logicalScreen.width || m_snake.getHeadPosition().x < 0) {
    quit();
  }

  if (m_snake.getHeadPosition().y >= logicalScreen.height || m_snake.getHeadPosition().y < 0) {
    quit();
  }

  m_timeElapsed = currentTime;
}

void GameplayState::draw(Renderer &renderer) {
  renderer.clear();

  renderer.setDrawColor(snakeColor);
  renderer.drawPoint(m_snake.getHeadPosition().x, m_snake.getHeadPosition().y);

  renderer.setDrawColor(appleColor);
  renderer.drawPoint(m_apple.x, m_apple.y);

  renderer.setDrawColor(snakeColor);
  for (int i{}; i < m_snake.getTailLength(); ++i) {
    renderer.drawPoint(m_snake.getTailPosition(i).x, m_snake.getTailPosition(i).y);
  }

  renderer.setDrawColor({});
  renderer.present();
}
