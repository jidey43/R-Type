#pragma once

#include "BasicPlayerProjectile.hh"
#include "GraphicalItem.h"

class BasicPlayerProjectileGrapical : public BasicPlayerProjectile, public GraphicalItem
{
public:
	BasicPlayerProjectileGrapical(sf::Vector2f speed, sf::Vector2f pos, unsigned int id);
	bool			update(sf::Clock const&);
	bool			update(std::vector<IObject*>&, sf::Clock const&) {};
    
private:
   sf::Sound    _sound;

};
