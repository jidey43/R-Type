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
    sf::Time elapsed;
    sf::Time lastTime;
 //STARTING GAME

	// vc->startSoundtrack();
  _itemCtrl->setBackground(1);
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

      elapsed = getElapsedTimeSinceLoop();
      lastTime = sf::microseconds(0);
      while ((elapsed = getElapsedTimeSinceLoop()) > lastTime)
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
      std::cout << "CRE_PLAY RECEIVED" << std::endl;
      _itemCtrl->addShip(dynamic_cast<CrePlayPacket*>(res));
      break;
    case CRE_OBJ:
      std::cout << "CRE_OBJ RECEIVED" << std::endl;
      _itemCtrl->addObj(dynamic_cast<CreObjPacket*>(res));
      break;
    case CRE_IA:
      std::cout << "CRE_IA RECEIVED" << std::endl;
      _itemCtrl->addAlien(dynamic_cast<CreIAPacket*>(res));
      break;
    case DEL_ITEM:
      std::cout << "DEL_ITEM RECEIVED" << std::endl;
      _itemCtrl->deleteObject(dynamic_cast<DelItemPacket*>(res));
      break;
    case MOVE:
      std::cout << "MOVE RECEIVED" << std::endl;
      _itemCtrl->moveShip(dynamic_cast<MovePacket*>(res));
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
      if (res = _udpHand->receive())
	treatPacket(res);
    }
}
