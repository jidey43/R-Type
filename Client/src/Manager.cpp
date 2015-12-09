#include "Manager.hh"

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
	_itemCtrl->addAlien(ObjectInfo::BYDO, sf::Vector2f(42, 42), sf::Vector2i(100, 100), 1 );
	_itemCtrl->setBackgroud(BACKGROUND_ONE);

	//GAME LOOP
	while (1)
	{
		_clock.restart();
		vc->clear();

		_itemCtrl->update();
		
		_keyboardStatus =  vc->getKeyboardStatus();
		treatEvents();

		_itemCtrl->draw();

		vc->refresh();
		_loopTime = _clock.getElapsedTime();
		sf::sleep(sf::Time(sf::microseconds(16666)) - _loopTime);
	}
}

void Manager::treatEvents()
{
	
}
