#include "GameCore.hh"

GameCore::GameCore(std::string const&ip, std::string const& port)
  : _clients(new std::vector<GamerInfo*>()),
    _network(new UDPNetworkHandler(ip, port, _clients)),
    _map(new MapController(_network)),
    _factory(new FactoryManager(_map, "../../level/Level1.lvl")),
    _referential(sf::Time(sf::microseconds(16666))),
    _running(true)
{
  std::cout << "start thread" << std::endl;
  this->run();
}

GameCore::~GameCore()
{
}

bool		GameCore::run()
{
  if (!_network->initSocket())
    return false;

  _clock.restart();
  while (_running)
    {
      _map->updateMap();
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
  // TODO : Parsing paquets
  switch (packet->getCommandType())
    {
    case CAUTH_UDP:
      {
	authGamer(client, packet);
	break;
      }
    case FIRE:
      {
	gamerTryShoot(client, packet);
	break;
      }
    case SEND_MOVE:
      {
	gamerMove(client, packet);
	break;
      }
    case DISCONNECT:
      {
	gamerDisconnect(client, packet);
	break;
      }
    default:
      {
	std::cout << "Unknown command" << std::endl;
	break;
      }
    }
  std::cout << "Packet Received" << std::endl;
  return true;
}

void					GameCore::authGamer(GamerInfo* client, IClientPacket<ClientUDPCommand>* packet)
{
  if (!client->isAuth())
    {
      client->setName(dynamic_cast<CAuthUDPPacket*>(packet)->getData()->data);
      client->setAuth(true);
      client->setID(_maxId++);
      _map->addObject(new Player(sf::Vector2f(0,0), sf::Vector2f(10,10), client->getID()));
    }
  _network->sendTo(client, new AuthUDPPacket(AUTH_UDP, 0, SUCCESS, "test"));
}

void					GameCore::gamerTryShoot(GamerInfo* client, IClientPacket<ClientUDPCommand>* packet)
{
  Player*				player = dynamic_cast<Player*>(_map->getPlayer(client->getID()));

  if (client->isAuth())
    {
      player->tryShoot();
      _map->updatePlayer(player);
      // if (player->isShooting())
      _network->broadcast(new CreObjPacket(CRE_OBJ, 0, player->getId(), player->getPos().x, player->getPos().y, 2, ObjectInfo::PLAYERREGULAR));
    }
}

void					GameCore::gamerMove(GamerInfo* client, IClientPacket<ClientUDPCommand>* packet)
{
  Player*				player = dynamic_cast<Player*>(_map->getPlayer(client->getID()));

  if (client->isAuth())
    {
      player->setDirection(dynamic_cast<SendMovePacket*>(packet)->getData()->dir);
      _map->updatePlayer(player);
      _network->sendTo(client, new MovePacket(MOVE, 0, client->getID(), player->getPos().x, player->getPos().y));
    }
}

void					GameCore::gamerDisconnect(GamerInfo* client, IClientPacket<ClientUDPCommand>* packet)
{
  _map->deletePlayer(client->getID());
}
