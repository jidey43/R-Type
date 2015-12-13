#pragma once
#include "Player.hh"
#include "GraphicalItem.h"

class PlayerGraphical : public Player, public GraphicalItem
{
public:
  PlayerGraphical(sf::Vector2f speed, sf::Vector2i pos, float coeff, int id);
	bool		update();
};
