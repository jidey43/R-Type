#pragma once

#include "SFML/Graphics.hpp"
#include "ViewController.h"

class                  GameItem
{
public:
	GameItem() {}
	virtual ~GameItem() {}

public:
	sf::Drawable*		getDrawable();
	sf::Vector2f		getPosition();
	virtual void		setPosition(sf::Vector2f) = 0;
	virtual void		update() = 0;

protected:
	sf::Sprite			*_sprite;
	sf::Vector2f		_position;
};