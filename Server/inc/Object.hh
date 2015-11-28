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
  ObjectInfo::Type		&getObjType();
  void				update();

protected:
  sf::Vector2f			_speed;
  sf::Vector2i			_size;
  sf::Vector2i			_pos;
  ObjectInfo::Type		_objType;
};

#endif
