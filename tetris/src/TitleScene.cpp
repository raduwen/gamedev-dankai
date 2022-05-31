#include "TitleScene.hpp"
#include <SFML/Window/Keyboard.hpp>

TitleScene::TitleScene(const sf::RenderWindow &window, SceneManager &scene_manager, InputManager &input_manager)
    : scene_manager_(scene_manager), input_(input_manager) {
  font_.loadFromFile("Mplus2-Regular.ttf");
  title_text_.setFont(font_);
  title_text_.setCharacterSize(64);
  title_text_.setString("Tetris");
  title_text_.setPosition(window.getSize().x / 2 - title_text_.getGlobalBounds().width / 2,
                          window.getSize().y / 2 - title_text_.getGlobalBounds().height / 2 - 128);
}

void TitleScene::update(const sf::Time &deltaTime) {
  if (input_.isPushed(sf::Keyboard::Space)) {
    scene_manager_.switchTo("play");
  }
}

void TitleScene::render(sf::RenderWindow &window) const { window.draw(title_text_); }
