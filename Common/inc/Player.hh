#ifndef _PLAYER_HH_
# define _PLAYER_HH_

# include "Object.hh"
# include "BasicPlayerProjectile.hh"

class Player: public Object
{
public:
  Player(sf::Vector2f, sf::Vector2f, unsigned int);
  ~Player();

public:
  bool		update();
  IObject	*BasicShoot();

private:
  int		_id;
};

# endif
