#ifndef UDPSOCKET_H_
# define UDPSOCKET_H_

# include "NetworkDefines.h"
# include "CINetwork.hh"
# include "Exceptions.hpp"

class			UDPSocket
{
private:
  int			_listen;

public:
  UDPSocket();
  ~UDPSocket();

  int			startNetwork(std::string const &ip, std::string const &port, ConnectionData*);
  void			sendData(const void *buffer, int size, SOCKET sock, ClientDatas *addr);
  void			rcvData(void* buffer, int size, SOCKET sock, ClientDatas *addr);
};

#endif
