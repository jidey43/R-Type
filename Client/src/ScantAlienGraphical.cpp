#include "ScantAlienGraphical.hh"

ScantAlienGraphical::ScantAlienGraphical(sf::Vector2f speed, sf::Vector2f pos, unsigned int id, float coeff)
  : ScantAlien(speed, pos, id, coeff), GraphicalItem()
{
	_sprite->setTexture(*(ac->getAlien(SCANT)));
	_sprite->setPosition(
	_pos.x / SCREENRATIO,
	_pos.y / SCREENRATIO
	);
}

bool ScantAlienGraphical::update(sf::Clock const& clock)
{
  bool	ret;

  ret = ScantAlien::update(clock);
  _sprite->setPosition(
		_pos.x,
		_pos.y
		);
	return (ret);
}

bool	ScantAlienGraphical::update(std::vector<IObject*>&, sf::Clock const&)
{
  return (true);
}