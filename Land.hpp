#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace ChroMoZub {
	class Land {
	public:
		Land(GameDataRef data);

		void MoveLand(float dt);
		void DrawLand();
	private:
		GameDataRef _data;
		
		//vector zawieraj�cy tekstury pod�o�y
		std::vector<sf::Sprite> _landSprites;


	};
}