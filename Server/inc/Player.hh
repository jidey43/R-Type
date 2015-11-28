#ifndef _PLAYER_HH_
# define _PLAYER_HH_

# include "Object.hh"
# include "BasicPlayerProjectile.hh"

class Player: public Object
{
public:
  Player(sf::Vector2i);
  ~Player();

public:
  void		update();
  IObject	*BasicShoot();
}

# endif
