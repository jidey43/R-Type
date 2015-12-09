#include "MenuController.hh"

MenuController::MenuController()
{
	_join = false;
	_ipArea = new TextArea(STAR, sf::Vector2f((RES_X / 2) - (LOGO_SIZE_X / 2), RES_Y * 0.3), 
			sf::Vector2f(500,50), "Enter ip");
	
	_portArea = new TextArea(STAR, sf::Vector2f((RES_X / 2) - (LOGO_SIZE_X / 2), RES_Y * 0.4),
		sf::Vector2f(500, 50), "Enter port");

	_nicknameArea = new TextArea(STAR, sf::Vector2f((RES_X / 2) - (LOGO_SIZE_X / 2), RES_Y * 0.5),
			sf::Vector2f(500, 50), "Enter nickname");

	_buttons.resize(NUMBEROFBUTTON);
	_buttons[EXIT] = new ExitButton;
	_buttons[JOIN] = new JoinButton;

	_background.setTexture(*(ac->getBackground(MENU_BACKGROUND)));
	_background.setPosition(sf::Vector2f(0, 0));
	_logo.setTexture(*(ac->getLogo()));
	_logo.setPosition(sf::Vector2f((RES_X / 2) - (LOGO_SIZE_X / 2), RES_Y * 0.05));
}

MenuController::~MenuController()
{
}

void MenuController::loop()
{
	while (true)
	{
		_clock.restart();
		vc->clear();

		if (_join)
			return;

		_keyboardStatus = vc->getKeyboardStatus();
		treatEvents();

		update();
		drawMenuItems();

		vc->refresh();
		_loopTime = _clock.getElapsedTime();
		sf::sleep(sf::Time(sf::microseconds(16666)) - _loopTime);
	}
}

void MenuController::treatEvents()
{
	if (_keyboardStatus.leftClick == true)
		for (int i = 0; i != _buttons.size(); i++)
		{
			if (_buttons[i]->getIsHigh())
				onClick((ButtonType)i);
		}
}

void MenuController::update()
{
	for (int i = 0; i != _buttons.size(); i++)
	{
		_buttons[i]->update(_keyboardStatus.mousePos);
	}
	_ipArea->update(_keyboardStatus);
	_portArea->update(_keyboardStatus);
	_nicknameArea->update(_keyboardStatus);
}

void MenuController::drawMenuItems()
{
	vc->draw(&_background);
	vc->draw(&_logo);
	vc->draw(_ipArea->getTextArea());
	vc->draw(_ipArea->getDrawableText());
	vc->draw(_portArea->getTextArea());
	vc->draw(_portArea->getDrawableText());
	vc->draw(_nicknameArea->getTextArea());
	vc->draw(_nicknameArea->getDrawableText());
	for (int i = 0; i != _buttons.size(); i++)
	{
		vc->draw(_buttons[i]->getDrawable());
	}
}

void MenuController::onClick(ButtonType type)
{
	switch (type)
	{
	case JOIN:
		joinGame();
		break;
	case EXIT:
		exit(0);
		break;
	}
}

void MenuController::joinGame()
{
	_join = true;
}