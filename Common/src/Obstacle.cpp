#include "Obstacle.hh"
#include "BasicAlienProjectile.hh"
#include <stdlib.h>

extern unsigned int _maxId;

Obstacle::Obstacle(sf::Vector2f speed, sf::Vector2f pos, unsigned int id, float coeff, ObjectInfo::ObstacleType obstacleType)
  : Alien(speed, pos, sf::Vector2i(70, 70), id, coeff)
{
  _speed.x = 4;
  _speed.y = 4;
  _realType = ObjectInfo::OBSTACLE;

  switch (obstacleType)
  {

  }
}

Obstacle::~Obstacle()
{
}

bool		Obstacle::update(sf::Clock const& clock)
{
  this->_pos.x = this->_pos.x - this->_speed.x;
  return true;
}

bool		Obstacle::update(sf::Clock const& clock, std::vector<IObject*> &map)
{
  this->update(clock);
  return (_isAlive);
}

IObject		*Obstacle::BasicShoot()
{
  return (NULL);
}
