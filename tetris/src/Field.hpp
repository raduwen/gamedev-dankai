#pragma once

#include "Block.hpp"
#include "InputManager.hpp"
#include "Tetrimino.hpp"
#include <random>
#include <vector>

class Field : public sf::Drawable, public sf::Transformable {
public:
  Field();
  ~Field();

  void update(InputManager &input);
  Tetrimino &getCurrentTetrimino();

  bool isHit(const Tetrimino &tetrimino) const;
  void fallTetrimino();

  int getDeletedLineCount() const;

private:
  void putTetrimino();
  void nextTetrimino();
  void deleteLines();
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
  std::vector<std::vector<Block>> blocks_;
  int width_{10};
  int height_{20};

  Tetrimino currentTetrimino_{Tetrimino::Type::I, Tetrimino::Rotate::A};
  Tetrimino nextTetrimino_{Tetrimino::Type::I, Tetrimino::Rotate::A};

  std::random_device seed_gen;
  std::mt19937 engine{seed_gen()};
  std::uniform_int_distribution<int> dist{0, 6};

  int deleted_line_count_{0};
};
