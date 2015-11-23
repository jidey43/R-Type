#ifndef _OBJECT_HH_
# define _OBJECT_HH_

#include <SFML/System/Vector2.hpp>
# include "IObject.hh"

class Object : public IObject
{
public:
  Object();
  ~Object();

public:
  ObjectInfo::Type const	&getObjType() const;
  void				update();

private:
  Vector2f			_speed;
  Vector2i			_size;
  Vector2i			_pos;
  ObjectInfo::Type		_objType;
}

#endif
