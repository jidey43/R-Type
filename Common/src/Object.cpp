#include "Object.hh"
#include "Projectile.hh"
#include "BasicPlayerProjectile.hh"

Object::Object(sf::Vector2f const& speed, sf::Vector2f const& pos, sf::Vector2i const& size, ObjectInfo::Type type, unsigned int id)
  : _damage(false), _speed(speed), _pos(pos), _size(size), _objType(type), _id(id)
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

void			Object::damage()
{
  _damage = true;
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
  if (_damage)
    {
      _life -= 1;
      _damage = false;
    }
  else
    for (std::vector<IObject*>::iterator it = map.begin(); it != map.end(); it++)
      {
	if ((this->getObjType() == ObjectInfo::PLAYER && (((*it)->getObjType() == ObjectInfo::SHOT
							   && static_cast<Projectile*>(*it)->getRealType() == ObjectInfo::ALIENREGULAR) || (*it)->getObjType() == ObjectInfo::ALIEN))
	    || (this->getObjType() == ObjectInfo::ALIEN && (((*it)->getObjType() == ObjectInfo::SHOT
							     && static_cast<Projectile*>(*it)->getRealType() == ObjectInfo::PLAYERREGULAR) || (*it)->getObjType() == ObjectInfo::PLAYER))
	    || (this->getObjType() == ObjectInfo::SHOT && static_cast<Projectile*>(this)->getRealType() == ObjectInfo::PLAYERREGULAR && (*it)->getObjType() == ObjectInfo::ALIEN)
	    || (this->getObjType() == ObjectInfo::SHOT && static_cast<Projectile*>(this)->getRealType() == ObjectInfo::ALIENREGULAR && (*it)->getObjType() == ObjectInfo::PLAYER))
	  {
	    if (this->getObjType() == ObjectInfo::SHOT && static_cast<Projectile*>(this)->getRealType() == ObjectInfo::PLAYERREGULAR && (*it)->getObjType() == ObjectInfo::ALIEN)
	      {
		static_cast<BasicPlayerProjectile*>(this)->increaseScore();
	      }
	    if (this->getObjType() == ObjectInfo::ALIEN && (*it)->getObjType() == ObjectInfo::SHOT && static_cast<Projectile*>(*it)->getRealType() == ObjectInfo::PLAYERREGULAR)
	      {
		static_cast<BasicPlayerProjectile*>(*it)->increaseScore();
	      }
	    if ((this != *it)
		&& ((this->getPos().x <= (*it)->getPos().x + (*it)->getSize().x)
		    && (this->getPos().x + this->getSize().x >= (*it)->getPos().x)
		    && (this->getPos().y <= (*it)->getPos().y + (*it)->getSize().y)
		    && (this->getPos().y + this->getSize().y >= (*it)->getPos().y)))
	      // {
	      // std::cout << "COLLISION [" << this->getObjType() << "] !!!! entre" << this->getId() << " and " << (*it)->getId() << std::endl;
	      // if ((this != *it)
	      // 	&& (((this->getPos().x >= (*it)->getPos().x) && (this->getPos().x <= (*it)->getPos().x + (*it)->getSize().x) && (this->getPos().y >= (*it)->getPos().y) && (this->getPos().y <= (*it)->getPos().y + (*it)->getSize().y))
	      // 	    || ((this->getPos().y + this->getSize().y >= (*it)->getPos().y) && (this->getPos().y + this->getSize().y <= (*it)->getPos().y + (*it)->getSize().y) && (this->getPos().x >= (*it)->getPos().x) && (this->getPos().x <= (*it)->getPos().x + (*it)->getSize().x))
	      // 	    || ((this->getPos().y + this->getSize().y >= (*it)->getPos().y) && (this->getPos().y + this->getSize().y <= (*it)->getPos().y + (*it)->getSize().y) && (this->getPos().x + this->getSize().x >= (*it)->getPos().x) && (this->getPos().x + this->getSize().x <= (*it)->getPos().x + (*it)->getSize().x))
	      // 	    || ((this->getPos().y >= (*it)->getPos().y) && (this->getPos().y <= (*it)->getPos().y + (*it)->getSize().y) && (this->getPos().x + this->getSize().x >= (*it)->getPos().x) && (this->getPos().x + this->getSize().x <= (*it)->getPos().x + (*it)->getSize().x))))
	      {
		_life = _life - 1;
		// std::cout << "COLLISION entre" << this->getId() << " [" << this->getPos().x << ";" <<  this->getPos().y << "](" << this->getSize().x << ';' << this->getSize().y <<  ") and " << (*it)->getId()<< " [" << (*it)->getPos().x << ";" <<  (*it)->getPos().y << "]("<< (*it)->getSize().x << ';' << (*it)->getSize().y << ')' << std::endl;
		static_cast<Object*>(*it)->damage();
	      }
	  }
      }
  if (_life <= 0)
    _isAlive = false;
  return (_isAlive);
}
