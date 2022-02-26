#ifndef AXE_HPP
#define AXE_HPP

#include "game.hpp"
#include "scene.hpp"

namespace axe {
  class Axe : public axe::Game {
    private:
      Axe();
      ~Axe() {}

      static Axe* m_instance;

      void updateGame() const override;
      void renderGame() const override;
      void start() override;

      Scene scene;
    public:

      static Axe* getInstance();
  };
};

#endif