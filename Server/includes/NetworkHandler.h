#ifndef NETWORKHANDLER_H_
# define NETWORKHANDLER_H_

# include <string>
# include <vector>
# include "TCPSocket.hh"
# include "UDPSocket.hh"
# include "NetworkDefines.h"
# include "INetwork.hh"
# include "UNetwork.hh"
# include "WNetwork.hh"
# include "ClientInfo.h"

extern	SOCKET				_listen;
extern  std::vector<ClientInfo*>	_clientList;
template class				INetwork<TCPSocket>;

class NetworkHandler
{
public:
	NetworkHandler(std::string const& ip, std::string const& port);
	~NetworkHandler();

private:
	std::string					_ip;
	std::string					_port;
	INetwork<TCPSocket>*				_network;
	std::vector<ClientInfo*>			_activeClients;
	std::string					_packet;

public:
	bool						initSocket();
	SOCKET						acceptNewClient();
	bool						selectClient();
	ClientInfo*					getActiveClient();
	void						broadcast(char* msg);
	bool						sendToClient(ClientInfo* client, std::string const& data);
	TransmitStatus					receiveFromClient(ClientInfo* client);
	TransmitStatus					receiveFromClient(SOCKET client);
	void						closeConnection(ClientInfo* client);
};

#endif
