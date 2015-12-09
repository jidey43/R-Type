#include "ItemController.hh"

ItemController::ItemController()
{
	_background = new sf::Sprite;
}

ItemController::~ItemController()
{	
}

void ItemController::draw()
{
	if (_background->getTexture() != NULL)
		vc->draw(_background);
	for (GraphicalItem *i : _items)
		vc->draw(i->getDrawable());
}

void ItemController::update()
{
	for (GraphicalItem* i : _items)
		i->update();
}

void ItemController::setBackgroud(int id)
{
	_background->setTexture(*(ac->getBackground(id)));
}

void ItemController::addShip(int id)
{
}

void ItemController::moveShip(int id, sf::Vector2f pos)
{
}

void ItemController::addShot(sf::Vector2f startpos, int distance, int time, int skin)
{
}

void ItemController::addAlien(ObjectInfo::WaveType type, sf::Vector2f speed,
	sf::Vector2i pos, float coeff)
{
	switch (type)
	{
	case ObjectInfo::WaveType::BYDO :
		_items.emplace_back(new BydoAlienGraphical(speed, pos, coeff));
		break;
	}
}

