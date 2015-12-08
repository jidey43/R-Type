#include "Player.hh"
#include <stdlib.h>

Player::Player(sf::Vector2f speed, sf::Vector2i pos, float coeff) : Object(speed, pos, coeff)
{ 
  _objType = ObjectInfo::PLAYER;
}

Player::~Player() {}

void		Player::update()
{
}

IObject		*Player::BasicShoot()
{
<<<<<<< HEAD
  sf::Vector2i pos;
  
  pos.x = _pos.x + _size.x;
  pos.y = _pos.y;
  return new BasicPlayerProjectile(_speed, pos, 1.0);
=======
  //sf::Vector2i	pos(_size.x + _pos.x, _pos.y);
  //IObject *shoot = new BasicPlayerProjectile(_pos);
	return NULL;
  //return (shoot);
>>>>>>> 802ffea06c62fe3665e96ee80064f0495108c129
}
