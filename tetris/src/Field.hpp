#pragma once

#include "Block.hpp"
#include "InputManager.hpp"
#include "Tetrimino.hpp"
#include <vector>

class Field : public sf::Drawable, public sf::Transformable {
public:
  Field();
  ~Field();

  void update(InputManager &input);
  Tetrimino &getCurrentTetrimino();

  bool isHit(const Tetrimino &tetrimino) const;

private:
  void nextTetrimino();
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
  std::vector<std::vector<Block>> blocks_;
  int width_{10};
  int height_{20};

  Tetrimino currentTetrimino_{Tetrimino::Type::I, Tetrimino::Rotate::A};
  Tetrimino nextTetrimino_{Tetrimino::Type::I, Tetrimino::Rotate::A};
};
