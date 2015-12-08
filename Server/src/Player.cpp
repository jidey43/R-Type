#include "Player.hh"

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
  //sf::Vector2i	pos(_size.x + _pos.x, _pos.y);
  //IObject *shoot = new BasicPlayerProjectile(_pos);
  
  //return (shoot);
}
