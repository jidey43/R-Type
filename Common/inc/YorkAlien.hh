#ifndef _YORK_ALIEN_HH_
# define _YORK_ALIEN_HH_

# include "Alien.hh"

class YorkAlien : public Alien
{
public:
  YorkAlien(sf::Vector2f speed, sf::Vector2i pos, unsigned int id, float coeff);
  ~YorkAlien();

public:
  bool		update(sf::Clock const&, std::vector<IObject*>&);
  bool		update(sf::Clock const&);
  IObject	*Basicshoot();
};

# endif
