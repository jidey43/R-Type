#ifndef UDPSOCKET_H_
# define UDPSOCKET_H_

# ifdef _WIN32

# include "NetworkDefines.h"
# include "INetwork.h"

# pragma comment(lib, "ws2_32.lib")

class							UDPSocket
{
private:
	int							_listen;

public:
	UDPSocket();
	~UDPSocket();

	int							startNetwork(std::string const &ip, std::string const &port, addrinfo);
	TransmitStatus				sendData(const void *buffer, int size, ConnectionData *addr);
	TransmitStatus				rcvData(void* buffer, int size, ConnectionData *addr);
};

#endif

#endif

