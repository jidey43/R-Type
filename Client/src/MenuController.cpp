#include "MenuController.hh"

MenuController::MenuController()
{

}

MenuController::~MenuController()
{

}

void MenuController::loop()
{
	_clock.restart();
	vc->clear();

	_keyboardStatus = vc->getKeyboardStatus();
	treatEvents();

	//_itemCtrl->update();
	//_itemCtrl->draw();

	vc->refresh();
	_loopTime = _clock.getElapsedTime();
	sf::sleep(sf::Time(sf::microseconds(16666)) - _loopTime);
}

void MenuController::treatEvents()
{
}
