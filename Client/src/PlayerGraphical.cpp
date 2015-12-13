#include "PlayerGraphical.h"

PlayerGraphical::PlayerGraphical(sf::Vector2f speed, sf::Vector2i pos, float coeff) :
	Player(speed, pos, coeff), GraphicalItem()
{
	_sprite->setTexture(*(ac->getShipTexture(1)));
	_sprite->setPosition(
		(_pos.x / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2),
		(_pos.y / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2)
		);
}

void PlayerGraphical::update()
{
	_sprite->setPosition(
		(_pos.x / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2),
		(_pos.y / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2)
		);
}
