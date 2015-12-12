#pragma once

#include <vector>
#include "ViewController.hh"
#include "GraphicalItem.h"
#include "ObjectInfo.hpp"
#include "BydoAlienGraphical.hh"

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
	void						addShip(int id);
	void						moveShip(int id, sf::Vector2f);

public:
	void						addAlien(ObjectInfo::WaveType, sf::Vector2f speed, 
							sf::Vector2i pos, float coeff);

public:
	void						addShot(sf::Vector2f, int, int, int);

public:
	void						setBackgroud(int id);

private:
	std::vector<GraphicalItem*> _items;
	sf::Sprite*					_background;
};