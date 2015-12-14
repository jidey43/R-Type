#include "BydoAlienGraphical.hh"

BydoAlienGraphical::BydoAlienGraphical(sf::Vector2f speed, sf::Vector2f pos, unsigned int id, float coeff)
  : BydoAlien(speed, pos, id, coeff), GraphicalItem()
{
	_sprite->setTexture(*(ac->getAlien(BYDO)));
	_sprite->setPosition(
	(_pos.x / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2),
	(_pos.y / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2)
	);
}

bool BydoAlienGraphical::update()
{
  bool	ret;

  ret = BydoAlien::update();
	_sprite->setPosition(
		(_pos.x / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2),
		(_pos.y / SCREENRATIO) - (SHIP_ASSET_SIZE_Y / 2)
		);
	return (ret);
}

bool	BydoAlienGraphical::update(std::vector<IObject*>&)
{
  return (true);
}
