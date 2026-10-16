#ifndef SNAKE_H
#define SNAKE_H

#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

struct Position {
  int x{};
  int y{};
  bool operator==(const Position&) const = default;
};

class Snake {
public:
  enum class Direction : std::uint8_t { STOP, UP, DOWN, LEFT, RIGHT };

private:
  Position m_headPosition{};
  std::vector<Position> m_tailPosition;
  Direction m_currentDirection{};
  Direction m_lastDirection{};
  bool m_isDead{false};

public:
  Snake();
  Snake(int x, int y);

  void setDirection(Direction direction) noexcept;
  void move();
  void grow() { m_tailPosition.push_back({.x = -1, .y = -1}); }
  void die() { m_isDead = true; }

  Position getHeadPosition() const noexcept { return m_headPosition; }
  std::size_t getTailLength() const noexcept { return m_tailPosition.size(); }

  Position getTailPosition(std::size_t index) const {
    if (index >= m_tailPosition.size()) {
      throw std::out_of_range("Error: The Index '" + std::to_string(index) +
                              "' passed to 'Snake::getTailPosition(std::size_t index)' is out of range");
    }

    return m_tailPosition.at(index);
  }

  bool checkSelfCollision();
  bool checkCollisionWith(Position object);
  bool isDead() const noexcept { return m_isDead; }
};

#endif
