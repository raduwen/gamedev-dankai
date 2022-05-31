#include "PlayScene.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <imgui.h>

PlayScene::PlayScene(sf::RenderWindow &window) {
  auto win_size = window.getSize();
  auto r_size = racket_.getSize();
  racket_.setPosition({win_size.x / 2.f - r_size.x / 2.f, win_size.y - 50.f - r_size.y});
}

void PlayScene::update(const sf::Time &deltaTime) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !started_) {
    started_ = true;
  }

  racket_.update(deltaTime);

  if (started_) {
    ball_.update(deltaTime);
  } else {
    auto r = ball_.getRadius();
    ball_.setPosition(racket_.getSize().x / 2.f - r + racket_.getPosition().x,
                      racket_.getPosition().y - racket_.getSize().y - r);
  }

  ImGui::Begin("Racket info");
  ImGui::Text("Racket position: %.2f, %.2f", racket_.getPosition().x, racket_.getPosition().y);
  ImGui::End();
}

void PlayScene::render(sf::RenderWindow &window) const {
  window.draw(racket_);
  window.draw(ball_);
}
