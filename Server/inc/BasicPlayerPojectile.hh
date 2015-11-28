#ifndef _BASIC_PLAYER_PROJECTILE_HH_
# define _BASIC_PLAYER_PROJECTILE_HH_

# include "Projectile.hh"

class BasicPlayerProjectile : public Projectile
{
public:
  BasicPlayerProjectile(Object::Type , sf::Vector2i);
  ~BasicPlayerProjectile();

public:
  void		update();
}

# endif
