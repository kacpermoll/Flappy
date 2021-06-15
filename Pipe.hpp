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
		void MovePipes(float dt);
		//funkcja odpowiedzialna za rysowanie rur
		void DrawPipes();
		void RandomisePipeOffset();

	private:
		GameDataRef _data;

		//vector zawieraj¹cy wszystkie stworzone rury
		std::vector<sf::Sprite> pipeSprites;
		
		int _landHeight;
		int _pipeSpawnYOffset;
		
	};
}
