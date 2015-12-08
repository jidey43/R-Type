#pragma once

#include "ViewController.hh"
#include "AssetsController.hh"

extern ViewController *vc;
extern AssetsController *ac;

class MenuController
{
public:
	MenuController();
	~MenuController();

public:
	void			loop();
	void			treatEvents();

private:
	sf::Clock		_clock;
	keyboardStatus	_keyboardStatus;
	sf::Time		_loopTime;
};