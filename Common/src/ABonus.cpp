#include "ABonus.hh"

ABonus::ABonus(sf::Vector2f const& speed,
	       sf::Vector2f const& pos,
	       sf::Vector2i const& size,
	       ObjectInfo::Type type,
	       unsigned int id)
  : Object(speed, pos, size, type, id)
{
}

ABonus::~ABonus()
{
}
