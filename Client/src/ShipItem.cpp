#include "ShipItem.h"

ShipItem::ShipItem(int id)
{
	_sprite = new sf::Sprite;
	sf::Texture *text = ac->getShipTexture(id);
	_sprite->setTexture(*text);
}

ShipItem::~ShipItem()
{
}

void ShipItem::setPosition(sf::Vector2f newPosition)
{
	_position = newPosition;
	float newX = (_position.x / SCREENRATIO) - (SHIPASSETSIZE / 2);
	float newY = (_position.y / SCREENRATIO) - (SHIPASSETSIZE / 2);
	_sprite->setPosition(newX, newY);
}