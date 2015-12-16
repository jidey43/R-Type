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
  bool				update(std::vector<IObject*>&, sf::Clock const&);
  bool				update(sf::Clock const&);
  IObject			*BasicShoot();
  bool				tryShoot();
  void				setDirection(const Direction &dir);
  const ObjectInfo::PlayerType	&getRealType() const;

private:
  bool				_canShoot;
  int				_id;
  sf::Vector2f			_move;
  Direction			_dir;
  ObjectInfo::PlayerType	_realType;
  sf::Time			_unblockShot;
  sf::Time			_pauseShotDelay;
  sf::Time			_lastLoopTime;
};

# endif
