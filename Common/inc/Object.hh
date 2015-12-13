#ifndef _OBJECT_HH_
# define _OBJECT_HH_

# include "IObject.hh"

class Object : public IObject
{
public:
  Object(sf::Vector2f, sf::Vector2i, float);
  ~Object();

public:
  ObjectInfo::Type		getObjType() const;
  sf::Vector2i			getSize() const;
  sf::Vector2f			getSpeed() const;
  sf::Vector2i			getPos() const;
  virtual bool		        update() = 0;
  
protected:
  sf::Vector2f			_speed;
  sf::Vector2i			_size;
  sf::Vector2i			_pos;
  ObjectInfo::Type		_objType;
  float				_coeff;
};

#endif
