#include "Alien.hh"

extern unsigned int _maxId;

Alien::Alien(sf::Vector2f speed, sf::Vector2f pos, sf::Vector2i size, unsigned int id, float coeff)
  : Object(speed, pos, size, ObjectInfo::Type::ALIEN, id), _coeff(coeff)
{}

Alien::~Alien() {}

const float		&Alien::getCoeff() const
{
  return _coeff;
}

Alien::Alien(const IObject &obj)
{
  if (this != obj)
    {
      this._id = obj._id;
      this._life = obj._life;
      this._isAlive = obj._isAlive;
      this._isShoot = obj._isShoot;
      this._speed = obj._speed;
      this._size = obj._size;
      this._pos = obj._pos;
      this._objType = obj._objType;
      this._coeff = obj.coeff;
      this._f = obj._f;
      this._a = obj._a;
      this._rad = obj._rad;
      this._realType = obj._realType;
    }
  return (*this);
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
