#pragma once

#include "BasicPlayerProjectile.hh"
#include "GraphicalItem.h"

class BasicPlayerProjectileGrapical : public BasicPlayerProjectile, public GraphicalItem
{
public:
	BasicPlayerProjectileGrapical(sf::Vector2f speed, sf::Vector2i pos, float coeff);
	bool			update();
};
