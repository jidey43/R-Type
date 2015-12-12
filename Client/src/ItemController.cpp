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

void ItemController::addShip(sf::Vector2f speed, sf::Vector2i pos, float coeff)
{
	_items.emplace_back(new PlayerGraphical(speed, pos, coeff));
}

void ItemController::moveShip(int id, sf::Vector2f pos)
{
}

void ItemController::addShot(Shot type, sf::Vector2f speed, sf::Vector2i pos, float coeff)
{
	switch (type)
	{
	case BASICPLAYERSHOT:
		_items.emplace_back(new BasicPlayerProjectileGrapical(speed, pos, coeff));
		break;
	case BASICALIENSHOT:
		_items.emplace_back(new BasicAlienProjectileGrapical(speed, pos, coeff));
		break;

	default:
		break;
	}
}

void ItemController::addAlien(ObjectInfo::WaveType type, sf::Vector2f speed,
	sf::Vector2i pos, float coeff)
{
	switch (type)
	{
	case ObjectInfo::WaveType::BYDO :
		_items.emplace_back(new BydoAlienGraphical(speed, pos, coeff));
		break;
	default:
		break;
	}
}

