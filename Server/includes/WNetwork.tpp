#ifdef _WIN32

#include <string>
#include <iostream>
#include <tchar.h>
#include <stdio.h>
#include <strsafe.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS

template <typename T>
WNetwork<T>::WNetwork()
	: _socket(new T()), _readSet(new fd_set)
{
}

template <typename T>
WNetwork<T>::~WNetwork()
{
	delete _socket;
}

template <typename T>
bool WNetwork<T>::initServerSocket(std::string const &ip, std::string const &port)
{
	WSADATA wsaData;
	addrinfo hints;

	int result;
	result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (result != 0)
	{
		printf("WSAStartup failed: %d\n", result);
		return false;
	}
	ZeroMemory(&hints, sizeof(hints));
	if (_listen = _socket->startNetwork(ip, port, hints) == INVALID_SOCKET)
	{
		WSACleanup();
		return false;
	}
	return true;
}

template <typename T>
void		WNetwork<T>::selectClients(std::vector<int>& fd, struct timeval *to)
{
	std::vector<int> buffer;
	FD_ZERO(_readSet);
	for (std::vector<int>::iterator it = fd.begin(); it: = fd.end(); ++it)
		FD_SET((*it), _readSet);
	if (select(_listen + 1, _readSet, NULL, NULL, &to) < 0) {
		perror("select error");
	}
	for (std::vector<int>::iterator it = fd.begin(); it: = fd.end(); ++it)
	{
		if (FD_ISSET((*it), _readSet))
			buffer.push_back((*it));
	}
	fd.clear();
	fd = buffer;
}

template <typename T>
SOCKET WNetwork<T>::acceptSocket()
{
	SOCKET accept = _socket->acceptClient(_listen);
	if (accept == INVALID_SOCKET)
	{
		WSACleanup();
		closeConnection(_listen);
	}
	return accept;
}

template <typename T>
TransmitStatus WNetwork<T>::recvData(void *data, int size, ConnectionData *addr)
{
	return _socket->rcvData(data, size, addr);
}

template <typename T>
TransmitStatus WNetwork<T>::recvData(SOCKET sock, void *data, int size)
{
	return _socket->rcvData(sock, data, size);
}

template <typename T>
TransmitStatus WNetwork<T>::sendData(void *data, int size, ConnectionData *addr)
{
	return _socket->sendData(data, size, addr);
}

template <typename T>
TransmitStatus WNetwork<T>::sendData(SOCKET sock, void *data, int size)
{
	return _socket->sendData(data, size, sock);
}

template <typename T>
bool WNetwork<T>::closeConnection(SOCKET socket)
{
	closesocket(socket);
	return false;
}

template <typename T>
SOCKET WNetwork<T>::getFd() const
{
	return (_listen);
}

template <typename T>
INetwork*		getNetworkInstance()
{
	return new WNetwork<T>();
}

#endif
