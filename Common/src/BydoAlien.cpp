#include "BydoAlien.hh"
#include "BasicAlienProjectile.hh"
#include <stdlib.h>

BydoAlien::BydoAlien(sf::Vector2f speed, sf::Vector2i pos, float coeff) : Alien(speed, pos, coeff)
{}

BydoAlien::~BydoAlien()
{}

void		BydoAlien::update()
{}

IObject		*BydoAlien::BasicShoot()
{ 
<<<<<<< HEAD
  sf::Vector2i pos;

  pos.x = _pos.x + _speed.x;
  pos.y = _pos.y;
  return new BasicAlienProjectile(_speed, pos, 1.0);
=======
	//debug
	
	return NULL;
>>>>>>> 802ffea06c62fe3665e96ee80064f0495108c129
}
