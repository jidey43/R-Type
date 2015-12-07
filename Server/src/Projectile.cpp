#include "Projectile.hh"

Projectile::Projectile(sf::Vector2f speed, sf::Vector2i pos, float coeff)
  : Object(speed, pos, coeff)
{
}

Projectile::~Projectile() {}

void		update()
{
}
