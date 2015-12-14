#pragma once

#include "ViewController.hh"
#include "AssetsController.hh"
#include "ItemController.hh"
#include "ObjectInfo.hpp"


extern ViewController *vc;
extern AssetsController *ac;

class					Manager
{
public:
	Manager();
	~Manager();

public:
	void				loop();
	void				treatEventsFromKeyboard();
	void				treatEventsFromNetwork();

private:
	sf::Clock			_clock;
	sf::Time			_loopTime;

private:
	keyboardStatus		_keyboardStatus;
	ItemController		*_itemCtrl;
};
