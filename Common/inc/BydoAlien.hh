#ifndef _BYDO_ALIEN_HH_
# define _BYDO_ALIEN_HH_

# include "Alien.hh"

class BydoAlien : public Alien
{
public:
  BydoAlien(sf::Vector2f speed, sf::Vector2i pos, float coeff);
  ~BydoAlien();

public:
  void		update();
  IObject	*BasicShoot();
};

# endif
