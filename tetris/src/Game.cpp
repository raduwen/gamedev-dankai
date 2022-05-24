#include "Game.hpp"

Game::Game() {}

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
    if (clock_.getElapsedTime().asSeconds() > 1.f) {
      clock_.restart();
      field_.fallTetrimino();
    }
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
}

void Game::render() {
  window_.clear();
  window_.draw(field_);
  window_.display();
}
