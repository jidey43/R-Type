#ifndef _DOKAN_ALIEN_HH_
# define _DOKAN_ALIEN_HH_

# include "Alien.hh"

class DokanAlien : public Alien
{
public:
  DokanAlien(sf::Vector2f speed, sf::Vector2f pos, unsigned int id, float coeff);
  ~DokanAlien();

public:
  bool		update();
  bool		update(std::vector<IObject*>&);
  IObject	*BasicShoot();
};

# endif
