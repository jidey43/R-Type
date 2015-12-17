#include "GameCore.hh"

GameCore::GameCore(std::string const&ip, std::string const& port)
  : _clients(new std::vector<GamerInfo*>()),
    _network(new UDPNetworkHandler(ip, port, _clients)),
    _map(new MapController()),
    _factory(new FactoryManager(_map, "../../level/Level1.lvl")),
    _referential(sf::Time(sf::microseconds(16666))),
    _running(true)
{
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
      _map->updateMap(_clock);
      this->sendMap(NULL);
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

void							GameCore::sendMap(GamerInfo* client)
{
  std::vector<IServerPacket<ServerUDPResponse>*>*	toSend;
  IServerPacket<ServerUDPResponse>*			packetToSend;

  toSend = _map->getMap();
  while (!toSend->empty())
    {
      packetToSend = toSend->back();
      if (client)
	_network->sendTo(client, packetToSend);
      else
	_network->broadcast(packetToSend);
      delete packetToSend;
      toSend->pop_back();
    }
}

void							GameCore::authGamer(GamerInfo* client, IClientPacket<ClientUDPCommand>* packet)
{
  Player*						player;

  if (!client->isAuth())
    {
      client->setName(static_cast<CAuthUDPPacket*>(packet)->getData()->data);
      client->setAuth(true);
      client->setID(_maxId++);
      _map->addObject(new Player(sf::Vector2f(10,6), sf::Vector2f(50,50), client->getID()));
    }
   player = static_cast<Player*>(_map->getPlayer(client->getID()));
   _map->generatePacketsMap(player);
   _network->sendTo(client, new AuthUDPPacket(AUTH_UDP, 0, SUCCESS));
   this->sendMap(client);
   _network->broadcast(new CrePlayPacket(CRE_PLAY, 0, player->getId(), player->getPos().x, player->getPos().y));
}

void					GameCore::gamerTryShoot(GamerInfo* client, IClientPacket<ClientUDPCommand>* packet)
{
  Player*				player = static_cast<Player*>(_map->getPlayer(client->getID()));

  if (player && client->isAuth())
    {
      player->tryShoot();
    }
}


void					GameCore::gamerMove(GamerInfo* client, IClientPacket<ClientUDPCommand>* packet)
{
  Player*				player = static_cast<Player*>(_map->getPlayer(client->getID()));

  if (player && client->isAuth())
    {
      player->setDirection(static_cast<SendMovePacket*>(packet)->getData()->dir);
      _map->updatePlayer(player, _clock);
      _network->broadcast(new MovePacket(MOVE, 0, client->getID(), player->getPos().x, player->getPos().y));
    }
}

void					GameCore::gamerDisconnect(GamerInfo* client, IClientPacket<ClientUDPCommand>* packet)
{
  _map->deletePlayer(client->getID());
}
