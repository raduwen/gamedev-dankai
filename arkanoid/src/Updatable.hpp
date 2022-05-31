#pragma once

#include <SFML/System/Time.hpp>

class Updatable {
public:
  virtual void update(const sf::Time &deltaTime) = 0;
};
