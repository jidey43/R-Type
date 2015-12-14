# include "BasicAlienProjectile.hh"

BasicAlienProjectile::BasicAlienProjectile(sf::Vector2f speed, sf::Vector2f pos, unsigned int id)
  : Projectile(speed, pos, sf::Vector2i(0,0), id)
{}

BasicAlienProjectile::~BasicAlienProjectile()
{}

bool		BasicAlienProjectile::update()
{}

bool		BasicAlienProjectile::update(std::vector<IObject*>&)
{
}
