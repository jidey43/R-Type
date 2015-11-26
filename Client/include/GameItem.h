#pragma once

#include "SFML/Graphics.hpp"

class                  GameItem
{
public:
	GameItem() {}
	virtual ~GameItem() {}

public:
	sf::Drawable*		getDrawable();

protected:
	sf::Sprite			*_sprite;
};