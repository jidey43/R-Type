#include "Object.hh"

Object::Object(sf::Vector2f speed, sf::Vector2i pos, float coeff)
  :_speed(speed), _pos(pos),  _coeff(coeff)
{}

Object::~Object() {}

ObjectInfo::Type	&Object::getObjType()
{
  return _objType;
}

void			Object::update()
{}
