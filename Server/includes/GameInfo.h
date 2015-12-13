#ifndef GAMEINFO_H_
# define GAMEINFO_H_

# include <string>
# include <vector>
# include "ClientInfo.h"

class GameInfo
{
 public:
  GameInfo(std::string const& name, int id, int port);
  ~GameInfo();

 private:
  std::string	       		_name;
  int				_id;
  int				_port;
  std::vector<ClientInfo*>	_clients;


 public:
  std::string const&		getName() const;
  int				getID() const;
  int				getPort() const;
  int				getPlayerNb() const;
  bool				addClient(ClientInfo* client);
  std::string const		getClients() const;
};

#endif
