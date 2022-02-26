#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <string>

namespace axe {
  class Game {
    private:
      float dt{0};
      sf::Clock dtClock;
    
      sf::Text dtDisplay{};
      sf::Font* font;

      const sf::String defaultTitle;
      const int defaultWidth;
      const int defaultHeight;
      
      
     
      void update();
      void render();
    protected:
     bool init = false;
      void initWindow();
      virtual void updateGame() const = 0;
      virtual void renderGame() const = 0;
      virtual void start() = 0;
    public:
      virtual ~Game();
      Game(sf::String const&,int const&, int const&);

      float getDeltaTime() const { return dt; }

      int exec();
      sf::RenderWindow* window;
  };
};
#endif