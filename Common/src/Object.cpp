#include "Object.hh"
#include "Projectile.hh"

Object::Object(sf::Vector2f speed, sf::Vector2f pos, sf::Vector2i size, ObjectInfo::Type type, unsigned int id)
  : _speed(speed), _pos(pos), _size(size), _objType(type), _id(id)
{
  _life = 1;
  _isAlive = true;
  _isShoot = false;
}

Object::~Object() {}

const ObjectInfo::Type		&Object::getObjType() const
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
  return _isShoot;
}


void			Object::setShooting(bool shoot)
{
  _isShoot = shoot;
}

bool			Object::collision(std::vector<IObject*>& map)
{
  // if (this->getObjType() == ObjectInfo::ALIEN)
  //   std::cout << "BEGIN ALIENNNNNN\n";
  for (std::vector<IObject*>::iterator it = map.begin(); it != map.end(); it++)
    {
      // std::cout << "type : " << (*it)->getObjType() << std::endl;
      // si this = player et que ennemi = shot&&alien ou alien
      if ((this->getObjType() == ObjectInfo::PLAYER && (((*it)->getObjType() == ObjectInfo::SHOT
	  && static_cast<Projectile*>(*it)->getRealType() == ObjectInfo::ALIENREGULAR) || (*it)->getObjType() == ObjectInfo::ALIEN))
	  || (this->getObjType() == ObjectInfo::ALIEN && (((*it)->getObjType() == ObjectInfo::SHOT
          && static_cast<Projectile*>(*it)->getRealType() == ObjectInfo::PLAYERREGULAR) || (*it)->getObjType() == ObjectInfo::PLAYER))
	  || (this->getObjType() == ObjectInfo::SHOT && static_cast<Projectile*>(this)->getRealType() == ObjectInfo::PLAYERREGULAR && (*it)->getObjType() == ObjectInfo::ALIEN)
	  || (this->getObjType() == ObjectInfo::SHOT && static_cast<Projectile*>(this)->getRealType() == ObjectInfo::ALIENREGULAR && (*it)->getObjType() == ObjectInfo::PLAYER))
  	{
	  // std::cout << "after segfault1\n";
	  // if (this->getObjType() == ObjectInfo::PLAYER)
	  //   std::cout << "PLAYERRRRRR\n";
	    // std::cout << "START COLLISION pos shot : " << this->getPos().x << " " << this->getPos().y << "\npos alien : " << (*it)->getPos().x << " " << (*it)->getPos().y << "\n";
  	  if ((this != *it)
	      && ((this->getPos().x <= (*it)->getPos().x + (*it)->getSize().x)
		  && (this->getPos().x + this->getSize().x >= (*it)->getPos().x)
		  && (this->getPos().y <= (*it)->getPos().y + (*it)->getSize().y)
		  && (this->getPos().y + this->getSize().y >= (*it)->getPos().y)))
  	    {
	      std::cout << "COLLISION [" << this->getObjType() << "] !!!! entre" << this->getId() << " and " << (*it)->getId() << std::endl;
  	      _life = _life - 1;
  	    }
  	}
      // else
      // 	std::cout << "after segfault2\n";

    }
  if (_life <= 0)
    _isAlive = false;
  return (_isAlive);
}
