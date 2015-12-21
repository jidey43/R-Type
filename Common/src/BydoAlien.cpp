#include "BydoAlien.hh"
#include "BasicAlienProjectile.hh"
#include <stdlib.h>

extern unsigned int _maxId;

BydoAlien::BydoAlien(sf::Vector2f speed, sf::Vector2f pos, unsigned int id, float coeff)
  : Alien(speed, pos, sf::Vector2i(70, 70), id, coeff)
{
  _speed.x = 4;
  _speed.y = 4;
  _realType = ObjectInfo::BYDO;
  _f = 3;
  _rad = 3;
  _a = 30;
}

BydoAlien::~BydoAlien()
{}

bool		BydoAlien::update(sf::Clock const& clock)
{
  this->_pos.x = this->_pos.x - this->_speed.x;
  this->_pos.y = _pos.y - (_a * cos((0.5 * _f * clock.getElapsedTime().asSeconds() * M_PI) + _rad));
  return true;
}

bool		BydoAlien::update(std::vector<IObject*> &map, sf::Clock const& clock)
{
  this->update(clock);
  map.push_back(this->BasicShoot());
  this->collision(map);
  return (_isAlive);
}

IObject		*BydoAlien::BasicShoot()
{
  sf::Vector2f pos;

  pos.x = _pos.x + _speed.x;
  pos.y = _pos.y;
  _maxId = _maxId + 1;
  _isShoot = true;
  return new BasicAlienProjectile(_speed, pos, _maxId);
}
