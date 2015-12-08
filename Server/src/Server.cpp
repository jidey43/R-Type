#include <iostream>
#include "Server.hh"
#include "NetworkDefines.h"
#include "WNetwork.hh"
#include "NewGamePacket.h"
#include "JoinPacket.hh"
#include "GameListPacket.h"
#include "DesGamePacket.h"
#include "GameListPacket.h"
#include "AuthPacket.h"
#include "GameOverPacket.h"
#include "IServerPacket.hh"

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
	joinGame(client);
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
{
}

bool Server::describeGame(ClientInfo * client)
{
  _network->sendToClient(client, new GameListPacket(START_GAME_LIST));
  for (std::vector<GameInfo*>::iterator it = _games->getGameList().begin(); it != _games->getGameList().end(); ++it)
    {
      _network->sendToClient(client, new DesGamePacket(DES_GAME, (*it)->getID(), (*it)->getName(), (*it)->getClients()));
    }
  _network->sendToClient(client, new GameListPacket(END_GAME_LIST));
  return true;
}

bool Server::createGame(ClientInfo * client)
{
  int		id;

  if (client->isInGame() || (id = _games->startNewGame(dynamic_cast<NewGamePacket*>(client->getPacket())->getData()->data)) == -1)
    {
      _network->sendToClient(client, new FailPacket(DES_GAME));
    }
  else
    {
      joinGame(client, id);
    }
  // _network->sendToClient(client, "okkkkkkk bolosse\r\n");
  return true;
}

bool	Server::joinGame(ClientInfo* client)
{
  GameInfo*	game;

  if ((game = _games->addClientInGame(client, dynamic_cast<JoinPacket*>(client->getPacket())->getData()->id)) != NULL)
    _network->sendToClient(client, new GameInfoPacket(ADD_GAME, game->getID(), game->getPort() game->getClients()));
  else
    _network->sendToClient(client, new FailPacket(ADD_GAME));
}

bool	Server::joinGame(ClientInfo* client, int id)
{
  GameInfo*	game;

  if ((game = _games->addClientInGame(client, id)) != NULL)
    _network->sendToClient(client, new GameInfoPacket(ADD_GAME, game->getID(), game->getPort() game->getClients()));
  else
    _network->sendToClient(client, new FailPacket(ADD_GAME));}
