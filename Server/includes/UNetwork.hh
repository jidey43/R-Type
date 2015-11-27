#ifndef UNETWORK_H_
# define UNETWORK_H_

# ifdef __linux__

# include "INetwork.hh"
#include "TCPSocket.h"
#include "UDPSocket.h"


template <class T>
class UNetwork : public INetwork<T>
{
private:
	T*							_socket;
	SOCKET						_listen;
	struct addrinfo*			_addr;
	fd_set*						_readSet;

public:
	UNetwork();
	~UNetwork();

public:
  bool					initServerSocket(std::string const &, std::string const &);
  SOCKET					acceptSocket();

  // template <typename TCPSocket>
  TransmitStatus			recvData(SOCKET, void *data, int size);
  // template <typename TCPSocket>
  TransmitStatus			sendData(SOCKET, void *data, int size);

  // template <typename UDPSocket>
  TransmitStatus			recvData(void *data, int size, ConnectionData *addr);
  // template <typename UDPSocket>
  TransmitStatus			sendData(void *data, int size, ConnectionData *addr);

  SOCKET					getFd() const;
  void					selectClients(std::vector<int>& fd, struct timeval *to);
  bool					closeConnection(SOCKET);
};

# include "UNetwork.tpp"

# endif

#endif
