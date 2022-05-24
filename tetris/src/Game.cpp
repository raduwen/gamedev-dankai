#include "Game.hpp"

void Game::run() {
  {
    int fw = 32 * 12, fh = 32 * 21;
    int ww = window_.getSize().x, wh = window_.getSize().y;

    field_.setPosition({(ww - fw) / 2.f, (wh - fh) / 2.f});
  }

  while (window_.isOpen()) {
    processEvents();
    update();
    render();
  }
}

void Game::processEvents() {
  sf::Event event;
  while (window_.pollEvent(event)) {
    if (event.type == sf::Event::Closed)
      window_.close();
  }
}

void Game::update() {
  // update
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    window_.close();

  /*
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
    */

  /*
    { // test tetrimino
      if (beforeInputState[sf::Keyboard::Left] && !currentInputState[sf::Keyboard::Left]) {
        auto t = t_i.getType();
        auto nt = t == Tetrimino::Type::Z ? Tetrimino::Type::I : static_cast<Tetrimino::Type>(static_cast<int>(t) + 1);
        t_i.setTypeWithRotate(nt, Tetrimino::Rotate::A);
      }

      if (beforeInputState[sf::Keyboard::Space] && !currentInputState[sf::Keyboard::Space])
        t_i.rotate();
    }
    */
}

void Game::render() {
  window_.clear();
  window_.draw(field_);
  window_.display();
}
