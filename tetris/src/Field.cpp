#include "Field.hpp"
#include <iostream>

Field::Field() {
  for (std::size_t y = 0; y < height_ + 1; ++y) {
    blocks_.emplace_back();
    for (std::size_t x = 0; x < width_ + 2; ++x) {
      blocks_[y].emplace_back(Block::Color::None);
      blocks_[y].back().setPosition(x * 32, y * 32);
    }
  }

  for (std::size_t y = 0; y < height_ + 1; ++y) {
    blocks_[y][0].setColor(Block::Color::Gray);
    blocks_[y][width_ + 1].setColor(Block::Color::Gray);
  }
  for (std::size_t x = 0; x < width_ + 2; ++x) {
    blocks_[height_][x].setColor(Block::Color::Gray);
  }

  // [todo] - randomize current/next tetrimino
  currentTetrimino_.setTypeWithRotate(Tetrimino::Type::I, Tetrimino::Rotate::A);
  currentTetrimino_.setPosition(32 * 4, 0);
}

Field::~Field() {}

void Field::update(InputManager &input) {
  // [todo] - generate random tetrimino
  // [todo] - fall

  { // process user input
    if (input.isPushed(sf::Keyboard::Left)) {
      currentTetrimino_.move(Tetrimino::MoveDirection::Left);
      if (isHit(currentTetrimino_)) {
        currentTetrimino_.move(Tetrimino::MoveDirection::Right);
      }
    }
    if (input.isPushed(sf::Keyboard::Right)) {
      currentTetrimino_.move(Tetrimino::MoveDirection::Right);
      if (isHit(currentTetrimino_)) {
        currentTetrimino_.move(Tetrimino::MoveDirection::Left);
      }
    }
    if (input.isPushed(sf::Keyboard::Down)) {
      currentTetrimino_.move(Tetrimino::MoveDirection::Down);
      if (isHit(currentTetrimino_)) {
        currentTetrimino_.move(Tetrimino::MoveDirection::Up);
        // [todo] - fix blocks
      }
    }
    if (input.isPushed(sf::Keyboard::Space)) {
      currentTetrimino_.rotate();
      // [todo] - check collision
    }
  }
}

Tetrimino &Field::getCurrentTetrimino() { return currentTetrimino_; }

bool Field::isHit(const Tetrimino &tetrimino) const {
  for (auto &blocks : blocks_) {
    for (auto &block : blocks) {
      if (!block.isNone() && currentTetrimino_.isHit(block)) {
        return true;
      }
    }
  }
  return false;
}

void Field::nextTetrimino() {
  currentTetrimino_ = nextTetrimino_;
  // [todo] - randomize next tetrimino
  nextTetrimino_.setTypeWithRotate(Tetrimino::Type::I, Tetrimino::Rotate::A);
}

void Field::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.transform *= getTransform();
  for (auto &blocks : blocks_) {
    for (auto &block : blocks) {
      target.draw(block, states);
    }
  }

  target.draw(currentTetrimino_, states);
}
