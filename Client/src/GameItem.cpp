#include "GameItem.hh"

sf::Drawable * GameItem::getDrawable()
{
	return _sprite;
}

sf::Vector2f GameItem::getPosition()
{
	return _position;
}
