#pragma once
# include "YorkAlien.hh"
# include "GraphicalItem.h"

class YorkAlienGraphical : public YorkAlien, public GraphicalItem
{
public:
  YorkAlienGraphical(sf::Vector2f speed, sf::Vector2f pos, unsigned int, float coeff);

public:
	bool				update(sf::Clock const&);
  bool				update(std::vector<IObject*>&, sf::Clock const&);
};
