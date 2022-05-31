#include "Game.hpp"
#include "PlayScene.hpp"
#include "TitleScene.hpp"
#include <SFML/Window/Event.hpp>
#include <iostream>

Game::Game() {
  scene_manager_.add("title", std::make_unique<TitleScene>(window_, scene_manager_, input_));
  scene_manager_.add("play", std::make_unique<PlayScene>(window_, scene_manager_, input_));
  scene_manager_.switchTo("title");
}

void Game::run() {
  while (window_.isOpen()) {
    clock_.restart();
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
  scene_manager_.update(clock_.getElapsedTime());
}

void Game::render() {
  window_.clear();
  scene_manager_.render(window_);
  window_.display();
}
