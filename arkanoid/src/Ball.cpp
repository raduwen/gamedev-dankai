#include "Ball.hpp"

Ball::Ball() : sf::CircleShape(16.f) { setFillColor(sf::Color::Red); }

void Ball::update(const sf::Time &deltaTime) {
  // move
  auto v = direction_ * (speed_ * deltaTime.asSeconds());
  move(v);

  // [tood] - collision
}
