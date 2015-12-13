#include "PlayerGraphical.h"

PlayerGraphical::PlayerGraphical(sf::Vector2f speed, sf::Vector2i pos, float coeff, int id) :
  Player(speed, pos, coeff, id), GraphicalItem()
{
	_sprite->setTexture(*(ac->getShipTexture(1)));
	_sprite->setPosition(
		(_pos.x / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2),
		(_pos.y / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2)
		);
}

bool PlayerGraphical::update()
{
  bool	ret;

  ret = Player::update();
	_sprite->setPosition(
		(_pos.x / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2),
		(_pos.y / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2)
		);
	return (ret);
}
