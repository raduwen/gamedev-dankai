#include "Game.hpp"
#include <iostream>

Game::Game() {
  if (!font_.loadFromFile("Mplus2-Regular.ttf")) {
    std::cerr << "Failed to load font." << std::endl;
  } else {
    score_text_.setFont(font_);
    score_text_.setCharacterSize(32);
    score_text_.setFillColor(sf::Color::White);
    score_text_.setOutlineColor({32, 32, 32});
    score_text_.setString("Score: 0");
    score_text_.setPosition(8, 8);
  }
}

void Game::run() {
  { // centering field on screen
    int fw = 32 * 12, fh = 32 * 21;
    int ww = window_.getSize().x, wh = window_.getSize().y;
    field_.setPosition({(ww - fw) / 2.f, (wh - fh) / 2.f});
  }

  clock_.restart();
  while (window_.isOpen()) {
    processEvents();
    update();
    render();
  }
}

void Game::processEvents() {
  sf::Event event;
  while (window_.pollEvent(event)) {
    if (event.type == sf::Event::Closed)
      window_.close();
  }
}

void Game::update() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    window_.close();
  input_.update();
  field_.update(input_);
  if (clock_.getElapsedTime().asSeconds() > 1.f) {
    clock_.restart();
    field_.fallTetrimino();
  }

  if (int count = field_.getDeletedLineCount(); count > 0) {
    switch (count) {
    case 1:
      score_ += 10;
      break;
    case 2:
      score_ += 50;
      break;
    case 3:
      score_ += 200;
      break;
    case 4:
      score_ += 500;
      break;
    }

    score_text_.setString("Score: " + std::to_string(score_));
  }
}

void Game::render() {
  window_.clear();
  window_.draw(field_);
  window_.draw(score_text_);
  window_.display();
}
