#ifndef _PROJECTILE_HH_
# define _PROJECTILE_HH_

# include "Object.hh"

class Projectile : public Object
{
public:
  Projectile(sf::Vector2f, sf::Vector2f, sf::Vector2i, unsigned int, ObjectInfo::ShotType);
  ~Projectile();

  const ObjectInfo::ShotType	&getRealType() const;


public:
  virtual bool		update(std::vector<IObject*>&,sf::Clock const&) = 0;
  virtual bool		update(sf::Clock const&) = 0;
  ObjectInfo::ShotType	_realType;
};

# endif
