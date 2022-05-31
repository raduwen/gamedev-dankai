#include "TitleScene.hpp"
#include <SFML/Window/Keyboard.hpp>

TitleScene::TitleScene(const sf::RenderWindow &window, SceneManager &scene_manager, InputManager &input_manager)
    : scene_manager_(scene_manager), input_(input_manager) {
  font_.loadFromFile("assets/fonts/Mplus2-Regular.ttf");
  title_text_.setFont(font_);
  title_text_.setCharacterSize(64);
  title_text_.setString("Tetris");
  title_text_.setPosition(window.getSize().x / 2 - title_text_.getGlobalBounds().width / 2,
                          window.getSize().y / 2 - title_text_.getGlobalBounds().height / 2 - 128);

  push_text_.setFont(font_);
  push_text_.setCharacterSize(48);
  push_text_.setString("Push space key to start");
  push_text_.setPosition(window.getSize().x / 2 - push_text_.getGlobalBounds().width / 2,
                         window.getSize().y / 2 - push_text_.getGlobalBounds().height / 2 + 256);
  clock_.restart();
}

void TitleScene::update(const sf::Time &deltaTime) {
  if (input_.isPushed(sf::Keyboard::Space)) {
    scene_manager_.switchTo("play");
  }
  if (clock_.getElapsedTime().asSeconds() > 1) {
    clock_.restart();
    plus_ = !plus_;
  }
  if (plus_)
    push_text_.setFillColor({255, 255, 255, static_cast<sf::Uint8>(255 * (1 - clock_.getElapsedTime().asSeconds()))});
  else
    push_text_.setFillColor(
        {255, 255, 255, static_cast<sf::Uint8>(255 - 255 * (1 - clock_.getElapsedTime().asSeconds()))});
}

void TitleScene::render(sf::RenderWindow &window) const {
  window.draw(title_text_);
  window.draw(push_text_);
}
