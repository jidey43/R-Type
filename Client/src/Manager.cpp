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

	//PARTIE DE TEST DES ITEMS,  A DELETE
	_itemCtrl->addAlien(ObjectInfo::BYDO, sf::Vector2f(42, 42), sf::Vector2i(500, 300), 1 );
	_itemCtrl->addShip(sf::Vector2f(10,10), sf::Vector2i(50, 50), 100);
	_itemCtrl->addShot(BASICALIENSHOT, sf::Vector2f(42, 42), sf::Vector2i(100, 100), 1);
	_itemCtrl->setBackgroud(BACKGROUND_ONE);

	//GAME LOOP
	while (1)
	{
		_clock.restart();
		vc->clear();

		_itemCtrl->update();

		_keyboardStatus =  vc->getKeyboardStatus();
		treatEventsFromKeyboard();

		_itemCtrl->draw();

		vc->refresh();
		_loopTime = _clock.getElapsedTime();
		sf::sleep(sf::Time(sf::microseconds(16666)) - _loopTime);
	}
}

void Manager::treatEventsFromKeyboard()
{
	if (_keyboardStatus.up)
		std::cout << "il a appuyé sur haut\n";
	if (_keyboardStatus.down)
		std::cout << "il a appuyé sur bas\n";
	if (_keyboardStatus.left)
		std::cout << "il a appuyé sur gauche\n";
	if (_keyboardStatus.right)
		std::cout << "il a appuyé sur droite\n";
	if (_keyboardStatus.ctrl)
		std::cout << "il a appuyé sur tirer  !\n";

}

void Manager::treatEventsFromNetwork()
{

}
