#include "Player.hh"

Player::Player(sf::Vector2i pos)
{
  _objType = PLAYER;
  _size.x = 0; // a def
  _size.y = 0; // a def
  _pos = pos;
  _speed.x = 0;
  _speed.y = 0;
}

Player::~Player() {}

void		update()
{
}

IObject		*BasicShoot()
{
  sf::Vector2i	pos(_size.x + pos.x, _pos.y);
  IObject *shoot = new BasicPlayerProjectile(pos);
  
  return (shoot);
}
