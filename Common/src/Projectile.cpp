#include "Projectile.hh"

Projectile::Projectile(sf::Vector2f speed, sf::Vector2f pos, sf::Vector2i size, unsigned int id, ObjectInfo::ShotType realType)
  : Object(speed, pos, size, ObjectInfo::Type::SHOT, id), _realType(realType)
{
}

Projectile::~Projectile() {}

bool		Projectile::update(sf::Clock const& clock)
{
  this->_pos.x = this->_pos.x + this->_speed.x;
}

bool		Projectile::update(std::vector<IObject*> &map, sf::Clock const& clock)
{
  this->update(clock);
  this->collision(map);
}

const ObjectInfo::ShotType	&Projectile::getRealType() const
{
  return _realType;
}
