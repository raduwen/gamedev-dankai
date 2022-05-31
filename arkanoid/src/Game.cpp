#include "Game.hpp"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <imgui-SFML.h>
#include <imgui.h>

Game::Game() {
  if (!ImGui::SFML::Init(window_)) {
    throw std::runtime_error("Failed to initialize ImGui-SFML");
  }
  clock_.restart();
}

Game::~Game() { ImGui::SFML::Shutdown(); }

void Game::run() {
  while (window_.isOpen()) {
    processEvents();
    update();
    render();
    clock_.restart();
  }
}

void Game::processEvents() {
  sf::Event event;
  while (window_.pollEvent(event)) {
    ImGui::SFML::ProcessEvent(event);
    if (event.type == sf::Event::Closed) {
      window_.close();
    }
  }
}

void Game::update() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
    window_.close();
  }

  ImGui::SFML::Update(window_, clock_.getElapsedTime());

  ImGui::Begin("hello");
  ImGui::Text("Hello");
  ImGui::End();
}

void Game::render() {
  window_.clear();
  ImGui::SFML::Render(window_);
  window_.display();
}
