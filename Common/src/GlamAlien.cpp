#include "GlamAlien.hh"
#include "BasicAlienProjectile.hh"
#include <stdlib.h>

extern unsigned int _maxId;

GlamAlien::GlamAlien(sf::Vector2f speed, sf::Vector2f pos, unsigned int id, float coeff)
  : Alien(speed, pos, sf::Vector2i(0, 0), id, coeff)
{
  _f = 50;
  _rad = 6;
  _t = 1;
  _a = 10;
}

GlamAlien::~GlamAlien()
{}

bool	        GlamAlien::update()
{
  this->_pos.x = this->_pos.x + this->_speed.x;
  this->_pos.y = _a * sin((2 * _f * _t * M_PI) + _rad);
  _t = _t + 1;
  return true;
}

bool		GlamAlien::update(std::vector<IObject*> &map)
{
  this->update();
  this->collision(map);
  return (_isAlive);
}

IObject		*GlamAlien::BasicShoot()
{
  sf::Vector2f pos;

  pos.x = _pos.x + _speed.x;
  pos.y = _pos.y;
  _maxId = _maxId + 1;
  return new BasicAlienProjectile(_speed, pos, 1);
}
