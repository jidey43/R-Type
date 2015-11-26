#pragma once

#include <vector>
#include "ShipItem.h"
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

private:
	std::vector<ShipItem*>		_ships;
};