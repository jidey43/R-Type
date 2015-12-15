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
  _move = sf::Vector2f(0,0);
  return true;
}

bool		Player::update(std::vector<IObject*>& map)
{
  _pos += _move;
  _move = sf::Vector2f(0,0);
  this->collision(map);
  return true;
}

IObject		*Player::BasicShoot()
{
  sf::Vector2f pos;

  pos.x = _pos.x + _size.x;
  pos.y = _pos.y;
  _maxId = _maxId + 1;
  _isShoot = true;
  return new BasicPlayerProjectile(_speed, pos, _maxId);
}

bool		Player::tryShoot()
{
  _tryShoot = true;
  return true;
}

void		Player::setDirection(Direction dir)
{
  _move = sf::Vector2f((dir == LEFT ? -_speed.x : (dir == RIGHT ? _speed.x : 0)), (dir == UP ? -_speed.y : (dir == DOWN ? _speed.y : 0)));
}
