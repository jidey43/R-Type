#ifdef __linux__

#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <unistd.h>
#include "TCPSocket.hh"
#include "UDPSocket.hh"
#include "INetwork.hh"

template <typename T>
UNetwork<T>::UNetwork()
  : _socket(new T()), _readSet(new fd_set)
{
}

template <typename T>
UNetwork<T>::~UNetwork()
{
  delete _socket;
}

template <typename T>
bool UNetwork<T>::initServerSocket(std::string const &ip, std::string const &port)
{
  addrinfo hints;

  bzero(&hints, sizeof(hints));
  if ((_listen = _socket->startNetwork(ip, port, hints)) == INVALID_SOCKET)
    return false;
  return true;
}

template <typename T>
void		UNetwork<T>::selectClients(std::vector<int>& fd, struct timeval *to)
{
  std::vector<int>	buffer;
  SOCKET			maxFd = 0;

  FD_ZERO(_readSet);
  for (std::vector<int>::iterator it = fd.begin(); it != fd.end(); ++it)
    {
      FD_SET((*it), _readSet);
      if (*it > maxFd)
	maxFd = *it;
    }
  if (select(maxFd + 1, _readSet, NULL, NULL, to) < 0) {
    perror("select error");
    std::cout << "after" << std::endl;
  }
  for (std::vector<int>::iterator it = fd.begin(); it != fd.end(); ++it)
    {
      if (FD_ISSET((*it), _readSet))
	buffer.push_back((*it));
    }
  fd.clear();
  fd = buffer;
}

template <typename T>
SOCKET UNetwork<T>::acceptSocket()
{
  SOCKET accept = _socket->acceptClient();
  if (accept == INVALID_SOCKET)
    {
      closeConnection(_listen);
    }
  return accept;
}

template <typename T>
TransmitStatus UNetwork<T>::recvData(void *data, int size, SOCKET sock, ConnectionData *addr)
{
  return _socket->rcvData(data, size, sock, addr);
}

template <typename T>
TransmitStatus UNetwork<T>::sendData(void *data, int size, SOCKET sock, ConnectionData *addr)
{
  return _socket->sendData(data, size, sock, addr);
}

template <typename T>
bool UNetwork<T>::closeConnection(SOCKET socket)
{
	close(socket);
	return true;
}

template <typename T>
SOCKET UNetwork<T>::getFd() const
{
	return (_listen);
}

template <typename T>
INetwork<T>*		getNetworkInstance()
{
	return new UNetwork<T>();
}

#endif
