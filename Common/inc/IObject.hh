#ifndef _IOBJECT_HH_
# define _IOBJECT_HH_

# include <vector>
# include "ObjectInfo.hpp"
# include <SFML/System/Vector2.hpp>
# include <SFML/System/Time.hpp>

class IObject
{
public:
  virtual ~IObject() {}

public:
  virtual ObjectInfo::Type		getObjType() const = 0;
  virtual sf::Vector2f			getPos() const = 0;
  virtual sf::Vector2f			getSpeed() const = 0;
  virtual sf::Vector2i			getSize() const = 0;
  virtual unsigned int			getId() const = 0;
  virtual bool				update(std::vector<IObject*>&) = 0;
};

#endif
