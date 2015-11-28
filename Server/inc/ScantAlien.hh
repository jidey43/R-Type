#ifndef _SCANT_ALIEN_HH_
# define _SCANT_ALIEN_HH_

# include "Alien.hh"

class ScantAlien : public Alien
{
public:
  ScantAlien(sf::Vector2i pos);
  ~ScantAlien();

public:
  void		update();
  IObject	*Basicshoot();
}

# endif
