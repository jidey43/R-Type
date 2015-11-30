#ifndef NETWORKHANDLER_H_
# define NETWORKHANDLER_H_

# include <string>
# include <vector>
# include "TCPSocket.h"
# include "UDPSocket.h"
# include "NetworkDefines.h"
# include "INetwork.hh"
# include "UNetwork.hh"
# include "WNetwork.hh"
# include "ClientInfo.h"

template class				INetwork<TCPSocket>;

class NetworkHandler
{
public:
	NetworkHandler(std::string const& ip, std::string const& port);
	~NetworkHandler();

private:
	std::string					_ip;
	std::string					_port;
	INetwork<TCPSocket>*		_network;
	std::vector<ClientInfo*>	_clientList;
	std::vector<ClientInfo*>	_activeClients;
	std::string					_packet;
	SOCKET						_listen;

public:
	bool						initSocket();
	bool						acceptNewClient();
	bool						selectClient();
	ClientInfo*					getActiveClient();
	void						broadcast(char* msg);
	bool						sendToClient(ClientInfo* client, std::string const& data);
	TransmitStatus				receiveFromClient(ClientInfo* client);
	TransmitStatus				receiveFromClient(SOCKET client);
	void						closeConnection(ClientInfo* client);
};

#endif