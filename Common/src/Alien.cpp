#include "Alien.hh"

extern unsigned int _maxId;

Alien::Alien(sf::Vector2f speed, sf::Vector2f pos, sf::Vector2i size, unsigned int id, float coeff)
  : Object(speed, pos, size, ObjectInfo::Type::ALIEN, id), _coeff(coeff)
{}

Alien::~Alien() {}

bool		Alien::update(std::vector<IObject*>& map, sf::Clock const& clock)
{
}

bool		Alien::update(sf::Clock const& clock)
{
}

const ObjectInfo::WaveType	&Alien::getRealType() const
{
  return _realType;
}

IObject		*Alien::BasicShoot()
{
  sf::Vector2f pos;

  pos.x = _pos.x + _size.x;
  pos.y = _pos.y + _size.y;
  _isShoot = false;
  return new BasicAlienProjectile(_speed, pos, _maxId++);
}
