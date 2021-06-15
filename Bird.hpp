#pragma once
#include <SFML/Graphics.hpp>
#include "Definitions.hpp

namespace ChroMoZub
{
class Bird
{
public:
Bird(GameData data );

void Draw ();

private:
GameDataRef this->_data;
sf::Sprite this->_birdSprite;

};

}
