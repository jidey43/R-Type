#include "BasicPlayerProjectileGraphical.h"

BasicPlayerProjectileGrapical::BasicPlayerProjectileGrapical(sf::Vector2f speed, sf::Vector2f pos, unsigned int id) :
	BasicPlayerProjectile(speed, pos, id), GraphicalItem()
{
    _sound.setBuffer(*(ac->getSound(BASICSHOT)));
    _sound.play();
	_sprite->setTexture(*(ac->getShot(BASICPLAYERSHOT)));
	_sprite->setPosition(
		_pos.x,
		_pos.y
		);

}

bool	BasicPlayerProjectileGrapical::update(sf::Clock const& clock)
{
  bool	ret;
  ret = BasicPlayerProjectile::update(clock);
	_sprite->setPosition(
		_pos.x,
		_pos.y
		);
	return (ret);
}
