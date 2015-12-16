#include "Object.hh"

Object::Object(sf::Vector2f speed, sf::Vector2f pos, sf::Vector2i size, ObjectInfo::Type type, unsigned int id)
  : _speed(speed), _pos(pos), _size(size), _objType(type), _id(id)
{
  _life = 1;
  _isAlive = true;
  _isShoot = false;
}

Object::~Object() {}

const ObjectInfo::Type	&Object::getObjType() const
{
  return _objType;
}

const sf::Vector2i		&Object::getSize() const
{
  return _size;
}

const sf::Vector2f		&Object::getSpeed() const
{
  return _speed;
}

const sf::Vector2f		&Object::getPos() const
{
  return _pos;
}

const unsigned int		&Object::getId() const
{
  return _id;
}

void			Object::setPos(const sf::Vector2f &pos)
{
  this->_pos = pos;
}

void                    Object::setSpeed(const sf::Vector2f &speed)
{
  this->_speed = speed;
}


bool			Object::isAlive() const
{
  return _isAlive;
}

bool			Object::isShooting()
{
  if (_isShoot == true)
    {
      _isShoot = false;
      return true;
    }
  else
    return false;
}

bool			Object::collision(std::vector<IObject*>& map)
{
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
    {
      _isAlive = false;
      return (_isAlive);
    }
  return (true);
}
