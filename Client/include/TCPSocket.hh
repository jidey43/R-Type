#ifndef TCPSOCKET_H_
# define TCPSOCKET_H_

# include "NetworkDefines.h"
# include "INetwork.hh"

class					TCPSocket
{
private:
  std::string				_ip;
  std::string				_port;

public:
  TCPSocket();
  ~TCPSocket();

  SOCKET				startNetwork(std::string const &ip, std::string const &port, ConnectionData*);
  void					sendData(const void *buffer, int size, SOCKET socket, ClientDatas *addr);
  void					rcvData(void*, int size, SOCKET socket, ClientDatas *addr);
};

#endif
