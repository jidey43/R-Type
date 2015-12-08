#pragma once

#include "ViewController.hh"
#include "AssetsController.hh"
#include <JoinButton.h>

extern ViewController *vc;
extern AssetsController *ac;

class MenuController
{
public:
	MenuController();
	~MenuController();

public:
	void						loop();
	void						treatEvents();
	void						update();
	void						drawMenuItems();

private:
	sf::Clock					_clock;
	keyboardStatus				_keyboardStatus;
	sf::Time					_loopTime;
	std::vector<MenuButton*>		_buttons;
};