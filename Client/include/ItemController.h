#pragma once

#include <vector>
#include "ShipItem.h"
#include "ShotItem.h"
#include "ViewController.h"

extern ViewController *vc;

class                           ItemController
{
public:
	ItemController();
	~ItemController();

public:
	void						draw();

public:
	void						addShip(int id);
	void						moveShip(int id, sf::Vector2f);

public:
	void						addShot(int, int, int);

public:
	void						setBackgroud(int id);

private:
	std::vector<ShipItem*>		_ships;
	std::vector<ShotItem*>		_shots;
	sf::Sprite*					_background;
};