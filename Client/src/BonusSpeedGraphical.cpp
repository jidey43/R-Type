#include "BonusSpeedGraphical.hh"

BonusSpeedGraphical::BonusSpeedGraphical(sf::Vector2f const& speed,
		       sf::Vector2f const& pos,
		       sf::Vector2i const& size,
		       ObjectInfo::Type type,
		       unsigned int id) :
               BonusSpeed(speed, pos, size, type, id), GraphicalItem()
{
    
}

BonusSpeedGraphical::~BonusSpeedGraphical()
{
    
}

bool                BonusSpeedGraphical::update(sf::Clock const&)
{
    
}