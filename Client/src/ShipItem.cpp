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
