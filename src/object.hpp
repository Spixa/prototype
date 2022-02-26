#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>

namespace axe {
  class Object {
    public:
      explicit Object(sf::String const& name) : name(name) {}
      
    private:
      sf::String name;
  };
};

#endif