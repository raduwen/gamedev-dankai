#include "Game.hpp"
#include <exception>
#include <iostream>

int main() {
  try {
    Game game;
    game.run();
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return 0;
}
