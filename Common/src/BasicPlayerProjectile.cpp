#include "BasicPlayerProjectile.hh"

BasicPlayerProjectile::BasicPlayerProjectile(sf::Vector2f speed, sf::Vector2f pos, unsigned int id)
  : Projectile(speed, pos, sf::Vector2i(10,10), id, ObjectInfo::PLAYERREGULAR)
{
  std::cout << "pos shot : " << pos.x << "  " << pos.y << std::endl;
}

BasicPlayerProjectile::~BasicPlayerProjectile()
{}

bool		BasicPlayerProjectile::update(sf::Clock const& clock)
{
  if (_pos.x + _size.x < 0 || _pos.x > MAP_SIZE_X
      || _pos.y + _size.y < 0 || _pos.y > MAP_SIZE_Y)
    {
      _isAlive = false;
    }
  this->_pos.x = this->_pos.x + this->_speed.x;
 }

bool		BasicPlayerProjectile::update(std::vector<IObject*>& map, sf::Clock const& clock)
{
  this->update(clock);
  this->collision(map);
}
