#include "Bird.hpp"

namespace ChroMoZub
{
Bird::Bird (GameDataRef data ) : this->_data( data )
{
  this->_birdSprite.setTexture( this->_data->assets.GetTexture( "Bird Frame 1"));
}
  void Bird::Draw( ) 
  {
    this->_data->window.draw( _birdSprite );
    
  }
  
  
}
