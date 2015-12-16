#include "BasicPlayerProjectile.hh"

BasicPlayerProjectile::BasicPlayerProjectile(sf::Vector2f speed, sf::Vector2f pos, unsigned int id)
  : Projectile(speed, pos, sf::Vector2i(0,0), id)
{}

BasicPlayerProjectile::~BasicPlayerProjectile()
{}

bool		BasicPlayerProjectile::update(sf::Clock const& clock)
{
  this->_pos.x = this->_pos.x + this->_speed.x;
}

bool		BasicPlayerProjectile::update(std::vector<IObject*>& map, sf::Clock const& clock)
{
  this->update(clock);
  this->collision(map);
}
