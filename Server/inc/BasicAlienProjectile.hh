#ifndef _BASIC_ALIEN_PROJECTILE_HH_
# define _BASIC_ALIEN_PROJECTILE_HH_

# include "Projectile.hh"

class BasicAlienProjectile : public Projectile
{
public:
  BasicAlienProjectile(Object::Type , sf::Vector2i);
  ~BasicAlienProjectile();

public:
  void		update();
}

# endif
