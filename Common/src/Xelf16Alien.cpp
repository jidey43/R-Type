#include "Xelf16Alien.hh"
#include "BasicAlienProjectile.hh"
#include <stdlib.h>

extern unsigned int _maxId;

Xelf16Alien::Xelf16Alien(sf::Vector2f speed, sf::Vector2f pos, unsigned int id, float coeff)
  : Alien(speed, pos, sf::Vector2i(100, 100), id, coeff)
{
  _life = 50;
  _realType = ObjectInfo::XELF16;
  _a = 10;
}

Xelf16Alien::~Xelf16Alien()
{}

bool		Xelf16Alien::update(sf::Clock const& clock)
{
  this->_pos.y = _a * cos((2 * _f * clock.getElapsedTime().asMicroseconds() * M_PI) + _rad);
  if ((int)(_pos.x) % 400 == 0)
    _isShoot = true;
  return true;
}


bool	        Xelf16Alien::update(sf::Clock const& clock, std::vector<IObject*>& map)
{
  this->update(clock);
  this->collision(map);
  return (_isAlive);
}

IObject		*Xelf16Alien::BasicShoot()
{
  sf::Vector2f pos;

  pos.x = _pos.x + _speed.x;
  pos.y = _pos.y;
  if ((int)(_pos.x) % 400 == 0)
    _isShoot = true;
  return new BasicAlienProjectile(_speed, pos, _maxId++);
}
