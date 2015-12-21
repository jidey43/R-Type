#include "BasicPlayerProjectile.hh"

BasicPlayerProjectile::BasicPlayerProjectile(sf::Vector2f speed, sf::Vector2f pos, unsigned int id)
  : Projectile(speed, pos, sf::Vector2i(0,0), id, ObjectInfo::PLAYERREGULAR)
{}

BasicPlayerProjectile::~BasicPlayerProjectile()
{}

bool		BasicPlayerProjectile::update(sf::Clock const& clock)
{
  if (_pos.x + _size.x < 0 || _pos.x > MAP_SIZE_X
      || _pos.y + _size.y < 0 || _pos.y > MAP_SIZE_Y)
    {
      std::cout << "shot delete in " << _pos.x << " : " << _pos.y << std::endl;
      _isAlive = false;
    }
  this->_pos.x = this->_pos.x + this->_speed.x;
  // std::cout << "alive in " << _pos.x << " : " << _pos.y << std::endl;
 }

bool		BasicPlayerProjectile::update(std::vector<IObject*>& map, sf::Clock const& clock)
{
  this->update(clock);
  this->collision(map);
}
