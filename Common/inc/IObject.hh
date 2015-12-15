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
  virtual void				setPos(const sf::Vector2f &pos) = 0;
  virtual void				setSpeed(const sf::Vector2f &speed) = 0;
  virtual unsigned int			getId() const = 0;
  virtual bool				isAlive() const = 0;
  virtual bool				isShooting() = 0;
  virtual bool				update(std::vector<IObject*>&) = 0;
  virtual bool				update() = 0;
};

#endif
