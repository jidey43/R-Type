#include "GraphicalItem.h"

GraphicalItem::GraphicalItem()
{
	_sprite = new sf::Sprite;
}

sf::Drawable * GraphicalItem::getDrawable()
{
	return _sprite;
}
