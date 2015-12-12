#pragma once

#include <vector>
#include "ViewController.hh"
#include "GraphicalItem.h"
#include "ObjectInfo.hpp"
#include "BydoAlienGraphical.hh"
#include "BasicPlayerProjectileGraphical.h"
#include "BasicAlienProjectileGraphical.h"
#include "PlayerGraphical.h"

extern ViewController *vc;

class                           ItemController
{
public:
	ItemController();
	~ItemController();

public:
	void						draw();
	void						update();

public:
	void						addShip(sf::Vector2f speed, sf::Vector2i pos, float coeff);
	void						moveShip(int id, sf::Vector2f);

public:
	void						addAlien(ObjectInfo::WaveType, sf::Vector2f speed, 
							sf::Vector2i pos, float coeff);

public:
	void						addShot(Shot, sf::Vector2f speed, sf::Vector2i pos, float );

public:
	void						setBackgroud(int id);

private:
	std::vector<GraphicalItem*> _items;
	sf::Sprite*					_background;
};