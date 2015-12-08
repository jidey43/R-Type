#ifndef _GLAM_ALIEN_HH_
# define _GLAM_ALIEN_HH_

# include "Alien.hh"

class GlamAlien : public Alien
{
public:
  GlamAlien(sf::Vector2i pos);
  ~GlamAlien();

public:
  void		update();
  IObject	*Basicshoot();
}

# endif
