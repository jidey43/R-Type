#pragma once
#include "Player.hh"
#include "GraphicalItem.h"

class PlayerGraphical : public Player, public GraphicalItem
{
public:
  PlayerGraphical(sf::Vector2f speed, sf::Vector2f pos, unsigned int id);
  bool		update(std::vector<IObject*>&, sf::Clock const&);
  bool		update(sf::Clock const&);
};
