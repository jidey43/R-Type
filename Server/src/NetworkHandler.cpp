#include <iostream>
#include "NetworkHandler.h"

NetworkHandler::NetworkHandler(std::string const & ip, std::string const & port)
	: _ip(ip), _port(port), _network(getNetworkInstance<TCPSocket>())
{
}

NetworkHandler::~NetworkHandler()
{
	delete _network;
}

SOCKET NetworkHandler::initSocket()
{
	if (_network->initServerSocket(_ip, _port))
	{
		_listen = _network->getFd();
		return _listen;
	}
	return INVALID_SOCKET;
}

SOCKET NetworkHandler::acceptNewClient()
{
	return _network->acceptSocket();
}

void NetworkHandler::selectClient(std::vector<ClientInfo*>& clientList)
{
}

bool		NetworkHandler::isClientSet(SOCKET sock)
{
}

void	NetworkHandler::broadcast(std::vector<ClientInfo*>& clientList, char* msg)
{
	for (std::vector<ClientInfo*>::iterator it = clientList.begin(); it != clientList.end(); ++it)
	{
		_network->sendData((*it)->getSocket(), msg, sizeof(msg));
	}
}

TransmitStatus NetworkHandler::receiveFromClient(SOCKET sock, ClientPacket *data)
{
	return (_network->recvData(sock, data, sizeof(*data)));
}

TransmitStatus NetworkHandler::sendToClient(SOCKET sock, ClientPacket *data)
{
	return (_network->sendData(sock, data, sizeof(*data)));
}

void NetworkHandler::closeConnection(SOCKET sock)
{
	_network->closeConnection(sock);
}
