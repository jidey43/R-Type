#ifndef UNETWORK_H_
# define UNETWORK_H_

# ifndef _WIN32

# include "INetwork.hh"

template <class T>
class UNetwork : public INetwork<T>
{
private:
  T*							_socket;
  SOCKET						_listen;
  struct addrinfo*					_addr;
  fd_set*						_readSet;

public:
  UNetwork();
  ~UNetwork();

public:
  bool					initServerSocket(std::string const &, std::string const &);
  SOCKET				acceptSocket();
  TransmitStatus			recvData(void *data, int, SOCKET, ClientDatas *addr);
  TransmitStatus			sendData(void *data, int size, SOCKET, ClientDatas *addr);
  SOCKET				getFd() const;
  void					selectClients(std::vector<SOCKET>& fd, struct timeval *to);
  bool					closeConnection(SOCKET);
};

# include "UNetwork.tpp"

# endif

#endif
