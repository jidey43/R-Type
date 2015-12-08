#ifndef _PROJECTILE_HH_
# define _PROJECTILE_HH_

# include "Object.hh"

class Projectile : public Object
{
public:
  Projectile(Object::Type , sf::Vector2i);
  ~Projectile();

public:
  void		update();
}

# endif
