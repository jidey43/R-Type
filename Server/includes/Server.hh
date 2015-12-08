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

 private:
  void					start();
  void					answerClients();
  void					parser(ClientInfo* client);
  void					deleteClient(std::vector<ClientInfo*>::iterator& it, ClientInfo* info);

  bool					describeGame(ClientInfo* client);
  bool					createGame(ClientInfo* client);
  bool					joinGame(ClientInfo* client);
};

#endif
