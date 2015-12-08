#ifndef SERVER_H_
# define SERVER_H_

# include <vector>
# include "GameInfo.h"
# include "NetworkHandler.h"
# include "GameHandler.h"

class		Server
{
 public:
  Server(std::string const& ip, std::string const& port);
  ~Server();

 private:
  NetworkHandler*			_network;
  GameHandler*				_games;
  IServerPacket*			_packet;

 private:
  void					start();
  void					answerClients();
  void					parser(ClientInfo* client);
  bool					describeGame(ClientInfo* client);
  bool					createGame(ClientInfo* client);
  bool					joinGame(ClientInfo* client);
  bool					joinGame(ClientInfo* client, int id);
};

#endif
