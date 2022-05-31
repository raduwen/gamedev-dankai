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

  sf::Font font_;
  sf::Text score_text_;
  sf::Text game_over_text_;
  int score_{0};
};
