#include "Server.h"

#include <iostream>
#include "NetworkDefines.h"
#include "WNetwork.hh"


Server::Server(std::string const & ip, std::string const & port)
	: _network(new NetworkHandler(ip, port)), _games(new GameHandler())
{
	if (_network->initSocket())
	{
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
		_network->selectClient();
		answerClients();
	}
}

void Server::answerClients()
{
	ClientInfo*			client;

	while ((client = _network->getActiveClient()))
	{
		std::cout << "--> client [" << client->getNickname() << "] says : " << client->getPacket() << "END" << std::endl;
		parser(client);
	}
}

void Server::parser(ClientInfo * client)
{
	if (client->getPacket().find(" ", 0) != std::string::npos)
	{
		std::string command = client->getPacket().substr(0, client->getPacket().find(" ", 0));
		std::string data = client->getPacket().substr(client->getPacket().find(" ", 0) + 1, client->getPacket().find("\n", 0) - 1);

		std::cout << DESCRIBE_GAME << "  " << command << std::endl;
		if (command == "DES_GAME")
			describeGame(client);
		else if (command == "CRE_GAME")
			createGame(client, data);
		else
			std::cout << "no match..." << std::endl;
	}
	else
		std::cout << "fuck ya" << std::endl;
	//int i = _cPacket->command;
	//if (_cPacket->command == DESCRIBE_GAME)
	//	describeGame(client);
	//else if (_cPacket->command == CREATE_GAME)
	//	createGame(client);
	//else
	//	std::cout << "no match..." << std::endl;
}

void Server::deleteClient(std::vector<ClientInfo*>::iterator& it, ClientInfo* client)
{}


bool Server::describeGame(ClientInfo * client)
{
	for (std::vector<GameInfo*>::iterator it = _games->getGameList().begin(); it != _games->getGameList().end(); ++it)
		_network->sendToClient(client, (*it)->getName() + "\n");
	return true;
}

bool Server::createGame(ClientInfo * client, std::string& data)
{
	if (client->isInGame())
		return false;
	_games->startNewGame(data);
	_network->sendToClient(client, "okkkkkkk bolosse\n");
	return true;
}
