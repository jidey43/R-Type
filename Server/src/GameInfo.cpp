#include "GameInfo.h"

GameInfo::GameInfo(std::string const& name, int port)
	: _name(name), _port(port)
{
}

GameInfo::~GameInfo()
{
}

std::string GameInfo::getName() const
{
	return _name;
}

int GameInfo::getPort() const
{
	return _port;
}

bool GameInfo::addClient(ClientInfo * client)
{
	_clients.push_back(client);
}

std::vector<ClientInfo*> GameInfo::getClients() const
{
	return _clients;
}

