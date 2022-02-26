#include "axe.hpp"
#include <iostream>

namespace axe {

Axe* Axe::m_instance = nullptr;

Axe* Axe::getInstance() { 
  if (!m_instance) {
    m_instance = new Axe();
  }
  return m_instance;
}

Axe::Axe() : Game("axe", 800, 400) , scene() {

}

void Axe::start() {

  std::cout << "0";
  scene.start();

}

void Axe::updateGame() const {
  scene.update(getDeltaTime());
}

void Axe::renderGame() const {
  window->draw(scene);
}

}; // namespace axe