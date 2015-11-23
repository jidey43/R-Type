#include "Object.hh"

Object::Object() {}

Object::~Object() {}

ObjectInfo::Type const	&Object::getObjtype() const
{
  return _objType;
}

void			Object::update() const {}
