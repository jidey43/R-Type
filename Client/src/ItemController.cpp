#include "ItemController.h"

ItemController::ItemController()
{
	_background = new sf::Sprite;
}

ItemController::~ItemController()
{
	for (int i = 0; i != _ships.size(); i++)
		delete _ships[i];
	delete _background;
}

void ItemController::draw()
{
	if (_background->getTexture() != NULL)
		vc->draw(_background);
	for (int i = 0; i != _ships.size(); i++)
	{
		*vc << _ships[i];
	}
}

void ItemController::setBackgroud(int id)
{
	_background->setTexture(*(ac->getBackground(id)));
}

void ItemController::addShip(int id)
{
	_ships.push_back(new ShipItem(id));
}

void ItemController::moveShip(int id, sf::Vector2f pos)
{
	_ships[id - 1]->setPosition(pos);
}

void ItemController::addShot(int, int, int)
{
}
