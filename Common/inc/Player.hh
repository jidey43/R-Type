#ifndef _PLAYER_HH_
# define _PLAYER_HH_

# include "Object.hh"
# include "BasicPlayerProjectile.hh"
# include "NetworkDefines.h"

class Player: public Object
{
public:
  Player(sf::Vector2f, sf::Vector2f, unsigned int);
  ~Player();

public:
  bool		update();
  bool		update(IObject*);
  bool		update(std::vector<IObject*>&);
  IObject	*BasicShoot();
  void		tryShoot();
  void		setDirection(Direction dir);

private:
  int		_id;
  bool		_tryShoot;
  Direction	_dir;
};

# endif
