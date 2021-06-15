#include "Bird.hpp"

namespace ChroMoZub
{
    Bird::Bird(GameDataRef data) : _data(data)
    {
        this->_birdSprite.setTexture(this->_data->assets.GetTexture("Bird Frame 1"));
    }

    Bird::~Bird() {

    }

    void Bird::Draw()
    {
        this->_data->window.draw(_birdSprite);

    }
  
  
}
