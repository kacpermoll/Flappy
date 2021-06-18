#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace ChroMoZub
{
	class GameOverState : public State
	{
	public:
		GameOverState(GameDataRef data, int score);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;

		sf::Sprite _gameOverTitle;
		sf::Sprite _gameOverContainer;
		sf::Sprite _retryButton;

		sf::Text _scoreText;
		sf::Text _highScoreText;

		//zmienne przechowuj¹ce aktualny wynik i rekordzik
		int _score;
		int _highScore;
	};
}