#include <stdio.h>
#include <errno.h>
#include <cerrno>
#include "TCPSocket.hh"
#include "Exceptions.hpp"

TCPSocket::TCPSocket()
{
}

TCPSocket::~TCPSocket()
{
}

SOCKET			TCPSocket::startNetwork(std::string const &ip, std::string const &port, addrinfo hints)
{
  struct addrinfo *addr = NULL;
  int result;
  hints.ai_flags = AI_PASSIVE;
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;
  hints.ai_addr = INADDR_ANY;
  std::cout << ip << "   " << port << std::endl;
  result = getaddrinfo(ip.c_str(), port.c_str(), &hints, &addr);
  if (result != 0) {
    throw Exceptions::NetworkExcept("GETADDRINFO ERROR", errno);
  }

  SOCKET Thatsocket = INVALID_SOCKET;
  if ((Thatsocket = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol)) == -1)
    throw Exceptions::NetworkExcept("SOCKET ERROR", errno);
  if (bind(Thatsocket, addr->ai_addr, (int)addr->ai_addrlen) == SOCKET_ERROR)
    {
      freeaddrinfo(addr);
      throw Exceptions::NetworkExcept("BIND ERROR", errno);
    }
  if (listen(Thatsocket, SOMAXCONN) == SOCKET_ERROR)
    throw Exceptions::NetworkExcept("LISTEN ERROR", errno);
  _listen = Thatsocket;
  std::cout << "listening on " << _listen << std::endl;
  return _listen;
}

SOCKET	TCPSocket::acceptClient()
{
	SOCKET socket = INVALID_SOCKET;

	if ((socket = accept(_listen, NULL, NULL)) == INVALID_SOCKET)
	  throw Exceptions::NetworkExcept("ACCEPT FAILED", errno);
	return socket;
}

TransmitStatus	TCPSocket::sendData(const void *buffer, int size, SOCKET socket, ConnectionData *addr)
{
	int res = send(socket, (void*)buffer, size, 0);
	if (res == -1)
	  throw Exceptions::NetworkExcept("SEND FAILED", errno);
	return (res == -1 ? ERR : PASSED);
}

TransmitStatus			TCPSocket::rcvData(void* buffer, int size, SOCKET socket, ConnectionData *addr)
{
  int				addr_len = sizeof(addr);
  int				res;

  res = recv(socket, (void*)buffer, size, 0);
  if (res == -1)
    throw Exceptions::NetworkExcept("RECEIVE FAILED", errno);
  return (res == -1 ? ERR : (res == 0 ? DISCONNECTED : PASSED));
}
