#ifndef _OBSTACLE_HH_
# define _OBSTACLE_HH_

# include "Alien.hh"

class Obstacle : public Alien
{
private:
  ObjectInfo::ObstacleType _obstacleType;

public:
  Obstacle(sf::Vector2f speed, sf::Vector2f pos, unsigned int id, float coeff, ObjectInfo::ObstacleType);
  ~Obstacle();

public:
  bool				update(sf::Clock const&, std::vector<IObject*>&);
  bool				update(sf::Clock const&);
  IObject	*BasicShoot();
  ObjectInfo::ObstacleType getObstacleType() const;
};

# endif
