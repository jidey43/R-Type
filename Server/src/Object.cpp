#include "Object.hh"

Object::Object() {}

Object::~Object() {}

ObjectInfo::Type	&Object::getObjType()
{
  return _objType;
}

void			Object::update() {}
