#include "Ball.hpp"

Ball::Ball() : sf::CircleShape(16.f) { setFillColor(sf::Color::Red); }

void Ball::update(const sf::Time &deltaTime) {
  // get velocity
  auto v = direction_ * (speed_ * deltaTime.asSeconds());

  // reflect when hit wall
  if (getPosition().x + v.x < 0) {
    direction_.x *= -1;
  } else if (getPosition().x + v.x > 1600 - getRadius() * 2) {
    direction_.x *= -1;
  }
  if (getPosition().y + v.y < 0) {
    direction_.y *= -1;
  } else if (getPosition().y + v.y > 900 - getRadius() * 2) {
    direction_.y *= -1;
  }

  move(v);
}
