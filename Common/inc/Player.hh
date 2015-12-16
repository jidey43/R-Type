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
  bool				update();
  bool				update(std::vector<IObject*>&);
  IObject			*BasicShoot();
  bool				tryShoot();
<<<<<<< HEAD
  void				setDirection(const Direction &dir);
  const ObjectInfo::PlayerType	&getRealType() const;
  
=======
  void				setDirection(Direction dir);
  ObjectInfo::PlayerType	getRealType() const;

>>>>>>> 81455b23673468f67b075a94fb4ef17f92fc66e2
private:
  int				_id;
  bool				_tryShoot;
  sf::Vector2f			_move;
  Direction			_dir;
  ObjectInfo::PlayerType	_realType;
  sf::Time			_unblockShot;
  sf::Time			_pauseShotDelay;
  sf::Time			_lastLoopTime;
};

# endif
