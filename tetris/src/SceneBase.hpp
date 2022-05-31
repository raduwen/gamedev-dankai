#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

class SceneBase {
public:
  virtual ~SceneBase() = default;
  virtual void update(const sf::Time &deltaTime) = 0;
  virtual void render(sf::RenderWindow &window) const = 0;
  virtual void onActivate(){};
  virtual void onDeactivate(){};
};
