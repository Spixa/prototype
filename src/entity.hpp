#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "animation.hpp"
#include <tuple>

namespace axe {

  class Entity : public sf::Drawable {    
    protected:
      double health;
      double speed;
      sf::String name;

      sf::Sprite* sprite;
      std::vector<Animation> entityAnimations;
      virtual void updateEntity(float dt) {}

      unsigned int currentAnimation;
    public:
      Entity(double, double, sf::String const&);
      sf::String getName() const { return name; }

      virtual ~Entity();

      void setPosition(const sf::Vector2f& pos) { sprite->setPosition(pos); }
      void move(const sf::Vector2f& pos) { sprite->move(pos); }

      virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const;

      void update(float dt);
      sf::Sprite* getSpritePtr() { return sprite; }
  };


}

#endif