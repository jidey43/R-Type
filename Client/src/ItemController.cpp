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

void ItemController::addShip(CrePlayPacket *packet)
{
	CrePlayData *data = packet->getData();
	
  _items.emplace_back(new PlayerGraphical(sf::Vector2f(0,0), sf::Vector2f(data->x, data->y), data->id));
}

void ItemController::addObj(CreObjPacket *packet)
{
		
}

void ItemController::moveShip(MovePacket *packet)
{	
	
}

void ItemController::deleteObject(DelItemPacket *packet)
{
	int  id = packet->getData()->data;
	
	int i;
	for (i = 0; ((IObject*)_items[i])->getId() != id || i == _items.size(); i++);
	if (i == _items.size())
		return;
	_items.erase(_items.begin() + i);
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

void ItemController::addAlien(CreIAPacket *packet)
{
// 	switch (type)
// 	{
// 	case ObjectInfo::WaveType::BYDO :
// //	  _items.emplace_back(new BydoAlienGraphical(speed, pos, id, coeff));
// 		break;
// 	default:
// 		break;
// 	}
}

