#ifndef _PLAYER_HH_
# define _PLAYER_HH_

# include <algorithm>
# include "Object.hh"
# include "BasicPlayerProjectile.hh"
# include "NetworkDefines.h"

class Player: public Object
{
  typedef void	(Player::*bonusPtr)(sf::Clock const&);

public:
  Player(sf::Vector2f, sf::Vector2f, unsigned int, unsigned int nbPlayer = -1);
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
  unsigned int			getNbPlayer() const;
  void				setScore(uint32_t);
  void				speedUp();

private:
  void				checkBonus();
  void				handleBonusSpeed(sf::Clock const&);
  void				setBackDelay();

private:
  uint32_t			_score;
  bool				_canShoot;
  int				_id;

  // Number form 0 to 3 of the player : needed for score
  unsigned int			_nbPlayer;
  sf::Vector2f			_move;

  Direction			_dir;
  ObjectInfo::PlayerType	_realType;
  sf::Time			_unblockShot;

  /*
  ** Handle Shots Time Delay
  */
  sf::Time			_pauseShotDelayTemp;
  sf::Time			_pauseShotDelay;
  sf::Time			_lastLoopTime;

  /*
  ** Handle Bonus Timer
  */
  bool				_bonusSpeedTaken;
  sf::Time			_bonusSpeed;

  /*
  ** Bonus action to handle
  */
  std::vector<bonusPtr>		_actions;
};

# endif
