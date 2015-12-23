#pragma once
# include "Xelf16Alien.hh"
# include "GraphicalItem.h"

class Xelf16AlienGraphical : public Xelf16Alien, public GraphicalItem
{
public:
  Xelf16AlienGraphical(sf::Vector2f speed, sf::Vector2f pos, unsigned int, float coeff);

public:
	bool				update(sf::Clock const&);
  bool				update(std::vector<IObject*>&, sf::Clock const&);
};
