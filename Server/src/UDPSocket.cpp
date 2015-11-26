#ifdef _WIN32

#include "UDPSocket.h"

UDPSocket::UDPSocket()
{
}

UDPSocket::~UDPSocket()
{
}

int			UDPSocket::startNetwork(std::string const &ip, std::string const &port, addrinfo hints)
{
	struct addrinfo *addr = NULL;
	int result;
	hints.ai_flags = AF_INET;
	hints.ai_family = SOCK_DGRAM;
	hints.ai_socktype = IPPROTO_UDP;
	hints.ai_protocol = AI_PASSIVE;
	hints.ai_addr = INADDR_ANY;
	result = getaddrinfo(ip.c_str(), port.c_str(), &hints, &addr);
	if (result != 0) {
		printf("getaddrinfo failed: %d\n", result);
		return INVALID_SOCKET;
	}

	_listen = socket(addr->ai_family, addr->ai_socktype,
		addr->ai_protocol);
	return _listen;
}

TransmitStatus	UDPSocket::sendData(const void *buffer, int size, ConnectionData *addr)
{
	int res = sendto(_listen, (char*)buffer, size, 0, (sockaddr *)&addr, sizeof(addr));

	if (res == -1)
		printf("send failed: %d\n", WSAGetLastError());
	return (res == -1 ? ERR : PASSED);
}

TransmitStatus			UDPSocket::rcvData(void* buffer, int size, ConnectionData *addr)
{
	int			addr_len = sizeof(addr);
	int			res = 0;

	res = recvfrom(_listen, (char*)buffer, size, 0, (sockaddr*)&addr, &addr_len);

	return (res == -1 ? ERR : (res == 0 ? DISCONNECTED : PASSED));
}

#endif