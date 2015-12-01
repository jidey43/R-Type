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

	//STARTING GAME

	//vc->startSoundtrack();
	_itemCtrl->addShip(1);
	_itemCtrl->addShip(2);
	_itemCtrl->addShip(3);
	_itemCtrl->addShip(4);
	_itemCtrl->addShot(sf::Vector2f(0, 500), 1, 1, 1);

	_itemCtrl->moveShip(1, sf::Vector2f(800, 600));
	_itemCtrl->moveShip(2, sf::Vector2f(200, 200));
	_itemCtrl->moveShip(3, sf::Vector2f(1300, 700));
	_itemCtrl->moveShip(4, sf::Vector2f(1000, 300));
	_itemCtrl->setBackgroud(1);

	//GAME LOOP
	while (1)
	{
		_clock.restart();
		//vc->clear();
		vc->getEvents();
		_itemCtrl->update();
		_itemCtrl->draw();
		vc->refresh();
		_loopTime = _clock.getElapsedTime();
		sf::sleep(sf::Time(sf::microseconds(16666)) - _loopTime);
	}
}