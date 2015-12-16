#include "GameCore.hh"

GameCore::GameCore(std::string const&ip, std::string const& port)
  : _clients(new std::vector<GamerInfo*>()),
    _network(new UDPNetworkHandler(ip, port, _clients)),
    _map(new MapController()),
    _factory(new FactoryManager(_map, "../../level/Level1.lvl")),
    _referential(sf::Time(sf::microseconds(16666))),
    _running(true)
{
  std::cout << "start thread" << std::endl;
  this->run();
}

GameCore::~GameCore()
{
  for (auto& client : *_clients)
    {
      delete client;
    }
  delete _clients;
}

bool		GameCore::run()
{
  if (!_network->initSocket())
    return false;

  _clock.restart();
  while (_running)
    {
      _map->updateMap(// _clock
		      );
      sf::Time elapsed;
      sf::Time lastTime = sf::microseconds(0);
      while (_running && (elapsed = getElapsedTimeSinceLoop()) > lastTime)
	{
	  lastTime = elapsed;
	  receivePacket();
	}
    }
}

sf::Time	GameCore::getElapsedTimeSinceLoop()
{
  sf::Time ret;

  ret = sf::microseconds(_clock.getElapsedTime().asMicroseconds() % _referential.asMicroseconds());
  return ret;
}

bool					GameCore::receivePacket()
{
  GamerInfo*				client;
  IClientPacket<ClientUDPCommand>*	packet;

  if ((client = _network->selectClient()))
    {
      packet = _network->receiveFrom(client);
      if (packet)
	processPacket(client, packet);
    }
  return true;
}

bool					GameCore::processPacket(GamerInfo* client,
								IClientPacket<ClientUDPCommand>* packet)
{
  switch (packet->getCommandType())
    {
    case CAUTH_UDP:
      authGamer(client, packet);
      break;
    case FIRE:
      gamerTryShoot(client, packet);
      break;
    case SEND_MOVE:
      gamerMove(client, packet);
      break;
    case DISCONNECT:
      gamerDisconnect(client, packet);
      break;
    default:
      break;
    }
  return true;
}

void							GameCore::authGamer(GamerInfo* client, IClientPacket<ClientUDPCommand>* packet)
{
  Player*						player;
  std::vector<IServerPacket<ServerUDPResponse>*>*	toSend;
  IServerPacket<ServerUDPResponse>*			packetToSend;

  if (!client->isAuth())
    {
      client->setName(static_cast<CAuthUDPPacket*>(packet)->getData()->data);
      client->setAuth(true);
      client->setID(_maxId++);
      _map->addObject(new Player(sf::Vector2f(10,6), sf::Vector2f(50,50), client->getID()));
    }
   player = static_cast<Player*>(_map->getPlayer(client->getID()));
   _map->generatePacketsMap(player);
   toSend = _map->getMap();
   while (!toSend->empty())
     {
       packetToSend = toSend->back();
       _network->sendTo(client, packetToSend);
       delete packetToSend;
       toSend->pop_back();
     }
   _network->sendTo(client, new AuthUDPPacket(AUTH_UDP, 0, SUCCESS));
   _network->broadcast(new CrePlayPacket(CRE_PLAY, 0, player->getId(), player->getPos().x, player->getPos().y));
}

void					GameCore::gamerTryShoot(GamerInfo* client, IClientPacket<ClientUDPCommand>* packet)
{
  Player*				player = static_cast<Player*>(_map->getPlayer(client->getID()));

  if (player && client->isAuth())
    {
      player->tryShoot();
      _map->updatePlayer(player);
      if (player->isShooting())
	{
	  _map->addObject(player->BasicShoot());
	  _network->broadcast(new CreObjPacket(CRE_OBJ, 0, player->getId(), player->getPos().x, player->getPos().y, 15, ObjectInfo::PLAYERREGULAR));
	}
    }
}

void					GameCore::gamerMove(GamerInfo* client, IClientPacket<ClientUDPCommand>* packet)
{
  Player*				player = static_cast<Player*>(_map->getPlayer(client->getID()));

  if (player && client->isAuth())
    {
      player->setDirection(static_cast<SendMovePacket*>(packet)->getData()->dir);
      _map->updatePlayer(player);
      _network->broadcast(new MovePacket(MOVE, 0, client->getID(), player->getPos().x, player->getPos().y));
    }
}

void					GameCore::gamerDisconnect(GamerInfo* client, IClientPacket<ClientUDPCommand>* packet)
{
  _map->deletePlayer(client->getID());
}
