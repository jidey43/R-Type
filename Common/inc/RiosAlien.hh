#ifndef _RIOS_ALIEN_HH_
# define _RIOS_ALIEN_HH_

# include "Alien.hh"

class RiosAlien : public Alien
{
public:
  RiosAlien(sf::Vector2f speed, sf::Vector2i pos, float coeff);
  ~RiosAlien();

public:
  void		update();
  IObject	*Basicshoot();
};

# endif
