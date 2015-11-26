#include "Manager.h"

Manager::Manager()
{
	_itemCtrl = new ItemController;
}

Manager::~Manager()
{

}

void					Manager::loop()
{

	//STARTING

	//vc->startSoundtrack();
	_itemCtrl->addShip(1);

	//GAME LOOP
	while (1)
	{
		_clock.restart();
		vc->clear();
		vc->getEvents();
		_itemCtrl->draw();
		vc->refresh();
		_loopTime = _clock.getElapsedTime();
		sf::sleep(sf::Time(sf::microseconds(16666)) - _loopTime);
	}
}