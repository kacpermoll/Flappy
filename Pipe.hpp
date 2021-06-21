#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>
#include "Definitions.hpp"

namespace ChroMoZub {
	class Pipe {
	public:
		Pipe(GameDataRef data);

		void SpawnBottomPipe();
		void SpawnTopPipe();
		void SpawnInvisiblePipe();
		void SpawnScoringPipe();
		void MovePipes(float dt);
		//funkcja odpowiedzialna za rysowanie rur
		void DrawPipes();
		void RandomisePipeOffset();

		const std::vector<sf::Sprite>& GetSprites() const;
		std::vector<sf::Sprite>& GetScoringSprites();

	private:
		GameDataRef _data;

		//vector zawierajacy wszystkie stworzone rury
		std::vector<sf::Sprite> pipeSprites;
		std::vector<sf::Sprite> scoringPipes;

		int _landHeight;
		int _pipeSpawnYOffset;

	};
}