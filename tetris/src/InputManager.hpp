#pragma once

#include <SFML/Window/Keyboard.hpp>
#include <map>

class InputManager {
public:
  InputManager();
  ~InputManager();

  void update();
  bool isPushed(sf::Keyboard::Key key);

private:
  // input state
  std::map<sf::Keyboard::Key, bool> beforeInputState_, currentInputState_;
};
