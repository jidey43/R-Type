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
		(_pos.x / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2),
		(_pos.y / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2)
		);
	_spriteMoving->setTexture(*(ac->getShipTexture((Ship)(playerSkinId + 4))));
	_spriteMoving->setPosition(
		(_pos.x / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2),
		(_pos.y / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2)
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
		(_pos.x / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2),
		(_pos.y / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2)
		);
	_spriteMoving->setPosition(
		(_pos.x / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2),
		(_pos.y / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2)
		);
   if (_lastPos != _pos)
    {
        _lastPos = _pos;
        _sprite = _spriteMoving;
    }    
    else
        _sprite = _spriteStatic;
   
   
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