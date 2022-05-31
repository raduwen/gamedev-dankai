#pragma once

#include "Field.hpp"
#include "InputManager.hpp"
#include "SceneBase.hpp"
#include "SceneManager.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class PlayScene : public SceneBase {
public:
  PlayScene(const sf::RenderWindow &window, SceneManager &scene_manager, InputManager &input_manager);
  ~PlayScene() = default;

  void update(const sf::Time &deltaTime) override;
  void render(sf::RenderWindow &window) const override;
  void onActivate() override;

private:
  SceneManager &scene_manager_;
  InputManager &input_;
  Field field_;
  sf::Font font_;
  sf::Text score_text_;
  sf::Text game_over_text_;
  int score_{0};
};
