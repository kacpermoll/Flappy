#include "Bird.hpp"

namespace ChroMoZub
{
    Bird::Bird(GameDataRef data) : _data(data)
    {
        _animationInterator = 0;
        _animationFrames.push_back(_data->assets.GetTexture("Bird Frame 1") );
        _animationFrames.push_back(_data->assets.GetTexture("Bird Frame 2") );
        _animationFrames.push_back(_data->assets.GetTexture("Bird Frame 3") );
        _animationFrames.push_back(_data->assets.GetTexture("Bird Frame 4") );
        
        this->_birdSprite.setTexture( _animationsFrames.at(_animationInterator));
        
    }

    Bird::~Bird() {

    }

    void Bird::Draw()
    {
        this->_data->window.draw(_birdSprite);

    }
    void Bird::Animate(float dt)
    {
     if (_clock.getElapsedTime().asSeconds( )>BIRD_ANIMATION_DURATION / _animationFrames.size() )    
     {
      if ( _animationInterator < _animationFrames.size( )-1)
      {
          _animationInterator++;
      }
      else
       {
             _animationIterator = 0;
       }
        _birdSprite.setTexture(_animationFrames.at(_animationInterator));
         
         _clock.restart( );
         
         
     }
    }
  
  
}
