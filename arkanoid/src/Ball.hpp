#pragma once

#include "Updatable.hpp"
#include <SFML/Graphics/CircleShape.hpp>

class Ball : public sf::CircleShape, public Updatable {
public:
  Ball();
  void update(const sf::Time &deltaTime) override;

private:
  float speed_{3600.f};
  sf::Vector2f direction_{1.f, -1.f};
};
