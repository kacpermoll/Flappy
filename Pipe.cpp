#include "Pipe.hpp"
#include <iostream>

namespace ChroMoZub {
	Pipe::Pipe(GameDataRef data) : _data(data) 
	{
		_landHeight = _data->assets.GetTexture( "Land" ).getSize().y;
		_pipeSpawnYOffset = 0;
	}

	void Pipe::SpawnBottomPipe()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Pipe Up"));

		sprite.setPosition(this->_data->window.getSize().x, this->_data->window.getSize().y - sprite.getLocalBounds().height - _pipeSpawnYOffset);

		pipeSprites.push_back(sprite);
	}

	void Pipe::SpawnTopPipe()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Pipe Down"));

		sprite.setPosition(this->_data->window.getSize().x, -_pipeSpawnYOffset );

		pipeSprites.push_back(sprite);
	}

	//nie do koñca rozumiem jaki problem rozwi¹zuje niewidzialna rura (odcinek 12)
	void Pipe::SpawnInvisiblePipe()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Pipe Down"));

		sprite.setPosition(this->_data->window.getSize().x, 0);
		sprite.setColor(sf::Color(0, 0, 0, 0));

		pipeSprites.push_back(sprite);
	}

	void Pipe::MovePipes(float dt)
	{
		for (unsigned short int i = 0; i < pipeSprites.size(); i++)
		{
			//ten warunek usuwa rure z pamiêci jeœli wyjdzie poza ekran, aby nie zape³niaæ bezsensownie pamiêci
			//NIE MO¯NA USUN¥Æ RURY JAK TYLKO ZETKNIE SIÊ Z GRANIC¥, PONIEWA¯ WCZEŒNIEJ ZNIKNIE NI¯ CHCEMY (dlatego w warunku ...- pipeSprite().at(i)....
			if (pipeSprites.at(i).getPosition().x < 0 - pipeSprites.at(i).getGlobalBounds().width) {
				pipeSprites.erase(pipeSprites.begin() + i);
			}
			else {
				float movement = PIPE_MOVEMENT_SPEED * dt;

				pipeSprites.at(i).move(-movement, 0);
			}
		}

		std::cout << pipeSprites.size() << std::endl;
	}

	//rysowanie rur
	void Pipe::DrawPipes()
	{
		for (unsigned short int i = 0; i < pipeSprites.size(); i++)
		{
			this->_data->window.draw(pipeSprites.at(i));
		}
	}
        void Pipe::RandomisePipeOffset()
	{
		_pipeSpawnYOffset = rand() % ( _landHeight + 1);
		
	}

	
	
}
