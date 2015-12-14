#include "GameCore.hh"

GameCore::GameCore(std::string const&ip, std::string const& port)
  : _clients(new std::vector<GamerInfo*>()),
    _network(new UDPNetworkHandler(ip, port, _clients))
{
  std::cout << "start thread" << std::endl;
}

GameCore::~GameCore()
{
}

bool		GameCore::run()
{
  if (!_network->initSocket())
    return false;
  while (receivePacket());
}

bool					GameCore::receivePacket()
{
  GamerInfo*				client;
  IClientPacket<ClientUDPCommand>*	packet;

  if ((client = _network->selectClient()))
    {
      packet = _network->receiveFrom(client);
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
  client->setName(dynamic_cast<CAuthUDPPacket*>(packet)->getData()->data);
  client->setAuth(true);
  client->setID(_maxId++);
  _map->addObject(new Player(sf::Vector2f(0,0), sf::Vector2f(10,10), client->getID()));
}

void					GameCore::gamerTryShoot(GamerInfo* client, IClientPacket<ClientUDPCommand>* packet)
{
  dynamic_cast<Player*>(_map->getPlayer(client->getID()))->tryShoot();
  _map->updatePlayer(_map->getPlayer(client->getID()));
}

void					GameCore::gamerMove(GamerInfo* client, IClientPacket<ClientUDPCommand>* packet)
{
  dynamic_cast<Player*>(_map->getPlayer(client->getID()))->setDirection(dynamic_cast<SendMovePacket*>(packet)->getData()->dir);
  _map->updatePlayer(_map->getPlayer(client->getID()));
}

void					GameCore::gamerDisconnect(GamerInfo* client, IClientPacket<ClientUDPCommand>* packet)
{
  _map->deletePlayer(client->getID());
}
