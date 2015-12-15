#ifndef _YORK_ALIEN_HH_
# define _YORK_ALIEN_HH_

# include "Alien.hh"

class YorkAlien : public Alien
{
public:
  YorkAlien(sf::Vector2f speed, sf::Vector2i pos, unsigned int id, float coeff);
  ~YorkAlien();

public:
  bool		update();
  bool		update(std::vector<IObject*>&);
  IObject	*Basicshoot();
};

# endif
