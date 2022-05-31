#pragma once

#include "Ball.hpp"
#include "Racket.hpp"
#include "SceneBase.hpp"

class PlayScene : public SceneBase {
public:
  PlayScene(sf::RenderWindow &window);
  void update(const sf::Time &deltaTime) override;
  void render(sf::RenderWindow &window) const override;

private:
  Racket racket_;
  Ball ball_;
  bool started_{false};
};
