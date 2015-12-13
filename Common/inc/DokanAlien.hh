#ifndef _DOKAN_ALIEN_HH_
# define _DOKAN_ALIEN_HH_

# include "Alien.hh"

class DokanAlien : public Alien
{
public:
  DokanAlien(sf::Vector2f speed, sf::Vector2i pos, float coeff);
  ~DokanAlien();

public:
  bool		update();
  IObject	*BasicShoot();
};

# endif
