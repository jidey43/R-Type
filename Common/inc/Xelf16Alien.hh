#ifndef _XELF_16_ALIEN_HH_
# define _XELF_16_ALIEN_HH_

# include "Alien.hh"

class Xelf16Alien : public Alien
{
public:
  Xelf16Alien(sf::Vector2f speed, sf::Vector2i pos, float coeff);
  ~Xelf16Alien();

public:
  bool		update();
  IObject	*Basicshoot();
};

# endif
