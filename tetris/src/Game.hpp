#pragma once

#include "Field.hpp"
#include "InputManager.hpp"
#include "Tetrimino.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <map>

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
  InputManager input_;
  Field field_;
  sf::Clock clock_;
};
