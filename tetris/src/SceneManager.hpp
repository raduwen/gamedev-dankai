#pragma once

#include "SceneBase.hpp"
#include <map>
#include <memory>
#include <string>

class SceneManager {
public:
  void update(const sf::Time &deltaTime);
  void render(sf::RenderWindow &window);

  void add(const std::string &id, std::unique_ptr<SceneBase> scene);
  void switchTo(const std::string &id);

private:
  std::map<std::string, std::unique_ptr<SceneBase>> scenes_;
  std::string next_scene_id_{""};
  SceneBase *current_scene_{nullptr};
};
