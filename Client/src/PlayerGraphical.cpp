#include "PlayerGraphical.h"

PlayerGraphical::PlayerGraphical(sf::Vector2f speed, sf::Vector2f pos, unsigned int id) :
  Player(speed, pos, id), GraphicalItem()
{
	_sprite->setTexture(*(ac->getShipTexture(1)));
	_sprite->setPosition(
		(_pos.x / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2),
		(_pos.y / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2)
		);
}

bool PlayerGraphical::update(std::vector<IObject*> &map)
{
  bool	ret;

  ret = Player::update();
	_sprite->setPosition(
		(_pos.x / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2),
		(_pos.y / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2)
		);
	return (ret);
}

bool	PlayerGraphical::update()
{


  return (true);
}
