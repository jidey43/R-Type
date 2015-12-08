#include <iostream>
#include "Server.h"

Server::Server(std::string const & ip, std::string const & port)
 : _network(new NetworkHandler(ip, port)),
	  _games(new GameHandler())
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
      std::cout << "--> client [" << client->getNickname() << "]" << std::endl;
      parser(client);
    }
}

void Server::parser(ClientInfo * client)
{
  switch (client->getPacket()->getCommandType())
    {
    case JOIN_GAME:
      {
	// joinGame(client);
	break;
      }
    case ADD_GAME:
      {
	createGame(client);
	break;
      }
    default:
      {
	std::cout << "no match..." << std::endl;
	break;
      }
    }
}

void Server::deleteClient(std::vector<ClientInfo*>::iterator& it, ClientInfo* client)
{}

bool Server::describeGame(ClientInfo * client)
{
  // for (std::vector<GameInfo*>::iterator it = _games->getGameList().begin(); it != _games->getGameList().end(); ++it)
  //   _network->sendToClient(client, (*it)->getName() + "\r\n");
  return true;
}

bool Server::createGame(ClientInfo * client)
{
  // if (client->isInGame())
  // 	return false;
  // _games->startNewGame(data);
  // _network->sendToClient(client, "okkkkkkk bolosse\r\n");
  return true;
}
