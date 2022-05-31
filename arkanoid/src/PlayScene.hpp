#pragma once

#include "Racket.hpp"
#include "SceneBase.hpp"

class PlayScene : public SceneBase {
public:
  PlayScene(sf::RenderWindow &window);
  void update(const sf::Time &deltaTime) override;
  void render(sf::RenderWindow &window) const override;
  // void onActivate() override;
  // void onDeactivate() override;

private:
  Racket racket_;
};
