#include "Player.hh"
#include <stdlib.h>

Player::Player(sf::Vector2f speed, sf::Vector2i pos, float coeff, int id) : Object(speed, pos, coeff), _id(id)
{
  _objType = ObjectInfo::PLAYER;
}

Player::~Player() {}

bool		Player::update()
{
}

IObject		*Player::BasicShoot()
{
  sf::Vector2i pos;
  
  pos.x = _pos.x + _size.x;
  pos.y = _pos.y;
  return new BasicPlayerProjectile(_speed, pos, 1.0);
}
