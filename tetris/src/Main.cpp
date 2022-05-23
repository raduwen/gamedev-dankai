#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Tetris");

  sf::RectangleShape block{{32, 32}};
  block.setFillColor(sf::Color::Red);
  block.setOutlineColor({64, 0, 0});
  block.setOutlineThickness(1.f);

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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
      block.move(-0.1, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
      block.move(0.1, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
      block.move(0, -0.1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
      block.move(0, 0.1);

    // render
    window.clear();
    window.draw(block);
    window.display();
  }

  return 0;
}
