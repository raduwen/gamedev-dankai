#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>
#include <imgui.h>

int main() {
  sf::RenderWindow window{{1600, 900}, "arkanoid", sf::Style::Close};

  if (!ImGui::SFML::Init(window))
    return -1;

  sf::Clock clock;

  clock.restart();
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      ImGui::SFML::ProcessEvent(event);
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    ImGui::SFML::Update(window, clock.getElapsedTime());

    ImGui::Begin("hello");
    ImGui::Text("Hello");
    ImGui::End();

    window.clear();
    ImGui::SFML::Render(window);
    window.display();

    clock.restart();
  }

  ImGui::SFML::Shutdown();
  return 0;
}
