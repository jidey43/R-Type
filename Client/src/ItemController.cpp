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
  for (GraphicalItem *i : _unlogicalItems)
    vc->draw(i->getDrawable());
}

void ItemController::update()
{
  for (GraphicalItem* i : _items)
    i->update(_clock);
  for (std::vector<GraphicalItem*>::iterator it = _unlogicalItems.begin(); it != _unlogicalItems.end();)
    {
      if (!((*it)->update(_clock)))
	{
	  it = _unlogicalItems.erase(it);
	}
      else
	++it;
    }
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

  if (packet->getData()->type == ObjectInfo::PLAYERREGULAR)
    _items.emplace_back(new BasicPlayerProjectileGrapical(sf::Vector2f(speed, speed), pos, (unsigned int)id));
  if (packet->getData()->type == ObjectInfo::ALIENREGULAR)
    _items.emplace_back(new BasicAlienProjectileGrapical(sf::Vector2f(speed, speed), pos, (unsigned int)id));
}

void ItemController::moveShip(MovePacket *packet)
{
  int id = packet->getData()->id;
  sf::Vector2f newPos(packet->getData()->x ,packet->getData()->y);

  for (unsigned int i = 0; i != _items.size(); ++i)
    {
      if (dynamic_cast<IObject*>(_items[i])->getId() == id)
	{
	  static_cast<PlayerGraphical*>(_items[i])->setPos(newPos);
	  break;
	}
    }
}

void ItemController::addExplosion(sf::Vector2f pos)
{
  Explosion *expl = new Explosion(pos);

  _unlogicalItems.push_back(expl);
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
  //  addExplosion(dynamic_cast<IObject*>(_items[i])->getPos());
  addExplosion(static_cast<sf::Sprite*>(_items[i]->getDrawable())->getPosition());
  _items.erase(_items.begin() + i);
}

void ItemController::addAlien(CreIAPacket *packet)
{
  ObjectInfo::WaveType type = packet->getData()->iatype;
  sf::Vector2f speed(packet->getData()->speed, packet->getData()->speed);
  sf::Vector2f pos(packet->getData()->x, packet->getData()->y);
  unsigned int id = packet->getData()->id;

  switch (type)
    {
    case ObjectInfo::WaveType::BYDO :
      _items.emplace_back(new BydoAlienGraphical(speed, pos, id, 1));
      break;
    default:
      break;
    }
}
