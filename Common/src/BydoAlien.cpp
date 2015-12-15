#include "BydoAlien.hh"
#include "BasicAlienProjectile.hh"
#include <stdlib.h>

extern unsigned int _maxId;

BydoAlien::BydoAlien(sf::Vector2f speed, sf::Vector2f pos, unsigned int id, float coeff)
  : Alien(speed, pos, sf::Vector2i(0, 0), id, coeff)
{
  _f = 50;
  _rad = 6;
  _t = 1;
  _a = 2;
}

BydoAlien::~BydoAlien()
{}

bool		BydoAlien::update()
{}

bool		BydoAlien::update(std::vector<IObject*> &map)
{
  this->pos.x = this->pos.x + this->speed.x;
  this->pos.y = _a * sin((2 * _f * _t * M_PI) + _rad);  
  _t = _t + 1;
  map.push_back(this->BasicShoot());
}

IObject		*BydoAlien::BasicShoot()
{
  sf::Vector2f pos;

  pos.x = _pos.x + _speed.x;
  pos.y = _pos.y;
  _maxId = _maxId + 1;
  return new BasicAlienProjectile(_speed, pos, _maxId);
}
