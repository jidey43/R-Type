#pragma once

#include "SFML/Graphics.hpp"

class                  GameItem
{
public:
	GameItem() {}
	virtual ~GameItem() {}

private:
	sf::Sprite			mySprite;
};