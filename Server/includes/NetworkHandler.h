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
# include "PacketFactory.hh"
# include "IServerPacket.hh"

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
	IClientPacket*					_packet;
	PacketFactory*					_factory;

public:
	bool						initSocket();
	SOCKET						acceptNewClient();
	bool						selectClient();
	ClientInfo*					getActiveClient();
	void						broadcast(char *);
	void						closeConnection(ClientInfo *);

private:
	bool						sendToClient(ClientInfo *, IServerPacket *);
	TransmitStatus					receiveFromClient(ClientInfo *);
};

#endif
