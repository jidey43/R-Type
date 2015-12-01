#include "ShotItem.h"

ShotItem::ShotItem(int distance, int time, int skin)
{

	_distance = distance;
	_time = time;
	_sprite = new sf::Sprite;
	_sprite->setTexture(*(ac->getShot(skin)));
}

ShotItem::~ShotItem()
{

}