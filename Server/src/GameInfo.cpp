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

int GameInfo::getPlayerNb() const
{
  return _clients.size();
}

int	GameInfo::getID() const
{
  return _id;
}

bool GameInfo::addClient(ClientInfo * client)
{
  if (_clients.size() < MAX_PLAYERS)
    _clients.push_back(client);
  else
    return false;
  return true;
}

std::string const GameInfo::getClients() const
{
  std::string	buffer = "";

  for (std::vector<ClientInfo*>::const_iterator it = _clients.begin(); it != _clients.end(); ++it)
    {
      buffer += (*it)->getNickname() + "\n";
    }
  return buffer;
}
