#ifndef NETWORKHANDLER_H_
# define NETWORKHANDLER_H_

# include <string>
# include <vector>
# include "TCPSocket.h"
# include "UDPSocket.h"
# include "NetworkDefines.h"
# include "INetwork.h"
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
	SOCKET						_listen;

public:
	SOCKET						initSocket();
	SOCKET						acceptNewClient();
	void						selectClient(std::vector<ClientInfo*>& list);
	bool						isClientSet(SOCKET sock);
	void						broadcast(std::vector<ClientInfo*>& clientList, char* msg);
	TransmitStatus				receiveFromClient(SOCKET sock, ClientPacket *data);
	TransmitStatus				sendToClient(SOCKET sock, ClientPacket *data);
	void						closeConnection(SOCKET sock);
};

#endif
