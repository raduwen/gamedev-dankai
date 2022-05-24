#pragma once

#include "Block.hpp"
#include <vector>

class Field : public sf::Drawable, public sf::Transformable {
public:
  Field();
  ~Field();

private:
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
  std::vector<std::vector<Block>> blocks_;
  int width_{10};
  int height_{20};
};
