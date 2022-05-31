#pragma once

#include "Updatable.hpp"
#include <SFML/Graphics/RectangleShape.hpp>

class Racket : public sf::RectangleShape, public Updatable {
public:
  Racket();

  void update(const sf::Time &deltaTime) override;

private:
  float speed_{3600.f}; // pixel per second
};
