#include "GameInfo.h"

GameInfo::GameInfo(std::string const& name, int id, int port, std::string const& ip)
  : _name(name), _id(id), _port(port), _thread(new UThread(std::to_string(port), ip))
{
}

GameInfo::~GameInfo()
{
  for (std::vector<ClientInfo*>::iterator it = _clients.begin(); it != _clients.end(); ++it)
    (*it)->setInGame(false);
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
  client->setInGame(true);
  return true;
}

std::string const& GameInfo::getClients() const
{
  static std::string	buffer = "";

  for (std::vector<ClientInfo*>::const_iterator it = _clients.begin(); it != _clients.end(); ++it)
    {
      buffer += (*it)->getNickname() + "\n";
    }
  return buffer;
}

int		GameInfo::tryJoinGame()
{
  if (_thread->TryWaitThread())
    return _port;
  else
    return -1;
}
