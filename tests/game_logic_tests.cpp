#include "Snake.h"
#include <gtest/gtest.h>

TEST(GameLogic, SnakeIsAlive) {
  Snake snake;

  EXPECT_FALSE(snake.isDead());
}

TEST(GameLogic, SnakeDies) {
  Snake snake;
  snake.die();

  EXPECT_TRUE(snake.isDead());
}

TEST(GameLogic, SnakeMovesRight) {
  Snake snake(10, 10);

  snake.setDirection(Snake::Direction::RIGHT);
  snake.move();

  EXPECT_EQ(snake.getHeadPosition(), (Position{11, 10}));
}

TEST(GameLogic, SnakeMovesLeft) {
  Snake snake(10, 10);

  snake.setDirection(Snake::Direction::LEFT);
  snake.move();

  EXPECT_EQ(snake.getHeadPosition(), (Position{9, 10}));
}

TEST(GameLogic, SnakeMovesDown) {
  Snake snake(10, 10);

  snake.setDirection(Snake::Direction::DOWN);
  snake.move();

  EXPECT_EQ(snake.getHeadPosition(), (Position{10, 11}));
}

TEST(GameLogic, SnakeMovesUp) {
  Snake snake(10, 10);

  snake.setDirection(Snake::Direction::UP);
  snake.move();

  Position expectedPosition{10, 9};
  EXPECT_EQ(snake.getHeadPosition(), (Position{10, 9}));
}

TEST(GameLogic, SnakeGrows) {
  Snake snake;
  const auto oldTailLength{snake.getTailLength()};

  snake.grow();

  const auto newTailLength{snake.getTailLength()};

  EXPECT_GT(newTailLength, oldTailLength);
}

TEST(GameLogic, SnakeCollidesWithOtherObject) {
  Snake snake(0, 0);
  Position object{0, 0};

  EXPECT_TRUE(snake.checkCollisionWith(object));
}

TEST(GameLogic, SnakeDoesntCollideWithOtherObject) {
  Snake snake(0, 0);
  Position object{1, 1};

  EXPECT_FALSE(snake.checkCollisionWith(object));
}

TEST(GameLogic, SnakeCollidesWithItself) {
  Snake snake(0, 0);

  for (int i{}; i < 5; ++i) {
    snake.grow();
  }

  snake.setDirection(Snake::Direction::RIGHT);

  snake.move();
  snake.move();

  snake.setDirection(Snake::Direction::DOWN);

  snake.move();

  snake.setDirection(Snake::Direction::LEFT);

  snake.move();

  snake.setDirection(Snake::Direction::UP);

  snake.move();

  EXPECT_TRUE(snake.checkSelfCollision());
}

TEST(GameLogic, SnakeDoesntCollideWithItself) {
  Snake snake(5, 5);
  snake.grow();
  snake.setDirection(Snake::Direction::RIGHT);
  snake.move();
  snake.move();

  EXPECT_FALSE(snake.checkSelfCollision());
}

TEST(GameLogic, SnakeIgnoresReverseDirection) {
  Snake snake(10, 10);
  snake.setDirection(Snake::Direction::RIGHT);
  snake.move();
  snake.setDirection(Snake::Direction::LEFT);
  snake.move();

  EXPECT_EQ(snake.getHeadPosition(), (Position{12, 10}));
}
