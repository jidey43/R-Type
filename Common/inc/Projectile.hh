#ifndef _PROJECTILE_HH_
# define _PROJECTILE_HH_

# include "Object.hh"

class Projectile : public Object
{
public:
  Projectile(sf::Vector2f, sf::Vector2i, float);
  ~Projectile();

public:
  void		update();
};

# endif
