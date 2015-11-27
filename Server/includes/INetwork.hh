#ifndef INETWORK_H_
# define INETWORK_H_

# include <vector>
# include "NetworkDefines.h"

typedef enum	e_TransmitStatus
{
	ERR = -1,
	DISCONNECTED = 0,
	PASSED = 1,
}				TransmitStatus;

template <class T> class									INetwork
{
public:
	virtual bool					initServerSocket(std::string const &ip, std::string const &port) = 0;
	virtual SOCKET					acceptSocket() = 0;
	virtual TransmitStatus			recvData(SOCKET, void *data, int size) = 0;
	virtual TransmitStatus			sendData(SOCKET, void *data, int size) = 0;
	virtual TransmitStatus			recvData(void *data, int size, ConnectionData *addr) = 0;
	virtual TransmitStatus			sendData(void *data, int size, ConnectionData *addr) = 0;
	virtual SOCKET					getFd() const = 0;
	virtual void					selectClients(std::vector<int>& fd, struct timeval *to) = 0;
	virtual bool					closeConnection(SOCKET) = 0;
};

template <class T>
INetwork<T>*								getNetworkInstance();

#endif
