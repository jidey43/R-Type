#ifndef _BASIC_PLAYER_PROJECTILE_HH_
# define _BASIC_PLAYER_PROJECTILE_HH_

# include "Projectile.hh"

class BasicPlayerProjectile : public Projectile
{
public:
  BasicPlayerProjectile(sf::Vector2f, sf::Vector2i, float);
  ~BasicPlayerProjectile();

public:
  void		update();
};

# endif
