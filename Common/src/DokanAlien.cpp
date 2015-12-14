#include "DokanAlien.hh"
#include "BasicAlienProjectile.hh"
#include <stdlib.h>

extern unsigned int _maxId;

DokanAlien::DokanAlien(sf::Vector2f speed, sf::Vector2f pos, unsigned int id, float coeff)
  : Alien(speed, pos, sf::Vector2i(0, 0), id, coeff) 
{}

DokanAlien::~DokanAlien()
{}

bool	        DokanAlien::update()
{}

bool		DokanAlien::update(std::vector<IObject*>&)
{
}

IObject		*DokanAlien::BasicShoot()
{
  sf::Vector2f pos;

  pos.x = _pos.x + _speed.x;
  pos.y = _pos.y;
  _maxId = _maxId + 1;
  return new BasicAlienProjectile(_speed, pos, _maxId);
}
