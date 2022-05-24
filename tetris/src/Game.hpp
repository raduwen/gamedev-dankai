#pragma once

#include "Field.hpp"
#include "Tetrimino.hpp"
#include <SFML/Graphics.hpp>
#include <map>

class Game {
public:
  void run();

private:
  void processEvents();
  void update();
  void render();

private:
  sf::RenderWindow window_{{1600, 900}, "Tetris"};

  // input state
  std::map<sf::Keyboard::Key, bool> beforeInputState_, currentInputState_;
  Field field_;
};
