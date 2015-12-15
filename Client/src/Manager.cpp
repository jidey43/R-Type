#include "Manager.hh"

Manager::Manager(CUDPNetworkHandler *udpHand) : _udpHand(udpHand)
{
	_itemCtrl = new ItemController;
	_referential = sf::Time(sf::microseconds(16666));
}

Manager::~Manager()
{

}

void					Manager::loop()
{

	//STARTING GAME

	//vc->startSoundtrack();

	//PARTIE DE TEST DES ITEMS,  A DELETE
 	_itemCtrl->addAlien(ObjectInfo::BYDO, sf::Vector2f(42, 42), sf::Vector2f(500, 300), 1, 1.0);
	_itemCtrl->addShip(sf::Vector2f(10,10), sf::Vector2f(50, 50), 100);
	_itemCtrl->addShot(BASICALIENSHOT, sf::Vector2f(42, 42), sf::Vector2f(100, 100), 1);
	_itemCtrl->setBackgroud(BACKGROUND_ONE);

		//GAME LOOP
		_clock.restart();
		while (1)
		{
			vc->clear();
			_itemCtrl->draw();
			vc->refresh();

			_itemCtrl->update();
			_keyboardStatus =  vc->getKeyboardStatus();
			treatEventsFromKeyboard();



			sf::Time elapsed = getElapsedTimeSinceLoop();
			sf::Time lastTime = sf::microseconds(0);
			while ((elapsed = getElapsedTimeSinceLoop()) > lastTime )
			{
				lastTime = elapsed;
				treatEventsFromNetwork();
			}
		}
}

sf::Time Manager::getElapsedTimeSinceLoop()
{
	sf::Time ret;

 ret = sf::microseconds(_clock.getElapsedTime().asMicroseconds() % _referential.asMicroseconds());
	return ret;
}

void Manager::treatEventsFromKeyboard()
{
	if (_keyboardStatus.up)
		_udpHand->send(new SendMovePacket(SEND_MOVE, 0, UP));
	if (_keyboardStatus.down)
		_udpHand->send(new SendMovePacket(SEND_MOVE, 0, DOWN));
	if (_keyboardStatus.left)
		_udpHand->send(new SendMovePacket(SEND_MOVE, 0, LEFT));
	if (_keyboardStatus.right)
		_udpHand->send(new SendMovePacket(SEND_MOVE, 0, RIGHT));
	if (_keyboardStatus.ctrl)
		_udpHand->send(new FirePacket(FIRE, 0, 0, 0));
}

void Manager::treatPacket(IServerPacket<ServerUDPResponse>* res)
{
	ServerUDPResponse		packetType = res->getCommandType();

	switch (packetType)
	{
		case CRE_PLAY:
			break;
		case CRE_OBJ:
			break;
		case CRE_IA:
			break;
		case DEL_ITEM:
			break;
		case MOVE:
			break;
		default:
			break;
	}
}

void Manager::treatEventsFromNetwork()
{
			struct timeval to;
			to.tv_sec = 0;
			to.tv_usec = 1;
			IServerPacket<ServerUDPResponse> *res;

			if (_udpHand->selectServer(&to))
			{
				res = _udpHand->receive();
				treatPacket(res);
			}

}
