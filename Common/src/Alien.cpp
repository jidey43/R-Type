#include "Alien.hh"

extern unsigned int _maxId;

Alien::Alien(sf::Vector2f speed, sf::Vector2f pos, sf::Vector2i size, unsigned int id, float coeff)
  : Object(speed, pos, size, ObjectInfo::Type::ALIEN, id), _coeff(coeff)
{}

Alien::~Alien() {}

Alien::Alien(const Alien &obj)
  : Object(obj._speed, obj._pos, obj._size, obj._objType, obj._id)
{
  if (this != &obj)
    {
      this->_life = obj._life;
      this->_isAlive = obj._isAlive;
      this->_isShoot = obj._isShoot;
      this->_objType = obj._objType;
      this->_coeff = obj._coeff;
      this->_f = obj._f;
      this->_a = obj._a;
      this->_rad = obj._rad;
      this->_realType = obj._realType;
    }
}

// bool		        Alien::update(sf::Clock const&, std::vector<IObject*>&)
// {

// }

// bool		        Alien::update(sf::Clock const&)
// {
// }

const float		&Alien::getCoeff() const
{
  return _coeff;
}

const ObjectInfo::WaveType	&Alien::getRealType() const
{
  return _realType;
}

BasicAlienProjectile		*Alien::BasicShoot()
{
  sf::Vector2f pos;

  pos.x = _pos.x + _size.x;
  pos.y = _pos.y + _size.y;
  _isShoot = false;
  return new BasicAlienProjectile(_speed, pos, _maxId++);
}
