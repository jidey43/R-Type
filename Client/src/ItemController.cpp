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
    i->update(_clock);
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
	int id = packet->getData()->id;
	sf::Vector2f pos(packet->getData()->x, packet->getData()->y);
	float speed = packet->getData()->speed;

	std::cout << "adding object type = " << packet->getData()->type << " and speed " << speed << std::endl;

	if (packet->getData()->type == ObjectInfo::PLAYERREGULAR)
		_items.emplace_back(new BasicPlayerProjectileGrapical(sf::Vector2f(speed, speed), pos, (unsigned int)id));
	if (packet->getData()->type == ObjectInfo::ALIENREGULAR)
		_items.emplace_back(new BasicAlienProjectileGrapical(sf::Vector2f(speed, speed), pos, (unsigned int)id));
}

void ItemController::moveShip(MovePacket *packet)
{
  int id = packet->getData()->id;
  sf::Vector2f newPos(packet->getData()->x ,packet->getData()->y);
  std::cout << "ID = " << id << std::endl;

  for (unsigned int i = 0; i != _items.size(); ++i)
    {
      if (dynamic_cast<IObject*>(_items[i])->getId() == id)
	{
	  static_cast<PlayerGraphical*>(_items[i])->setPos(newPos);
	  std::cout << "pos = " << newPos.x << " : " << newPos.y << std::endl;
	  break;
	}
    }
}

void ItemController::deleteObject(DelItemPacket *packet)
{
  int  id = packet->getData()->data;

  size_t i;
  for (i = 0; i != _items.size(); ++i)
    {
      if ((dynamic_cast<IObject*>(_items[i])->getId()) == id)
	break;
    }
  if (i == _items.size())
    return;
  _items.erase(_items.begin() + i);
}

void ItemController::addAlien(CreIAPacket *packet)
{
  // ObjectInfo::WaveType type = packet->iatype;
  // sf::Vector2f pos(packet->x, packet->y);
  // int id = packet->id;

  // switch (type)
  //   {
  //   case ObjectInfo::WaveType::BYDO :
  //     _items.emplace_back(new BydoAlienGraphical(1, pos, id, 1));
  //     break;
  //   default:
  //     break;
  //   }
}
