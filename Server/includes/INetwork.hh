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

template <class T>
class									INetwork
{
public:
  virtual bool					initServerSocket(std::string const &ip, std::string const &port) = 0;
  virtual SOCKET				acceptSocket() = 0;
  virtual void					recvData(void *data, int, SOCKET, ClientDatas *addr) = 0;
  virtual void					sendData(void *data, int size, SOCKET, ClientDatas *addr) = 0;
  virtual SOCKET				getFd() const = 0;
  virtual void					selectClients(std::vector<SOCKET>& fd, struct timeval *to) = 0;
  virtual bool					closeConnection(SOCKET) = 0;
};

template <typename T>
INetwork<T>*								getNetworkInstance();

#endif
