#ifndef _BASIC_ALIEN_PROJECTILE_HH_
# define _BASIC_ALIEN_PROJECTILE_HH_

# include "Projectile.hh"

class BasicAlienProjectile : public Projectile
{
public:
  BasicAlienProjectile(sf::Vector2f speed, sf::Vector2i pos, float coeff);
  ~BasicAlienProjectile();

public:
  void		update();
};

# endif
