#ifndef UDPSOCKET_H_
# define UDPSOCKET_H_

# include "NetworkDefines.h"
# include "INetwork.hh"
# include "Exceptions.hpp"

class			UDPSocket
{
private:
  SOCKET		_listen;
  std::string		_port;

public:
  UDPSocket();
  ~UDPSocket();

  int			startNetwork(std::string const &ip, std::string const &port, ConnectionData*);
  void			sendData(const void *buffer, int size, SOCKET sock, ClientDatas *addr);
  void			rcvData(void* buffer, int size, SOCKET sock, ClientDatas *addr);
  SOCKET		acceptClient();
};

#endif
