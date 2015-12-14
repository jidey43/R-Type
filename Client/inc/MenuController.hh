#pragma once

#include "ViewController.hh"
#include "AssetsController.hh"
#include "JoinButton.h"
#include "ExitButton.h"
#include "TextArea.h"
#include "Background.h"

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
	void						onClick(ButtonType);
	void						joinGame();

private:
	sf::Clock					_clock;
	keyboardStatus				_keyboardStatus;
	Backgroud*					_background;
	sf::Time					_loopTime;
	std::vector<MenuButton*>	_buttons;
	bool						_join;
	sf::Sprite					_logo;
	TextArea*					_ipArea;
	TextArea*					_portArea;
	TextArea*					_nicknameArea;
};