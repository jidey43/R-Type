#ifndef _GLAM_ALIEN_HH_
# define _GLAM_ALIEN_HH_

# include "Alien.hh"

class GlamAlien : public Alien
{
public:
  GlamAlien(sf::Vector2f speed, sf::Vector2f pos, unsigned int id, float coeff);
  ~GlamAlien();

public:
  bool		update(std::vector<IObject*>&, sf::Clock const&);
  bool		update(sf::Clock const&);
  IObject	*BasicShoot();
};

# endif
