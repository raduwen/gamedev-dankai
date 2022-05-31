#pragma once

#include "InputManager.hpp"
#include "SceneBase.hpp"
#include "SceneManager.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class TitleScene : public SceneBase {
public:
  TitleScene(const sf::RenderWindow &window, SceneManager &scene_manager, InputManager &input_manager);
  ~TitleScene() = default;
  void update(const sf::Time &deltaTime) override;
  void render(sf::RenderWindow &window) const override;

private:
  sf::Font font_;
  sf::Text title_text_;
  sf::Text push_text_;
  SceneManager &scene_manager_;
  InputManager &input_;
  sf::Clock clock_;
  bool plus_{true};
};
