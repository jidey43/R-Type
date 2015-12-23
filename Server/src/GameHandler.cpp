#include <algorithm>
#include "GameHandler.h"

GameHandler::GameHandler(std::string const& ip)
  : _maxID(13), _ip(ip)
{
  for (int i = BASE_PORT; i < BASE_PORT + MAX_GAME; ++i)
    {
      _ports.push_back(i);
    }
}

GameHandler::~GameHandler()
{
}

GameInfo* GameHandler::addClientInGame(ClientInfo * client, int id)
{
  for (std::vector<GameInfo*>::iterator it = _gameList.begin(); it != _gameList.end(); ++it)
    {
      if ((*it)->getID() == id && (*it)->addClient(client))
	{
	  return (*it);
	}
    }
  return NULL;
}

int GameHandler::startNewGame(std::string const &name)
{
  if (_ports.size() == 0)
    return -1;
  _gameList.push_back(new GameInfo(name, _maxID++, _ports.back(), _ip));
  _ports.pop_back();
  return _maxID - 1;
}

std::vector<GameInfo*>& GameHandler::getGameList()
{
  tryJoinGames();
  return _gameList;
}

void		GameHandler::tryJoinGames()
{
  int		port;
  std::vector<GameInfo*>::iterator it = _gameList.begin();
  std::vector<GameInfo*>::iterator itTmp;

  while (it != _gameList.end())
    {
      if ((port = (*it)->tryJoinGame()) != -1)
	{
	  std::cout << "tototototototo" << std::endl;
	  _ports.push_back(port);
	  delete (*it);
	  itTmp = it + 1;
	  _gameList.erase(it);
	  it = itTmp;
	}
      else
	it++;
    }
}
