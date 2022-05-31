#include "PlayScene.hpp"
#include <iostream>

PlayScene::PlayScene(const sf::RenderWindow &window, SceneManager &scene_manager, InputManager &input_manager)
    : scene_manager_(scene_manager), input_(input_manager) {
  if (!font_.loadFromFile("assets/fonts/Mplus2-Regular.ttf")) {
    std::cerr << "Failed to load font." << std::endl;
  } else {
    score_text_.setFont(font_);
    score_text_.setCharacterSize(32);
    score_text_.setFillColor(sf::Color::White);
    score_text_.setOutlineColor({32, 32, 32});
    score_text_.setString("Score: 0");
    score_text_.setPosition(8, 8);

    game_over_text_.setFont(font_);
    game_over_text_.setCharacterSize(128);
    game_over_text_.setFillColor(sf::Color::Red);
    game_over_text_.setString("Game Over");
    game_over_text_.setPosition(window.getSize().x / 2 - game_over_text_.getGlobalBounds().width / 2,
                                window.getSize().y / 2 - game_over_text_.getGlobalBounds().height / 2);
  }

  { // centering field on screen
    int fw = 32 * 12, fh = 32 * 21;
    int ww = window.getSize().x, wh = window.getSize().y;
    field_.setPosition({(ww - fw) / 2.f, (wh - fh) / 2.f});
  }
}

void PlayScene::update(const sf::Time &deltaTime) {
  if (field_.isGameOver()) {
    if (input_.isPushed(sf::Keyboard::Space)) {
      scene_manager_.switchTo("title");
    }
  } else {
    field_.update(input_);
    field_.fallTetrimino();

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
}

void PlayScene::render(sf::RenderWindow &window) const {
  window.draw(field_);
  window.draw(score_text_);
  if (field_.isGameOver())
    window.draw(game_over_text_);
}

void PlayScene::onActivate() {
  field_.reset();
  score_ = 0;
}
