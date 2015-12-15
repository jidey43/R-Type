#ifndef _PROJECTILE_HH_
# define _PROJECTILE_HH_

# include "Object.hh"

class Projectile : public Object
{
public:
  Projectile(sf::Vector2f, sf::Vector2f, sf::Vector2i, unsigned int);
  ~Projectile();
  
  ObjectInfo::ShotType	getRealType() const;
  
  
public:
  virtual bool		update() = 0;
  virtual bool		update(std::vector<IObject*>&) = 0;
  ObjectInfo::ShotType	_realType;
};

# endif
