#include "BydoAlien.hh"
#include "BasicAlienProjectile.hh"
#include <stdlib.h>

extern unsigned int _maxId;

BydoAlien::BydoAlien(sf::Vector2f speed, sf::Vector2f pos, unsigned int id, float coeff)
  : Alien(speed, pos, sf::Vector2i(100, 100), id, coeff)
{
  _speed.x = 4;
  _speed.y = 4;
  _realType = ObjectInfo::BYDO;
  _f = 3;
  _rad = 3;
  _a = 3;
}

BydoAlien::~BydoAlien()
{
}

bool		BydoAlien::update(sf::Clock const& clock)
{
  this->_pos.x = this->_pos.x - this->_speed.x;
  this->_pos.y = _pos.y - (_a * cos((0.23 * _f * clock.getElapsedTime().asSeconds() * M_PI) + _rad));
  if ((int)(_pos.x) % 400 == 0)
    _isShoot = true;
  return true;
}

bool		BydoAlien::update(sf::Clock const& clock, std::vector<IObject*> &map)
{
  this->update(clock);
  this->collision(map);
  return (_isAlive);
}

IObject		*BydoAlien::BasicShoot()
{
  sf::Vector2f pos;

  pos.x = _pos.x + _size.x;
  pos.y = _pos.y + _size.y;
  _isShoot = false;
  return new BasicAlienProjectile(_speed, pos, _maxId++);
}
