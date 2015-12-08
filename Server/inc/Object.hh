#ifndef _OBJECT_HH_
# define _OBJECT_HH_

# include <SFML/System/Vector2.hpp>
# include <SFML/System/Time.hpp>
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
  virtual void		        update();
  
protected:
  float				_coeff;
  sf::Vector2f			_speed;
  sf::Vector2i			_size;
  sf::Vector2i			_pos;
  ObjectInfo::Type		_objType;
};

#endif
