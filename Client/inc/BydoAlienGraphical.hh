#pragma once
# include "BydoAlien.hh"
# include "GraphicalItem.h"

class BydoAlienGraphical : public BydoAlien, public GraphicalItem
{
public:
  BydoAlienGraphical(sf::Vector2f speed, sf::Vector2f pos, unsigned int, float coeff);

public:
	bool				update();
  bool				update(std::vector<IObject*>&);
};
