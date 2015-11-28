#include "Projectile.hh"

Projectile::Projectile(ObjectInfo::Type type, sf::Vector2i pos)
{
  _size.x = 0; // a def
  _size.y = 0; // a def
  _pos = pos;
  _speed.x = 0;
  _speed.y = 0;
}

Projectile::~Projectile() {}

void		update()
{
}
