#ifndef UDPSOCKET_H_
# define UDPSOCKET_H_

# include "NetworkDefines.h"
# include "INetwork.hh"

class							UDPSocket
{
private:
	int							_listen;

public:
	UDPSocket();
	~UDPSocket();

	int										startNetwork(std::string const &ip, std::string const &port, addrinfo);
	TransmitStatus				sendData(const void *buffer, int size, SOCKET sock, ConnectionData *addr);
	TransmitStatus				rcvData(void* buffer, int size, SOCKET sock, ConnectionData *addr);
	//void						zeroBytes(void* buff);
};

#endif
