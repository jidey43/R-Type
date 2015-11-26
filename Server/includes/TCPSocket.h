#ifndef TCPSOCKET_H_
# define TCPSOCKET_H_

# ifdef _WIN32

# include "NetworkDefines.h"
# include "INetwork.h"

# pragma comment(lib, "ws2_32.lib")

class							TCPSocket
{
private:
	std::string					_ip;
	std::string					_port;
	int							_listen;

public:
	TCPSocket();
	~TCPSocket();

	int							startNetwork(std::string const &ip, std::string const &port, addrinfo);
	SOCKET						acceptClient();
	TransmitStatus				sendData(const void *buffer, int size, SOCKET socket);
	TransmitStatus				rcvData(SOCKET socket, void* buffer, int size);
};

#endif

#endif

