#pragma once
#include <SFML/Graphics.hpp>
#include "Definitions.hpp"
#include "Game.hpp"

namespace ChroMoZub
{
	class Bird
	{
	public:
		Bird(GameDataRef data);
		~Bird();
		void Draw();

	private:
		GameDataRef _data;
		sf::Sprite _birdSprite;

	};

}
