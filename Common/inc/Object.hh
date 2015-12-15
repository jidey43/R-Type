#ifndef _OBJECT_HH_
# define _OBJECT_HH_

# include "IObject.hh"
# include "MapController.hh"

class Object : public IObject
{
public:
  Object(sf::Vector2f, sf::Vector2f, sf::Vector2i, ObjectInfo::Type, unsigned int);
  ~Object();

public:
  ObjectInfo::Type		getObjType() const;
  sf::Vector2i			getSize() const;
  sf::Vector2f			getSpeed() const;
  sf::Vector2f			getPos() const;
  unsigned int			getId() const;
  virtual bool		        update() = 0;
  virtual bool			update(std::vector<IObject*> &) = 0;
  
protected:
  bool				collision(std::vector<IObject*>&);

protected:
  unsigned int			_id;
  int				_life;
  sf::Vector2f			_speed;
  sf::Vector2i			_size;
  sf::Vector2f			_pos;
  ObjectInfo::Type		_objType;
};

#endif
