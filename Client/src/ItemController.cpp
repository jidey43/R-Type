#include "ItemController.hh"

ItemController::ItemController()
{
	_background = new sf::Sprite;
	_playerCount = 1;
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

void ItemController::addShip(sf::Vector2f speed, sf::Vector2f pos, unsigned int id)
{
  _items.emplace_back(new PlayerGraphical(speed, pos, id));
}

void ItemController::moveShip(int id, sf::Vector2f pos)
{
}

void ItemController::addShot(Shot type, sf::Vector2f speed, sf::Vector2f pos, unsigned int id)
{
	switch (type)
	{
	case BASICPLAYERSHOT:
		_items.emplace_back(new BasicPlayerProjectileGrapical(speed, pos, id));
		break;
	case BASICALIENSHOT:
		_items.emplace_back(new BasicAlienProjectileGrapical(speed, pos, id));
		break;

	default:
		break;
	}
}

void ItemController::addAlien(ObjectInfo::WaveType type, sf::Vector2f speed,
			      sf::Vector2f pos, unsigned int id, float coeff)
{
	switch (type)
	{
	case ObjectInfo::WaveType::BYDO :
	  _items.emplace_back(new BydoAlienGraphical(speed, pos, id, coeff));
		break;
	default:
		break;
	}
}

