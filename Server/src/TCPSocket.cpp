#include <stdio.h>
#include "TCPSocket.h"

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
	if ((_listen = listen(Thatsocket, SOMAXCONN)) == SOCKET_ERROR)
	  printf("Listen failed with error\n");
	_listen = Thatsocket;
	return _listen;
}

SOCKET	TCPSocket::acceptClient()
{
	SOCKET socket = INVALID_SOCKET;

	if ((socket = accept(_listen, NULL, NULL)) == INVALID_SOCKET)
	  printf("accept failed\n");
	return socket;
}

TransmitStatus	TCPSocket::sendData(const void *buffer, int size, SOCKET socket, ConnectionData *addr)
{
	int res = send(socket, (char*)buffer, size, 0);
	if (res == -1)
		printf("send failed\n");
	return (res == -1 ? ERR : PASSED);
}

TransmitStatus			TCPSocket::rcvData(void* buffer, int size, SOCKET socket, ConnectionData *addr)
{
	int				addr_len = sizeof(addr);
	int				res;

	res = recv(socket, (char*)buffer, BUFF_LEN, 0);
	return (res == -1 ? ERR : (res == 0 ? DISCONNECTED : PASSED));
}
