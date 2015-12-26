#include <stdlib.h>
#include "BydoAlien.hh"
#include "BasicAlienProjectile.hh"

extern unsigned int _maxId;

BydoAlien::BydoAlien(sf::Vector2f const& speed, sf::Vector2f const& pos, unsigned int id, float coeff)
  : Alien(speed, pos, sf::Vector2i(100, 100), id, coeff)
{
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
  if (_pos.x + _size.x < 0 || _pos.x > MAP_SIZE_X
      || _pos.y + _size.y < 0 || _pos.y > MAP_SIZE_Y)
    _isAlive = false;
  this->_pos.x = this->_pos.x - this->_speed.x;
  this->_pos.y = _pos.y - (_a * cos((0.23 * _f * (this->_pos.x / 150) * M_PI) + _rad));
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
  sf::Vector2f speed;

  pos.x = _pos.x  - (_size.x / 2);
  pos.y = _pos.y - (_size.y / 2);
  _isShoot = false;
  speed.x = _speed.y + (_speed.y / 3);
  speed.y = speed.x;
  return new BasicAlienProjectile(speed, pos, _maxId++);
}
