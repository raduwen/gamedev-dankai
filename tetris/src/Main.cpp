#include "Tetrimino.hpp"
#include <SFML/Graphics.hpp>
#include <map>

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Tetris");
  Tetrimino t_i(Tetrimino::Type::I, Tetrimino::Rotate::A);

  // input state
  std::map<sf::Keyboard::Key, bool> beforeInputState, currentInputState;

  while (window.isOpen()) {
    // process events
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    // update
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
      window.close();

    { // update input state
      beforeInputState = currentInputState;
      currentInputState.clear();
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        currentInputState[sf::Keyboard::Left] = true;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        currentInputState[sf::Keyboard::Right] = true;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        currentInputState[sf::Keyboard::Space] = true;
    }

    { // test tetrimino
      if (beforeInputState[sf::Keyboard::Left] && !currentInputState[sf::Keyboard::Left]) {
        auto t = t_i.getType();
        auto nt = t == Tetrimino::Type::Z ? Tetrimino::Type::I : static_cast<Tetrimino::Type>(static_cast<int>(t) + 1);
        t_i.setTypeWithRotate(nt, Tetrimino::Rotate::A);
      }

      if (beforeInputState[sf::Keyboard::Space] && !currentInputState[sf::Keyboard::Space])
        t_i.rotate();
    }

    // render
    window.clear();
    window.draw(t_i);
    window.display();
  }

  return 0;
}
