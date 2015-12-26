#include "Player.hh"
#include <stdlib.h>

extern unsigned int _maxId;

Player::Player(sf::Vector2f speed, sf::Vector2f pos, unsigned int id, unsigned int nbPlayer)
  : Object(speed, pos, sf::Vector2i(220, 80), ObjectInfo::PLAYER, id),
    _score(0),
    _canShoot(true),
    _nbPlayer(nbPlayer),
    _pauseShotDelayTemp(sf::milliseconds(500)),
    _pauseShotDelay(_pauseShotDelayTemp),
    _lastLoopTime(sf::milliseconds(0)),
    _bonusSpeedTaken(false),
    _bonusSpeed(sf::seconds(0))
{
}

Player::~Player()
{
}

void		Player::resetLoopTime()
{
  _lastLoopTime = sf::milliseconds(0);
}

void		Player::setBackDelay()
{
  _pauseShotDelayTemp = sf::milliseconds(500);
}

void		Player::speedUp()
{
  _bonusSpeedTaken = true;
}

void		Player::handleBonusSpeed(sf::Clock const& clock)
{
  _bonusSpeed -= (clock.getElapsedTime() - _lastLoopTime);
  if (_bonusSpeed <= sf::milliseconds(0))
    {
      _bonusSpeed = sf::milliseconds(0);
      this->setBackDelay();
      _actions.erase(std::find(_actions.begin(), _actions.end(), &Player::handleBonusSpeed));
    }
}

void		Player::checkBonus()
{
  if (_bonusSpeedTaken)
    {
      _pauseShotDelayTemp = sf::milliseconds(250);
      _bonusSpeed += sf::seconds(5);
      _bonusSpeedTaken = false;
      if (std::find(_actions.begin(), _actions.end(), &Player::handleBonusSpeed) == _actions.end())
	_actions.push_back(&Player::handleBonusSpeed);
    }
}

bool		Player::update(sf::Clock const& clock)
{
  checkBonus();
  if (!_actions.empty())
    {
      for (auto& action : _actions)
	{
	  (this->*action)(clock);
	}
    }

  _pauseShotDelay -= (clock.getElapsedTime() - _lastLoopTime);
  _lastLoopTime = clock.getElapsedTime();
  if (_pauseShotDelay <= sf::milliseconds(0))
    {
      _isShoot = false;
      _canShoot = true;
      _pauseShotDelay = _pauseShotDelayTemp;
    }
  _pos += _move;
  _move = sf::Vector2f(0,0);
  return true;
}

bool		Player::update(sf::Clock const& clock, std::vector<IObject*>& map)
{
  _pauseShotDelay -= (clock.getElapsedTime() - _lastLoopTime);
  _lastLoopTime = clock.getElapsedTime();
  if (_pauseShotDelay <= sf::milliseconds(0))
    {
      _isShoot = false;
      _canShoot = true;
      _pauseShotDelay = _pauseShotDelayTemp;
    }
  _pos += _move;
  if (_pos.x < 0 || _pos.x + _size.x > MAP_SIZE_X
      || _pos.y < 0 || _pos.y + _size.y > MAP_SIZE_Y)
    _pos -= _move;
  _move = sf::Vector2f(0,0);
  this->collision(map);
  return true;
}

BasicPlayerProjectile		*Player::BasicShoot()
{
  sf::Vector2f pos;
  sf::Vector2f speed;

  _isShoot = false;
  pos.x = _pos.x + _size.x;
  pos.y = _pos.y + _size.y;
  speed.x = _speed.y + (_speed.y / 3);
  speed.y = speed.x;
  return new BasicPlayerProjectile(speed, pos, _maxId++, &_score);
}

bool		Player::tryShoot()
{
  if (_canShoot)
    {
      _isShoot = true;
      _canShoot = false;
      return true;
    }
  return false;
}

void		Player::setDirection(const Direction &dir)
{
  _move = sf::Vector2f((dir == LEFT ? -_speed.x : (dir == RIGHT ? _speed.x : 0)), (dir == UP ? -_speed.y : (dir == DOWN ? _speed.y : 0)));
}

const ObjectInfo::PlayerType	&Player::getRealType() const
{
  return _realType;
}

uint32_t			Player::getScore() const
{
  return _score;
}

void				Player::setScore(uint32_t score)
{
  _score = score;
}

unsigned int			Player::getNbPlayer() const
{
  return _nbPlayer;
}
