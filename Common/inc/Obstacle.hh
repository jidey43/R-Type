#ifndef _OBSTACLE_HH_
# define _OBSTACLE_HH_

# include <cmath>
# include "Object.hh"

class Obstacle : public Object
{
public:
  Obstacle(sf::Vector2f, sf::Vector2f, sf::Vector2i, unsigned int);
  ~Obstacle();

public:
  bool				update(std::vector<IObject*>&, sf::Clock const&);
  bool				update(sf::Clock const&);
};

# endif
