#include "GlamAlien.hh"
#include "BasicAlienProjectile.hh"
#include <stdlib.h>

extern unsigned int _maxId;

GlamAlien::GlamAlien(sf::Vector2f speed, sf::Vector2f pos, unsigned int id, float coeff)
  : Alien(speed, pos, sf::Vector2i(0, 0), id, coeff)
{}

GlamAlien::~GlamAlien()
{}


bool		GlamAlien::update(std::vector<IObject*>&, sf::Clock const&)
{
}

bool		GlamAlien::update(sf::Clock const&)
{
}

IObject		*GlamAlien::BasicShoot()
{
  sf::Vector2f pos;

  pos.x = _pos.x + _speed.x;
  pos.y = _pos.y;
  _maxId = _maxId + 1;
  return new BasicAlienProjectile(_speed, pos, 1);
}
