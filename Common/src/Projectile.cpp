#include "Projectile.hh"

Projectile::Projectile(sf::Vector2f speed, sf::Vector2f pos, sf::Vector2i size, unsigned int id)
  : Object(speed, pos, size, ObjectInfo::Type::ALIEN, id)
{
}

Projectile::~Projectile() {}

bool		Projectile::update()
{
  this->_pos.x = this->_pos.x + this->_speed.x;
}

bool		Projectile::update(std::vector<IObject*> &map)
{
  this->update();
  this->collision(map);
}

const ObjectInfo::ShotType	&Projectile::getRealType() const
{
  return _realType;
}
