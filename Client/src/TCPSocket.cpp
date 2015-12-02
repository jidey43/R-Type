#include <string.h>
#include <stdio.h>
#include "TCPSocket.h"

TCPSocket::TCPSocket()
{
}

TCPSocket::~TCPSocket()
{
}

SOCKET			TCPSocket::startNetwork(std::string const &ip, std::string const &port, addrinfo *hint)
{
	struct addrinfo *addr = NULL, hints;
	memset(&hints, 0, sizeof(hints));
	int result;
	hints.ai_flags = AI_PASSIVE;
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_addr = NULL;

	result = getaddrinfo(ip.c_str(), port.c_str(), &hints, &addr);
	if (result != 0) {
		printf("getaddrinfo failed: %d\n", result);
		return INVALID_SOCKET;
	}

	SOCKET	listen;
	if ((listen = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol)) == INVALID_SOCKET)
	{
		printf("socket failed\n");
		return INVALID_SOCKET;
	}
	std::cout << "sock : " << listen << "   " << ip << "   " << port << std::endl;
	if (connect(listen, (struct sockaddr*)addr->ai_addr, (int)addr->ai_addrlen) == INVALID_SOCKET)
	{
		perror("connect");
		printf("connect failed\n");
		return INVALID_SOCKET;
	}
	return listen;
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

	res = recv(socket, (char*)buffer, size, 0);
	return (res == -1 ? ERR : (res == 0 ? DISCONNECTED : PASSED));
}
