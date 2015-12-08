#include "Object.hh"

Object::Object(sf::Vector2f speed, sf::Vector2i pos, float coeff)
  : _speed(speed), _pos(pos),  _coeff(coeff)
{}

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

sf::Vector2i		Object::getPos() const
{
  return _pos;
}
