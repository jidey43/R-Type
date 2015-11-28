#ifndef _ALIEN_HH_
# define _ALIEN_HH_

# include "Object.hh"

class Alien : public Object
{
public:
  Alien(sf::Vector2i pos);
  ~Alien();

public:
  void		update();
  IObject	*Basicshoot();
}

# endif
