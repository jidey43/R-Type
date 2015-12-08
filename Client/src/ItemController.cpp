#include "ItemController.hh"

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
		*vc << _ships[i];
	for (int i = 0; i != _shots.size(); i++)
		*vc << _shots[i];
}

void ItemController::update()
{
	for (int i = 0; i != _shots.size(); i++)
	{
			_shots[i]->update();
		//if (_shots[i]->die())
		//	_shots.erase(i);
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

void ItemController::addShot(sf::Vector2f startpos, int distance, int time, int skin)
{
	_shots.emplace_back(new ShotItem(startpos, distance, time, skin));
}
