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

void ItemController::setBackground(int id)
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
  int id = packet->getData()->id;
  sf::Vector2f newPos(packet->getData()->x ,packet->getData()->y);

  int i;
  for (i = 0; i != _items.size(); ++i)
    {
      if ((dynamic_cast<PlayerGraphical*>(_items[i])->getId()) == id)
	{
	  std::cout << "pos = " << newPos.x << " : " << newPos.y << std::endl;
	  break;
	}
    }
  if (i == _items.size())
    return;
  dynamic_cast<PlayerGraphical*>(_items[i])->setPos(newPos);
}

void ItemController::deleteObject(DelItemPacket *packet)
{
  int  id = packet->getData()->data;

  size_t i;
  for (i = 0; i != _items.size(); ++i)
    {
      if ((dynamic_cast<PlayerGraphical*>(_items[i])->getId()) == id)
	break;
    }
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
