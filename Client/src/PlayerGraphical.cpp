#include "PlayerGraphical.h"

int playerSkinId = -1;

PlayerGraphical::PlayerGraphical(sf::Vector2f speed, sf::Vector2f pos, unsigned int id) :
  Player(speed, pos, id), GraphicalItem()
{
    _spriteMoving = new sf::Sprite;
    _spriteStatic = new sf::Sprite;
        playerSkinId += 1;
    if (playerSkinId >= 5)
        playerSkinId = 0;
	_spriteStatic->setTexture(*(ac->getShipTexture((Ship)playerSkinId)));
	_spriteStatic->setPosition(
		_pos.x ,
		_pos.y
		);
	_spriteMoving->setTexture(*(ac->getShipTexture((Ship)(playerSkinId + 4))));
	_spriteMoving->setPosition(
		pos.x,
		_pos.y
		);
    _lastPos = pos;
}

bool PlayerGraphical::update(std::vector<IObject*> &map, sf::Clock const& clock)
{
  this->update(clock);
  return this->collision(map);
}

bool	PlayerGraphical::update(sf::Clock const& clock)
{

  bool	ret;

  ret = Player::update(clock);
	_spriteStatic->setPosition(
		_pos.x,
		_pos.y
		);
	_spriteMoving->setPosition(
		_pos.x,
		_pos.y
		);
   if (_lastPos != _pos)
    {
        if (_lastPos.x < _pos.x)
            _sprite = _spriteMoving;
        else
            _sprite = _spriteStatic;
        _lastPos = _pos;
    }    
    else
        _sprite = _spriteMoving;
   
   
	return (ret);

  return (true);
}

sf::Drawable*           PlayerGraphical::getDrawable()
{
   if (_lastPos != _pos)
    {
        _lastPos = _pos;
        return _spriteMoving;
    }    
}