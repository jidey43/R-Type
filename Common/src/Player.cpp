#include "Player.hh"
#include <stdlib.h>

extern unsigned int _maxId;

Player::Player(sf::Vector2f speed, sf::Vector2f pos, unsigned int id)
  : Object(speed, pos, sf::Vector2i(0,0), ObjectInfo::PLAYER, id), _tryShoot(false)
{
}

Player::~Player()
{
}

bool		Player::update()
{
  _pos += _move;
}

bool		Player::update(std::vector<IObject*>& map)
{
  _pos += _move;
  this->collision(map);
}

IObject		*Player::BasicShoot()
{
  sf::Vector2f pos;

  pos.x = _pos.x + _size.x;
  pos.y = _pos.y;
  _maxId = _maxId + 1;
  return new BasicPlayerProjectile(_speed, pos, _maxId);
}

void		Player::tryShoot()
{
  _tryShoot = true;
}

void		Player::setDirection(Direction dir)
{
  _move = sf::Vector2f((dir == UP ? -_speed.y : (dir == DOWN ? _speed.y : 0)), (dir == LEFT ? -_speed.x : (dir == RIGHT ? _speed.x : 0)));
}
