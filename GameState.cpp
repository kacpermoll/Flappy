#include <sstream>
#include "GameState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace ChroMoZub
{
	GameState::GameState(GameDataRef data) : _data(data)
	{
		
	}

	void GameState::Init()
	{
		std::cout << "Game State" << std::endl;
		this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);

		_data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
		_data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);

		_data->assets.LoadTexture("Land", LAND_FILEPATH);
		_data->assets.LoadTexture("Bird Frame 1", BIRD_FRAME_1_FILEPATH );
		_data->assets.LoadTexture("Bird Frame 2", BIRD_FRAME_2_FILEPATH );
		_data->assets.LoadTexture("Bird Frame 3", BIRD_FRAME_3_FILEPATH );
		_data->assets.LoadTexture("Bird Frame 4", BIRD_FRAME_4_FILEPATH );
			
		
		pipe = new Pipe(_data);
		land = new Land(_data);
		bird = new Bird(_data);

		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
	}

	void GameState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (_data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window))
			{
				
			}

		}
	}

	void GameState::Update(float dt)
	{
		pipe->MovePipes(dt);
		land-> MoveLand(dt);
		bird->Draw( );  	
		//jeœli minie okreœlony czas (na odstêp pomiêdzy rurami to stwórz now¹ rurê)
		if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
			pipe->RandomisePipeOffset( );
			pipe->SpawnInvisiblePipe();
			pipe->SpawnBottomPipe();
			pipe->SpawnTopPipe();

			clock.restart();
		}
		bird->Animate( dt );

	}

	void GameState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);

		pipe->DrawPipes();
		land->DrawLand();

		this->_data->window.display();
	}
}
