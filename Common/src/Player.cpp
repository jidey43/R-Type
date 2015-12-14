#include "Player.hh"
#include <stdlib.h>

Player::Player(sf::Vector2f speed, sf::Vector2f pos, int id)
  : Object(speed, pos, ObjectInfo::PLAYER, id), _tryShoot(false)
{
}

Player::~Player()
{
}

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

void		tryShoot()
{
  _tryShoot = true;
}

void		setDirection(Direction dir)
{
  _dir = dir;
}
