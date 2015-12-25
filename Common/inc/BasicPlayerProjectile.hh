#ifndef _BASIC_PLAYER_PROJECTILE_HH_
# define _BASIC_PLAYER_PROJECTILE_HH_

# include "Projectile.hh"

class BasicPlayerProjectile : public Projectile
{
public:
  BasicPlayerProjectile(sf::Vector2f, sf::Vector2f, unsigned int, uint32_t* score);
  ~BasicPlayerProjectile();

public:
  bool		update(sf::Clock const&);
  bool		update(sf::Clock const&, std::vector<IObject*>&);
  void		increaseScore();

protected :
  uint32_t*	_score;
};

# endif
