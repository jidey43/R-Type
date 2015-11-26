#include "ItemController.h"

ItemController::ItemController()
{
}

ItemController::~ItemController()
{
}

void ItemController::draw()
{
	for (int i = 0; i != _ships.size(); i++)
	{
		*vc << _ships[i];
	}
}

void ItemController::addShip(int id)
{
	_ships.push_back(new ShipItem(id));
}
