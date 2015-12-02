#ifndef CLIENT_H_
# define CLIENT_H_

# include <vector>
# include "NetworkHandler.h"

class Client
{
public:
	Client(std::string const& ip, std::string const& port);
	~Client();

private:
	NetworkHandler*				_network;
	ClientPacket*				_packet;
	SOCKET						_listen;

public:
	void						start();
	void						wipePacket();
	void						fillPacket(ClientCommand command, std::string& data);
};

#endif