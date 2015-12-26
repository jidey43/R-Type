#include "Xelf16Alien.hh"
#include "BasicAlienProjectile.hh"
#include <stdlib.h>

extern unsigned int _maxId;

Xelf16Alien::Xelf16Alien(sf::Vector2f const& speed, sf::Vector2f const& pos, unsigned int id, float coeff)
  : Alien(speed, pos, sf::Vector2i(500, 500), id, coeff)
{
  _bossFactor = _pos.x;
  _life = 50;
  _realType = ObjectInfo::XELF16;
  _f = 3;
  _a = 5;
  _rad = 3;
}

Xelf16Alien::~Xelf16Alien()
{}

bool		Xelf16Alien::update(sf::Clock const& clock)
{
  if (_pos.x + _size.x < 0 || _pos.x > MAP_SIZE_X
      || _pos.y + _size.y < 0 || _pos.y > MAP_SIZE_Y)
    _isAlive = false;
  if (_pos.x > 1400)
    this->_pos.x = this->_pos.x - this->_speed.x;
  _bossFactor -= _speed.x;
  this->_pos.y = _pos.y - (_a * cos((0.23 * _f * (_bossFactor / 150) * M_PI) + _rad));
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
  sf::Vector2f speed;

  pos.x = _pos.x  - (_size.x / 2);
  pos.y = _pos.y - (_size.y / 2);
  _isShoot = false;
  speed.x = _speed.y + (_speed.y / 3);
  speed.y = speed.x;
  return new BasicAlienProjectile(speed, pos, _maxId++);
}
