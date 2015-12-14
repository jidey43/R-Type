#ifndef _PLAYER_HH_
# define _PLAYER_HH_

# include "Object.hh"
# include "BasicPlayerProjectile.hh"

class Player: public Object
{
public:
  Player(sf::Vector2f, sf::Vector2i, float, int);
  ~Player();

public:
  bool		update();
  IObject	*BasicShoot();
  void		tryShoot();
  void		setDirection(Direction dir);

private:
  int		_id;
  bool		_tryShoot;
  Direction	_dir;
};

# endif
