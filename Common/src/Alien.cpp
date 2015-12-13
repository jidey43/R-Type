#include "Alien.hh"

Alien::Alien(sf::Vector2f speed, sf::Vector2i pos, float coeff) : Object(speed, pos, coeff)
{
  _objType = ObjectInfo::ALIEN;
}

Alien::~Alien() {}

bool		Alien::update()
{
}
