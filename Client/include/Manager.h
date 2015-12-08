#pragma once

#include "ViewController.h"
#include "AssetsController.h"
#include "ItemController.h"

extern ViewController *vc;
extern AssetsController *ac;

class					Manager
{
public:
	Manager();
	~Manager();

public:
	void				loop();
	void				treatEvents();

private:
	sf::Clock			_clock;
	sf::Time			_loopTime;

private:
	keyboardStatus		_keyboardStatus;
	ItemController		*_itemCtrl;
};