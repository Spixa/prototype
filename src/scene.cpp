#include "scene.hpp"
#include "lumberjack.hpp"
#include <SFML/Graphics/RectangleShape.hpp>

namespace axe {
  Scene::Scene() {
    std::cout << "1";
    
  }

  void Scene::draw(sf::RenderTarget &target, sf::RenderStates state) const {
    for (auto x : _entities) {
      target.draw(*x, state) ;
    }
  }

  void Scene::start()  {
    _entities.push_back(new Lumberjack());
  }

  void Scene::update(float dt) const
  {
    for (auto x : _entities) {
      
      x->update(dt);
    } 
  }

}