#include "DokanAlien.hh"
#include "BasicAlienProjectile.hh"
#include <stdlib.h>

DokanAlien::DokanAlien(sf::Vector2f speed, sf::Vector2i pos, float coeff) : Alien(speed, pos, coeff)
{}

DokanAlien::~DokanAlien()
{}

bool	        DokanAlien::update()
{}

IObject		*DokanAlien::BasicShoot()
{
  sf::Vector2i pos;

  pos.x = _pos.x + _speed.x;
  pos.y = _pos.y;
  return new BasicAlienProjectile(_speed, pos, 1.0);
}
