#ifndef _BASIC_ALIEN_PROJECTILE_HH_
# define _BASIC_ALIEN_PROJECTILE_HH_

# include "Projectile.hh"

class BasicAlienProjectile : public Projectile
{
public:
  BasicAlienProjectile(sf::Vector2f speed, sf::Vector2f pos, unsigned int id);
  ~BasicAlienProjectile();

public:
  bool		update();
  bool		update(std::vector<IObject*>&);
};

# endif
