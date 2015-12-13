#include <iostream>
#include "Server.hh"
#include "NetworkDefines.h"
#include "SWNetwork.hh"
#include "NewGamePacket.h"
#include "JoinPacket.hh"
#include "GameListPacket.h"
#include "DesGamePacket.h"
#include "GameListPacket.h"
#include "AuthTCPPacket.h"
#include "GameInfoPacket.h"
#include "GameOverPacket.h"
#include "FailPacket.h"
#include "IServerPacket.hh"

Server::Server(std::string const & ip, std::string const & port)
 : _network(new NetworkHandler(ip, port)),
	  _games(new GameHandler(ip))
{
  if (_network->initSocket())
    {
      start();
    }
}

Server::~Server()
{
  delete _games;
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
      // std::cout << "--> client [" << client->getNickname() << "]" << std::endl;
      parser(client);
    }
}

void Server::parser(ClientInfo * client)
{
  if (client->isInGame())
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
      case AUTH_TCP:
	{
	  setNick(client);
	  break;
	}
      case REQ_GAME:
	{
	  describeGame(client);
	  break;
	}
      default:
	{
	  std::cout << "no match..." << std::endl;
	  break;
	}
      }
  else
    _network->sendToClient(client, new FailPacket(FAIL));
}

bool Server::describeGame(ClientInfo * client)
{
  if (_network->sendToClient(client, new GameListPacket(START_GAME_LIST)))
    return false;
  for (std::vector<GameInfo*>::iterator it = _games->getGameList().begin(); it != _games->getGameList().end(); ++it)
    {
      if (_network->sendToClient(client, new DesGamePacket(DES_GAME, (*it)->getID(), (*it)->getName(), (*it)->getClients())))
	return false;
    }
  _network->sendToClient(client, new GameListPacket(END_GAME_LIST));
  return true;
}

bool Server::createGame(ClientInfo * client)
{
  int		id;

  if (client->isInGame() || (id = _games->startNewGame(dynamic_cast<NewGamePacket*>(client->getPacket())->getData()->data)) == -1)
    {
      _network->sendToClient(client, new FailPacket(FAIL));
    }
  else
    {
      joinGame(client, id);
    }
  return true;
}

bool	Server::joinGame(ClientInfo* client)
{
  GameInfo*	game;

  if ((game = _games->addClientInGame(client, dynamic_cast<JoinPacket*>(client->getPacket())->getData()->id)) != NULL)
    _network->sendToClient(client, new GameInfoPacket(GAME_INFO, game->getID(), game->getPort()));
  else
    _network->sendToClient(client, new FailPacket(FAIL));
  return true;
}

bool	Server::joinGame(ClientInfo* client, int id)
{
  GameInfo*	game;

  if ((game = _games->addClientInGame(client, id)) != NULL)
    _network->sendToClient(client, new GameInfoPacket(GAME_INFO, game->getID(), game->getPort()));
  else
    _network->sendToClient(client, new FailPacket(FAIL));
  return true;
}

bool	Server::setNick(ClientInfo* client)
{
  client->setNickname(dynamic_cast<NickPacket*>(client->getPacket())->getData()->data);
  _network->sendToClient(client, new AuthTCPPacket(AUTH, SUCCESS));
  return true;
}
