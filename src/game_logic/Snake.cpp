#include "Snake.h"

constexpr std::size_t reserveSize{100};

Snake::Snake() {
  m_tailPosition.reserve(reserveSize);
}

Snake::Snake(int x, int y) : Snake::Snake() {
  m_headPosition = {x, y};
}

void Snake::move() {
  if (m_currentDirection == Direction::STOP)
    return;

  Position previousHeadPosition = m_headPosition;

  switch (m_currentDirection) {
  case Direction::UP:
    m_headPosition.y -= 1;
    break;
  case Direction::DOWN:
    m_headPosition.y += 1;
    break;
  case Direction::LEFT:
    m_headPosition.x -= 1;
    break;
  case Direction::RIGHT:
    m_headPosition.x += 1;
    break;
  case Direction::STOP:
    break;
  }

  for (int i{static_cast<int>(m_tailPosition.size()) - 1}; i > 0; --i) {
    m_tailPosition.at(i) = m_tailPosition.at(i - 1);
  }

  if (m_tailPosition.size() > 0) {
    m_tailPosition.front() = previousHeadPosition;
  }

  m_lastDirection = m_currentDirection;
}

void Snake::setDirection(Direction direction) noexcept {
  if ((m_lastDirection == Direction::UP && direction == Direction::DOWN) ||
      (m_lastDirection == Direction::DOWN && direction == Direction::UP) ||
      (m_lastDirection == Direction::RIGHT && direction == Direction::LEFT) ||
      (m_lastDirection == Direction::LEFT && direction == Direction::RIGHT)) {
    return;
  }

  m_currentDirection = direction;
}

bool Snake::checkSelfCollision() {
  for (int i{}; i < getTailLength(); ++i) {
    if (getHeadPosition().x == getTailPosition(i).x && getHeadPosition().y == getTailPosition(i).y) {
      return true;
    }
  }

  return false;
}

bool Snake::checkCollisionWith(Position object) {
  if (getHeadPosition().x == object.x && getHeadPosition().y == object.y) {
    return true;
  }

  return false;
}
