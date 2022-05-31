#pragma once

#include "SceneManager.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

class Game {
public:
  Game();
  ~Game();

  void run();

private:
  void processEvents();
  void update();
  void render();

private:
  sf::RenderWindow window_{{1600, 900}, "arkanoid", sf::Style::Close};
  sf::Clock clock_;
  SceneManager scene_manager_;
};
