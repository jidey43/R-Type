#pragma once

#include "BasicAlienProjectile.hh"
#include "GraphicalItem.h"

class BasicAlienProjectileGrapical : public BasicAlienProjectile, public GraphicalItem
{
public:
	BasicAlienProjectileGrapical(sf::Vector2f speed, sf::Vector2i pos, float coeff);
	bool			update();
};
