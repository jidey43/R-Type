#include "GameHandler.h"

GameHandler::GameHandler()
  : _maxID(13)
{
  _ports.push_back(4010);
  _ports.push_back(4011);
  _ports.push_back(4012);
  _ports.push_back(4013);
  _ports.push_back(4014);
  _ports.push_back(4015);
  _ports.push_back(4016);
}

GameHandler::~GameHandler()
{
}

GameInfo* GameHandler::addClientInGame(ClientInfo * client, int id)
{
  for (std::vector<GameInfo*>::iterator it = _gameList.begin(); it != _gameList.end(); ++it)
    {
      if ((*it)->getID() == id /* && nbPlayer < n */)
	{
	  (*it)->addClient(client);
	  return (*it);
	}
    }
  return NULL;
}

int GameHandler::startNewGame(std::string const & name)
{
  if (_ports.size() == 0)
    return -1;
  for (std::vector<GameInfo*>::iterator it = _gameList.begin(); it != _gameList.end(); ++it)
    if ((*it)->getName() == name)
      return -1;
  _gameList.push_back(new GameInfo(name, _maxID++, _ports.back()));
  _ports.pop_back();
  return _maxID - 1;
}

std::vector<GameInfo*>& GameHandler::getGameList()
{
  return _gameList;
}
