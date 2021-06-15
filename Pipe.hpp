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

	private:
		GameDataRef _data;

		//vector zawierający wszystkie stworzone rury
		std::vector<sf::Sprite> pipeSprites;
	};
}