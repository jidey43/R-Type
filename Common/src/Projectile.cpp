#include "Projectile.hh"

Projectile::Projectile(sf::Vector2f speed, sf::Vector2f pos, sf::Vector2i size, unsigned int id)
  : Object(speed, pos, size, ObjectInfo::Type::ALIEN, id)
{
}

Projectile::~Projectile() {}

bool		Projectile::update()
{
}
