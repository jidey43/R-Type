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
  void				setDirection(Direction dir);
  ObjectInfo::PlayerType	getRealType() const;
  
private:
  int				_id;
  bool				_tryShoot;
  sf::Vector2f			_move;
  Direction			_dir;
  ObjectInfo::PlayerType	_realType;
};

# endif
