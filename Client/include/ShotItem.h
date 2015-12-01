#pragma once

#include "GameItem.h"

class ShotItem : public GameItem
{
public:
	ShotItem(int distance, int time, int skin);
	~ShotItem();

private:
	int _distance;
	int _time;

};