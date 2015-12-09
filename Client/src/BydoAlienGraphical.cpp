#include "..\inc\BydoAlienGraphical.hh"

BydoAlienGraphical::BydoAlienGraphical(sf::Vector2f speed, sf::Vector2i pos, float coeff) 
	: BydoAlien(speed, pos, coeff), GraphicalItem()
{
	_sprite->setTexture(*(ac->getShipTexture(1)));
	_sprite->setPosition(
	(_pos.x / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2),
	(_pos.y / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2)
	);
}

void BydoAlienGraphical::update()
{
	BydoAlien::update();
	_sprite->setPosition(
		(_pos.x / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2),
		(_pos.y / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2)
		);
}
