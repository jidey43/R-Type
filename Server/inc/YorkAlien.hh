#ifndef _YORK_ALIEN_HH_
# define _YORK_ALIEN_HH_

# include "Alien.hh"

class YorkAlien : public Alien
{
public:
  YorkAlien(sf::Vector2i pos);
  ~YorkAlien();

public:
  void		update();
  IObject	*Basicshoot();
}

# endif
