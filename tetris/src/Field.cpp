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
}

Field::~Field() {}

void Field::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.transform *= getTransform();
  for (auto &blocks : blocks_) {
    for (auto &block : blocks) {
      target.draw(block, states);
    }
  }
}
