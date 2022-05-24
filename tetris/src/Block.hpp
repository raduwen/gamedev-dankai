#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Block : public sf::Drawable, public sf::Transformable {
public:
  enum class Color { Red, Green, Blue, Yellow, Purple, Cyan, Orange };

public:
  Block(Color color = Color::Red);
  ~Block();

  void setColor(Color color);

private:
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  sf::Color getSfColor(Color color) const;

private:
  sf::RectangleShape shape{{32, 32}};
};
