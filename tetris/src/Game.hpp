#pragma once

#include "InputManager.hpp"
#include "SceneManager.hpp"
#include <SFML/System/Clock.hpp>

class Game {
public:
  Game();
  void run();

private:
  void processEvents();
  void update();
  void render();

private:
  sf::RenderWindow window_{{1600, 900}, "Tetris"};
  SceneManager scene_manager_;
  InputManager input_;

  sf::Clock clock_;
};
