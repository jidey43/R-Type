#ifndef _SCANT_ALIEN_HH_
# define _SCANT_ALIEN_HH_

# include "Alien.hh"

class ScantAlien : public Alien
{
public:
  ScantAlien(sf::Vector2f speed, sf::Vector2i pos, unsigned int id, float coeff);
  ~ScantAlien();

public:
  bool		update();
  bool		update(std::vector<IObject*>&);
  IObject	*Basicshoot();
};

# endif
