#include "ShotItem.h"

ShotItem::ShotItem(sf::Vector2f startPos, int distance, int time, int skin)
{

	_distance = distance;
	_timeReference = sf::milliseconds(time);
	_sprite = new sf::Sprite;
	_sprite->setTexture(*(ac->getShot(skin)));
	_startPos = startPos;
	setPosition(startPos);
	_clock.restart();
	_die = false;
}

ShotItem::~ShotItem()
{

}

void ShotItem::setPosition(sf::Vector2f newPosition)
{
	_position = newPosition;
	float newX = (_position.x / SCREENRATIO) - (SHOT_ASSET_SIZE_Y / 2);
	float newY = (_position.y / SCREENRATIO);
	_sprite->setPosition(newX, newY);
	if (newX > MAP_SIZE_X)
		_die = true;
}

void ShotItem::update()
{
	sf::Time elapsed = _clock.getElapsedTime();
	int newPosX = elapsed.asMilliseconds() * _distance;
	setPosition(sf::Vector2f(newPosX, _startPos.y));
}

bool ShotItem::die()
{
	return _die;
}


