#ifdef _WIN32

#include "TCPSocket.h"

TCPSocket::TCPSocket()
{
}

TCPSocket::~TCPSocket()
{
}

int			TCPSocket::startNetwork(std::string const &ip, std::string const &port, addrinfo hints)
{
	struct addrinfo *addr = NULL;
	int result;
	hints.ai_flags = AF_INET;
	hints.ai_family = SOCK_STREAM;
	hints.ai_socktype = IPPROTO_TCP;
	hints.ai_protocol = AI_PASSIVE;
	hints.ai_addr = INADDR_ANY;
	result = getaddrinfo(ip.c_str(), port.c_str(), &hints, &addr);
	if (result != 0) {
		printf("getaddrinfo failed: %d\n", result);
		return INVALID_SOCKET;
	}

	SOCKET Thatsocket = INVALID_SOCKET;
	Thatsocket = socket(addr->ai_family, addr->ai_socktype,
		addr->ai_protocol);
	//int iResult = connect(Thatsocket, addr->ai_addr, (int)addr->ai_addrlen);
	//if (iResult == SOCKET_ERROR) {
	//	std::cout << "connect error" << std::endl;
	//	closesocket(Thatsocket);
	//	return INVALID_SOCKET;
	//}
	if (bind(Thatsocket, addr->ai_addr, (int)addr->ai_addrlen) == SOCKET_ERROR)
	{
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(addr);
		return INVALID_SOCKET;
	}

	if ((_listen = listen(Thatsocket, SOMAXCONN)) == SOCKET_ERROR)
		printf("Listen failed with error: %ld\n", WSAGetLastError());
	return _listen;
}

SOCKET	TCPSocket::acceptClient()
{
	SOCKET socket = INVALID_SOCKET;

	if ((socket = accept(_listen, NULL, NULL)) == INVALID_SOCKET)
		printf("accept failed: %d\n", WSAGetLastError());
	return socket;
}

TransmitStatus	TCPSocket::sendData(const void *buffer, int size, SOCKET socket)
{
	int res = send(socket, (char*)buffer, size, 0);
	if (res == -1)
		printf("send failed: %d\n", WSAGetLastError());
	return (res == -1 ? ERR : PASSED);
}

TransmitStatus			TCPSocket::rcvData(SOCKET socket, void* buffer, int size)
{
	int		res = recv(socket, (char*)buffer, size, 0);

	return (res == -1 ? ERR : (res == 0 ? DISCONNECTED : PASSED));
}

#endif