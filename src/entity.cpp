#include "entity.hpp"
#include <iostream>

namespace axe {
  Entity::Entity(double h, double s, sf::String const& n) 
    : health(h), speed(s), name(n)
  {
    std::cout << "3";
    sprite = new sf::Sprite();
    sprite->setScale({2, 2});
    sprite->move(400,200);

    currentAnimation = 0;
  } 

  void Entity::draw(sf::RenderTarget& target, sf::RenderStates state) const
  {
      target.draw(*sprite, state);  
  }

  void Entity::update(float dt) {
    // ! NOTE
    entityAnimations[currentAnimation].update(0, dt);
    updateEntity(dt);
    
  } 

  Entity::~Entity() {
    delete sprite;
  };

};