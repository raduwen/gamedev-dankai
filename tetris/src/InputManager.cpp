#include "InputManager.hpp"

InputManager::InputManager() {
  beforeInputState_.clear();
  currentInputState_.clear();
}

InputManager::~InputManager() {}

void InputManager::update() {
  beforeInputState_ = currentInputState_;
  currentInputState_.clear();
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    currentInputState_[sf::Keyboard::Left] = true;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    currentInputState_[sf::Keyboard::Right] = true;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    currentInputState_[sf::Keyboard::Down] = true;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    currentInputState_[sf::Keyboard::Space] = true;
}

bool InputManager::isPushed(sf::Keyboard::Key key) { return currentInputState_[key] && !beforeInputState_[key]; }
