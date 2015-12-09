#pragma once
# include "BydoAlien.hh"
# include "GraphicalItem.h"

class BydoAlienGraphical : public BydoAlien, public GraphicalItem
{
public:
	BydoAlienGraphical(sf::Vector2f speed, sf::Vector2i pos, float coeff);

public:
	void				update();
};