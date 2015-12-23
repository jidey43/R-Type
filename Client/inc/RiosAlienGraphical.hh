#pragma once
# include "RiosAlien.hh"
# include "GraphicalItem.h"

class RiosAlienGraphical : public RiosAlien, public GraphicalItem
{
public:
  RiosAlienGraphical(sf::Vector2f speed, sf::Vector2f pos, unsigned int, float coeff);

public:
	bool				update(sf::Clock const&);
  bool				update(std::vector<IObject*>&, sf::Clock const&);
};
