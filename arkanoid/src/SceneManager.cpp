#include "SceneManager.hpp"
#include <stdexcept>

void SceneManager::update(const sf::Time &deltaTime) {
  if (next_scene_id_ != "") {
    if (current_scene_)
      current_scene_->onDeactivate();
    current_scene_ = scenes_[next_scene_id_].get();
    next_scene_id_ = "";
    current_scene_->onActivate();
  }
  if (current_scene_)
    current_scene_->update(deltaTime);
}

void SceneManager::render(sf::RenderWindow &window) {
  if (current_scene_)
    current_scene_->render(window);
}

void SceneManager::add(const std::string &id, std::unique_ptr<SceneBase> scene) {
  auto found = scenes_.find(id);
  if (found != scenes_.end())
    throw std::runtime_error("Scene with id " + id + " already exists");
  scenes_.insert(std::make_pair(id, std::move(scene)));
}

void SceneManager::switchTo(const std::string &id) {
  auto found = scenes_.find(id);
  if (found == scenes_.end())
    throw std::runtime_error("Scene with id " + id + " does not exist");
  next_scene_id_ = id;
}
