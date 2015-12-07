#include <stdio.h>
#include "TCPSocket.hh"

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
    printf("getaddrinfo failed: %d\n", result);
    return INVALID_SOCKET;
  }

  SOCKET Thatsocket = INVALID_SOCKET;
  if ((Thatsocket = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol)) == -1)
    printf("socket failed with error\n");
  if (bind(Thatsocket, addr->ai_addr, (int)addr->ai_addrlen) == SOCKET_ERROR)
    {
      printf("bind failed with error\n");
      freeaddrinfo(addr);
      return INVALID_SOCKET;
    }
  if (listen(Thatsocket, SOMAXCONN) == SOCKET_ERROR)
    printf("Listen failed with error\n");
  _listen = Thatsocket;
  std::cout << "listening on " << _listen << std::endl;
  return _listen;
}

SOCKET	TCPSocket::acceptClient()
{
	SOCKET socket = INVALID_SOCKET;

	if ((socket = accept(_listen, NULL, NULL)) == INVALID_SOCKET)
	  std::cerr << "accept failed" << std::endl;
	return socket;
}

TransmitStatus	TCPSocket::sendData(const void *buffer, int size, SOCKET socket, ConnectionData *addr)
{
	int res = send(socket, (void*)buffer, size, 0);
	if (res == -1)
	  std::cerr << "send failed" << std::endl;
	return (res == -1 ? ERR : PASSED);
}

TransmitStatus			TCPSocket::rcvData(void* buffer, int size, SOCKET socket, ConnectionData *addr)
{
	int				addr_len = sizeof(addr);
	int				res;

	res = recv(socket, (void*)buffer, size, 0);
	return (res == -1 ? ERR : (res == 0 ? DISCONNECTED : PASSED));
}
