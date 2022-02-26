#include "game.hpp"
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <iostream>

namespace axe {

Game::Game(sf::String const& title,int const& width, int const& height) : defaultTitle(title), defaultWidth(width), defaultHeight(height)
{
  initWindow();
}

void Game::initWindow() {
  window = new sf::RenderWindow(sf::VideoMode(defaultWidth, defaultHeight), defaultTitle, sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);

  font = new sf::Font();

  font->loadFromFile("font.ttf");
  dtDisplay.setFont(*font);
  dtDisplay.move({5, 25});
  dtDisplay.setCharacterSize(12);
}

int Game::exec() {
  start();
  while (window->isOpen()) {
    update();
    render();
    updateGame();
    dt = dtClock.restart().asSeconds();
  } 
  return 0;
}

void Game::render() {
  window->clear();

  renderGame();
  window->draw(dtDisplay);

  window->display();
}

void Game::update() {
  sf::Event evnt;
  while (window->pollEvent(evnt)) {
    if (evnt.type == sf::Event::Closed) {
      window->close();
    }
  }

  dtDisplay.setString(std::to_string(dt));
}


Game::~Game() {

}

} // namespace axe