#ifndef GAME_H_
# define GAME_H_

# include <string>
# include <vector>
# include "ClientInfo.h"

class GameInfo
{
public:
	GameInfo(std::string const& name, int port);
	~GameInfo();

private:
	std::string					_name;
	int							_port;
	std::vector<ClientInfo*>	_clients;


public:
	std::string					getName() const;
	int							getPort() const;
	bool						addClient(ClientInfo* client);
	std::vector<ClientInfo*>	getClients() const;
};

#endif