#include "BasicPlayerProjectileGraphical.h"

BasicPlayerProjectileGrapical::BasicPlayerProjectileGrapical(sf::Vector2f speed, sf::Vector2f pos, unsigned int id) :
	BasicPlayerProjectile(speed, pos, id), GraphicalItem()
{
	_sprite->setTexture(*(ac->getShot(BASICPLAYERSHOT)));
	_sprite->setPosition(
		(_pos.x / SCREENRATIO) - (SHOT_ASSET_SIZE_Y / 2),
		(_pos.y / SCREENRATIO) - (SHOT_ASSET_SIZE_X / 2)
		);

}

bool	BasicPlayerProjectileGrapical::update(sf::Clock const& clock)
{
  bool	ret;
  ret = BasicPlayerProjectile::update(clock);
	_sprite->setPosition(
		(_pos.x / SCREENRATIO) - (SHOT_ASSET_SIZE_X / 2),
		(_pos.y / SCREENRATIO) - (SHOT_ASSET_SIZE_Y / 2)
		);
	return (ret);
}
