#ifndef LUMBERJACK_HPP
#define LUMBERJACK_HPP

#include "entity.hpp"
#include <vector>
#include <tuple>
#include "animation.hpp"
#include <iostream>

namespace axe {
  class Lumberjack : public Entity {
    public:
    Lumberjack() : Entity(20, 5, "lumberjack") {

      entityAnimations.push_back(Animation(this, "idle.png", {4, 1}, 0.1)); // 0
      entityAnimations.push_back(Animation(this, "run.png", {6, 1}, 0.1)); // 1
      entityAnimations.push_back(Animation(this, "attack.png", {6, 1}, 0.1)); // 3
      entityAnimations.push_back(Animation(this, "walk.png", {6, 1}, 0.1)); // 2



    }
    ~Lumberjack() {
      
    }
    
    
    void updateEntity(float dt) override {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
        currentAnimation = 0;
      } else
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
        currentAnimation = 1;
      } else
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
        currentAnimation = 2;
      } else
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
        currentAnimation = 3;
      }
    }
  };
};

#endif