#include "Block.hpp"

Block::Block(Color color) { setColor(color); }

Block::~Block() {}

void Block::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.transform *= getTransform();
  target.draw(shape_, states);
}

void Block::setColor(Color color) {
  color_ = color;
  shape_.setFillColor(getSfColor(color));
}

bool Block::isNone() const { return color_ == Color::None; }

sf::Color Block::getSfColor(Color color) const {
  switch (color) {
  case Color::None:
    return sf::Color::Transparent;
  case Color::Red:
    return sf::Color::Red;
  case Color::Green:
    return sf::Color::Green;
  case Color::Blue:
    return sf::Color::Blue;
  case Color::Yellow:
    return sf::Color::Yellow;
  case Color::Purple:
    return sf::Color(128, 0, 128);
  case Color::Cyan:
    return sf::Color::Cyan;
  case Color::Orange:
    return sf::Color(255, 128, 0);
  case Color::Gray:
    return sf::Color(64, 64, 64);
  }
}
