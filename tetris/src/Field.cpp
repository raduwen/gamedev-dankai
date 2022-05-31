#include "Field.hpp"

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

  nextTetrimino_.setPosition((width_ + 4) * 32 + 32, -32);
  nextTetrimino();
  nextTetrimino();
}

Field::~Field() {}

void Field::update(InputManager &input) {
  deleted_line_count_ = 0;

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
      fallTetrimino();
    }
    if (input.isPushed(sf::Keyboard::Space)) {
      currentTetrimino_.rotate();
      if (isHit(currentTetrimino_)) {
        // [todo] - 反対に回す? 位置を調整する?
        currentTetrimino_.rotate();
        currentTetrimino_.rotate();
        currentTetrimino_.rotate();
      }
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

void Field::fallTetrimino() {
  currentTetrimino_.move(Tetrimino::MoveDirection::Down);
  if (isHit(currentTetrimino_)) {
    currentTetrimino_.move(Tetrimino::MoveDirection::Up);
    putTetrimino();
    deleteLines();
    nextTetrimino();
  }
}

void Field::putTetrimino() {
  auto points = currentTetrimino_.getPoints();
  auto pos = currentTetrimino_.getPosition();
  std::size_t bx = pos.x / 32, by = pos.y / 32;
  for (auto &point : points) {
    blocks_[by + point.second][bx + point.first].setColor(currentTetrimino_.getColor());
  }
}

void Field::nextTetrimino() {
  currentTetrimino_ = nextTetrimino_;
  currentTetrimino_.setPosition(32 * 4, 0);

  if (isHit(currentTetrimino_)) {
    game_over_ = true;
    return;
  }

  int t = dist(engine);
  nextTetrimino_.setTypeWithRotate(static_cast<Tetrimino::Type>(t), Tetrimino::Rotate::A);
}

void Field::deleteLines() {
  for (std::size_t y = 0; y < height_; ++y) {
    bool full{true};
    for (std::size_t x = 1; x < width_ + 1; ++x) {
      if (blocks_[y][x].isNone()) {
        full = false;
        break;
      }
    }

    if (full) {
      deleted_line_count_++;
      for (std::size_t y2 = y; y2 > 0; --y2) {
        for (std::size_t x = 1; x < width_ + 1; ++x) {
          blocks_[y2][x].setColor(blocks_[y2 - 1][x].getColor());
        }
      }
      for (std::size_t x = 1; x < width_ + 1; ++x) {
        blocks_[0][x].setColor(Block::Color::None);
      }
    }
  }
}

void Field::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.transform *= getTransform();
  for (auto &blocks : blocks_) {
    for (auto &block : blocks) {
      target.draw(block, states);
    }
  }

  target.draw(currentTetrimino_, states);
  target.draw(nextTetrimino_, states);
}

int Field::getDeletedLineCount() const { return deleted_line_count_; }

bool Field::isGameOver() const { return game_over_; }

void Field::reset() {
  deleted_line_count_ = 0;
  game_over_ = false;
  for (std::size_t y = 0; y < height_; ++y) {
    for (std::size_t x = 1; x < width_ + 1; ++x) {
      blocks_[y][x].setColor(Block::Color::None);
    }
  }

  nextTetrimino_.setPosition((width_ + 4) * 32 + 32, -32);
  nextTetrimino();
  nextTetrimino();
}
