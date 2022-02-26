#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>

namespace axe {
	class Entity;
	class Animation final {
	// Functions:
	public:
		Animation(Entity* entity, sf::String const& texture,sf::Vector2u imageCount,float switchTime);
		void update(int row,float deltaTime);
		~Animation();


	private:


	// Variables:
	public:
		sf::IntRect animRect; // Animation Integer rectangle 

	private:
		sf::Vector2u imageCount; // total image {x,y}
		sf::Vector2u currentImage; // image we are currently on {known_x,y}

		float totalTime;  // period of time since last switch was applied.
		float switchTime; // period of time takes to switch to another buffer

		sf::Texture* texture;
		Entity* entity;

	};
}
#endif