#include "GameInfo.h"

GameInfo::GameInfo(std::string const& name, int id, int port)
  : _name(name), _id(id), _port(port)
{
}

GameInfo::~GameInfo()
{
}

std::string const& GameInfo::getName() const
{
  return _name;
}

int GameInfo::getPort() const
{
  return _port;
}

int	GameInfo::getID() const
{
  return _id;
}

bool GameInfo::addClient(ClientInfo * client)
{
  _clients.push_back(client);
}

std::vector<ClientInfo*> GameInfo::getClients() const
{
  return _clients;
}
