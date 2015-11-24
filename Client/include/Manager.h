#pragma once

#include "ViewController.h"
#include "SoundController.h"

extern ViewController *vc;

class					Manager
{
public:
	Manager();
	~Manager();

public:
	void				loop();

private:
	sf::Clock			_clock;
	sf::Time			_loopTime;

private:
	SoundController		*_soundCtrl;
};