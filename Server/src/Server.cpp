#include "Server.h"

#include <iostream>
#include <algorithm>
#include <string.h>
#include "NetworkDefines.h"
#include "WNetwork.hh"


Server::Server(std::string const & ip, std::string const & port)
	: _network(new NetworkHandler(ip, port)), _cPacket(new ClientPacket)
{
	if ((_listen = _network->initSocket()) != INVALID_SOCKET)
	{
		std::cout << "server strated" << std::endl;
		start();
	}
}

Server::~Server()
{
	delete _network;
}

void Server::start()
{
	while (1)
	{
		_network->selectClient(_clientList);
		if (_network->isClientSet(_listen) && !acceptClient())
		{
			std::cout << "client connection failed, closing server" << std::endl;
			// system("pause");
			return;
		}
		setClients();
	}
}

void Server::setClients()
{
	for (std::vector<ClientInfo*>::iterator it = _clientList.begin(); it != _clientList.end(); ++it)
	{
		if (_network->isClientSet((*it)->getSocket()))
		{
			wipePacket();
			if (_network->receiveFromClient((*it)->getSocket(), _cPacket) <= 0)
			{
				std::cout << "closing client " << std::endl;
				deleteClient(it, (*it));
				if (it == _clientList.end())
					return;
			}
			else
				parser((*it));
		}
	}
}

bool Server::acceptClient()
{
	SOCKET			sock;

	if ((sock = _network->acceptNewClient()) != INVALID_SOCKET)
	{
		std::cout << "new client accepted" << std::endl;
		_clientList.push_back(new ClientInfo(sock));
		return true;
	}
	return false;
}

void Server::parser(ClientInfo * client)
{
	int i = _cPacket->command;
	std::cout << DESCRIBE_GAME << "  " << _cPacket->command << std::endl;
	if (_cPacket->command == DESCRIBE_GAME)
		describeGame(client);
	else if (_cPacket->command == CREATE_GAME)
		createGame(client);
	else
		std::cout << "no match..." << std::endl;
}

void Server::deleteClient(std::vector<ClientInfo*>::iterator& it, ClientInfo* client)
{
	std::cout << "client deleted" << std::endl;
	_network->closeConnection(client->getSocket());
	delete (client);
	it = _clientList.erase(std::find(_clientList.begin(), _clientList.end(), client));
}

void Server::wipePacket()
{
	memset(_cPacket, 0, sizeof(*_cPacket));
}

void Server::fillPacket(ClientCommand command, std::string const& data)
{
	wipePacket();
	_cPacket->command = command;
	// strncpy_s(_cPacket->data, data.c_str(), data.size());
}

bool Server::describeGame(ClientInfo * client)
{
	std::cout << "inside describe " << std::endl;

	std::string msg = "";
	for (std::vector<Game*>::iterator it = _gameList.begin(); it != _gameList.end(); ++it)
	{
		msg += (*it)->getName() + "  ";
	}
	fillPacket(DESCRIBE_GAME, msg);
	_network->sendToClient(client->getSocket(), _cPacket);
	return true;
}

bool Server::createGame(ClientInfo * client)
{
	_gameList.push_back(new Game(_cPacket->data));
	std::cout << "list size : " << _gameList.size() << std::endl;
	fillPacket(DESCRIBE_GAME, std::string("lalalalla"));
	_network->sendToClient(client->getSocket(), _cPacket);
	return true;
}
