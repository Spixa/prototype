#ifndef SCENE_HPP
#define SCENE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <vector>
#include "entity.hpp"

namespace axe { 
  class Scene : public sf::Drawable {
    private:

    protected:
      std::vector<axe::Entity*> _entities;
  
    public:
     Scene();
     void start();
     void update(float dt) const;
     virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const;
  };

};

#endif