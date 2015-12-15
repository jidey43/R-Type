#ifndef _RIOS_ALIEN_HH_
# define _RIOS_ALIEN_HH_

# include "Alien.hh"

class RiosAlien : public Alien
{
public:
  RiosAlien(sf::Vector2f speed, sf::Vector2i pos, unsigned int id, float coeff);
  ~RiosAlien();

public:
  bool	       	update();
  bool		update(std::vector<IObject*>&);
  IObject	*Basicshoot();
};

# endif
