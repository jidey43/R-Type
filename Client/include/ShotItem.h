#pragma once

#include "GameItem.h"

class ShotItem : public GameItem
{
public:
	ShotItem(sf::Vector2f, int distance, int time, int skin);
	~ShotItem();

public:
	void			setPosition(sf::Vector2f);
	void			update();

private:
	int				_distance;
	sf::Time		_timeReference;
	sf::Clock		_clock;
	sf::Vector2f	_startPos;
};