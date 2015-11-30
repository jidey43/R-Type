#include "GameHandler.h"

GameHandler::GameHandler()
	: _maxPort(4010)
{
}

GameHandler::~GameHandler()
{
}

bool GameHandler::addClientInGame(ClientInfo * client, std::string const& name)
{
	for (std::vector<GameInfo*>::iterator it = _gameList.begin(); it != _gameList.end(); ++it)
	{
		if ((*it)->getName() == name)
		{
			(*it)->addClient(client);
			return true;
		}
	}
	return false;
}

bool GameHandler::startNewGame(std::string const & name)
{
	for (std::vector<GameInfo*>::iterator it = _gameList.begin(); it != _gameList.end(); ++it)
		if ((*it)->getName() == name)
			return false;
	_gameList.push_back(new GameInfo(name, _maxPort++));
	return true;
}

std::vector<GameInfo*>& GameHandler::getGameList()
{
	return _gameList;
}
