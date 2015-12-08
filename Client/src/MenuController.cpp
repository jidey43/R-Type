#include "MenuController.hh"

MenuController::MenuController()
{
	_buttons.resize(NUMBEROFBUTTON);
	_buttons[EXIT] = new JoinButton;
	_buttons[JOIN] = new JoinButton;
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
}

void MenuController::update()
{
	for (int i = 0; i != _buttons.size(); i++)
	{
		_buttons[i]->update(_keyboardStatus.mousePos);
	}
}

void MenuController::drawMenuItems()
{
	for (int i = 0; i != _buttons.size(); i++)
	{
		vc->draw(_buttons[i]->getDrawable());
	}
}
