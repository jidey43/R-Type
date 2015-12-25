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
  bool				update(sf::Clock const&, std::vector<IObject*>&);
  bool				update(sf::Clock const&);
  BasicPlayerProjectile		*BasicShoot();
  void				resetLoopTime();
  bool				tryShoot();
  void				setDirection(const Direction &dir);
  const ObjectInfo::PlayerType	&getRealType() const;
  uint32_t			getScore() const;
  void				setScore(uint32_t);

private:
  uint32_t			_score;
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
