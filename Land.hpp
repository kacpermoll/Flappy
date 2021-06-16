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

		const std::vector<sf::Sprite>& GetSprites() const;

	private:
		GameDataRef _data;

		//vector zawierajacy tekstury podlozy
		std::vector<sf::Sprite> _landSprites;


	};
}