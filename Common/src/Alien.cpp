#include "Alien.hh"

Alien::Alien(sf::Vector2f speed, sf::Vector2f pos, sf::Vector2i size, unsigned int id, float coeff)
  : Object(speed, pos, size, ObjectInfo::Type::ALIEN, id), _coeff(coeff)
{}

Alien::~Alien() {}

bool		Alien::update()
{
}

ObjectInfo::WaveType	Alien::getRealType() const
{
  return _realType;
}
