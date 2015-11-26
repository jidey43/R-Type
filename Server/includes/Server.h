#ifndef SERVER_H_
# define SERVER_H_

# include <vector>
# include "Game.h"
# include "NetworkHandler.h"

class Server
{
public:
	Server(std::string const& ip, std::string const& port);
	~Server();

private:
	std::vector<ClientInfo*>	_clientList;
	std::vector<Game*>			_gameList;
	NetworkHandler*				_network;
	ClientPacket*				_cPacket;
	SOCKET					_listen;

public:
	void						start();
	void						setClients();
	bool						acceptClient();
	void						parser(ClientInfo* client);
	void						deleteClient(std::vector<ClientInfo*>::iterator& it, ClientInfo* info);
	void						wipePacket();
	void						fillPacket(ClientCommand command, std::string const& data);

public:
	bool						describeGame(ClientInfo* client);
	bool						createGame(ClientInfo* client);
};

#endif
