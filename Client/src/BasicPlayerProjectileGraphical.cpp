#include "..\inc\BasicPlayerProjectileGraphical.h"

BasicPlayerProjectileGrapical::BasicPlayerProjectileGrapical(sf::Vector2f speed, sf::Vector2i pos, float coeff) :
	BasicPlayerProjectile(speed, pos, coeff), GraphicalItem()
{
	_sprite->setTexture(*(ac->getShot(BASICPLAYERSHOT)));
	_sprite->setPosition(
		(_pos.x / SCREENRATIO) - (SHOT_ASSET_SIZE_Y / 2),
		(_pos.y / SCREENRATIO) - (SHOT_ASSET_SIZE_X / 2)
		);

}

void BasicPlayerProjectileGrapical::update()
{
	BasicPlayerProjectile::update();
	_sprite->setPosition(
		(_pos.x / SCREENRATIO) - (SHOT_ASSET_SIZE_Y / 2),
		(_pos.y / SCREENRATIO) - (SHOT_ASSET_SIZE_Y / 2)
		);

}
