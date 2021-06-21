#pragma once
#include <SFML/Graphics.hpp>

#include "Definitions.hpp"
#include "Game.hpp"

namespace ChroMoZub
{
	class HUD
	{
	public:
		HUD(GameDataRef data);
		~HUD();
		void Draw();
		void UpdateScore(int score);

	private:
		GameDataRef _data;

		//obiekt wyswietlajacy tekst
		sf::Text _scoreText;
	};
}