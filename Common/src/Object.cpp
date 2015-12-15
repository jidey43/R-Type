#include "Object.hh"

Object::Object(sf::Vector2f speed, sf::Vector2f pos, sf::Vector2i size, ObjectInfo::Type type, unsigned int id)
  : _speed(speed), _pos(pos), _size(size), _objType(type), _id(id)
{
  _life = 1;
}

Object::~Object() {}

ObjectInfo::Type	Object::getObjType() const
{
  return _objType;
}

sf::Vector2i		Object::getSize() const
{
  return _size;
}

sf::Vector2f		Object::getSpeed() const
{
  return _speed;
}

sf::Vector2f		Object::getPos() const
{
  return _pos;
}

unsigned int		Object::getId() const
{
  return _id;
}

bool			Object::collision(std::vector<IObject*>& map)
{
    return (false);
  for (std::vector<IObject*>::iterator it = map.begin(); it != map.end(); it++)
    {
      if ((this->getObjType() == ObjectInfo::Type::PLAYER && (*it)->getObjType() == ObjectInfo::Type::ALIEN)
	  ||(this->getObjType() == ObjectInfo::Type::ALIEN && (*it)->getObjType() == ObjectInfo::Type::PLAYER))
	{
	  if ((this != *it) && (this->getPos().x >= (*it)->getPos().x + (*it)->getSize().x)
	      || (this->getPos().x + this->getSize().x <= (*it)->getPos().x)
	      || (this->getPos().y >= (*it)->getPos().y + (*it)->getSize().y)
	      || (this->getPos().y + this->getSize().y <= (*it)->getPos().y))
	    {
	      _life = _life - 1;
	    }
	}
    }
  if (_life == 0)
    return (true);
  return (false);
}
