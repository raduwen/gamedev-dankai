#include "Racket.hpp"
#include <SFML/Window/Keyboard.hpp>

Racket::Racket() {
  setFillColor({0, 32, 128});
  setOutlineColor({64, 64, 255});
  setOutlineThickness(1.f);
  setSize({100.f, 20.f});
}

void Racket::update(const sf::Time &deltaTime) {
  float v = speed_ * deltaTime.asSeconds();
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    if ((getPosition().x - v) < 0) {
      setPosition({0.f, getPosition().y});
    } else {
      move(-v, 0.f);
    }
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    if ((getPosition().x + v) > (1600 - getSize().x)) {
      setPosition({1600.f - getSize().x, getPosition().y});
    } else {
      move(v, 0.f);
    }
  }
}
