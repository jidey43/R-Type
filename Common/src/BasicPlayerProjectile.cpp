#include "BasicPlayerProjectile.hh"

BasicPlayerProjectile::BasicPlayerProjectile(sf::Vector2f speed,
					     sf::Vector2f pos,
					     unsigned int id,
					     uint32_t* score)
  : Projectile(speed, pos, sf::Vector2i(10,10), id, ObjectInfo::PLAYERREGULAR),
    _score(score)
{
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
  return true;
}

bool		BasicPlayerProjectile::update(sf::Clock const& clock, std::vector<IObject*>& map)
{
  this->update(clock);
  this->collision(map);
  return true;
}

void		BasicPlayerProjectile::increaseScore()
{
  // std::cout << "increase SCORE" << std::endl;
  if (_score)
    *_score += 10;
}
