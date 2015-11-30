#include <iostream>
#include <algorithm>
#include "NetworkHandler.h"

NetworkHandler::NetworkHandler(std::string const & ip, std::string const & port)
	: _ip(ip), _port(port), _network(getNetworkInstance<TCPSocket>())
{
}

NetworkHandler::~NetworkHandler()
{
	delete _network;
}

bool NetworkHandler::initSocket()
{
	if (_network->initServerSocket(_ip, _port))
	{
		_listen = _network->getFd();
		return true;
	}
	return false;
}

bool NetworkHandler::acceptNewClient()
{
	SOCKET			sock = _network->acceptSocket();

	if (sock == INVALID_SOCKET)
		return false;
	receiveFromClient(sock);
	if (_packet != "")
	{
		_clientList.push_back(new ClientInfo(sock, _packet));
		std::cout << "new client : " << sock << std::endl;
	}
	else
	{
		std::cout << "nick not received" << std::endl;
	}
	return true;
}

bool NetworkHandler::selectClient()
{
	std::vector<SOCKET>	fdList;

	fdList.push_back(_listen);
	for (std::vector<ClientInfo*>::iterator it = _clientList.begin(); it != _clientList.end(); ++it)
		fdList.push_back((*it)->getSocket());
	_network->selectClients(fdList, NULL);
	if (fdList.size() <= 0)
		return false;
	std::vector<SOCKET>::iterator fit = fdList.begin();
	if ((*fit) == _listen && !acceptNewClient())
		return false;

	_activeClients.clear();
	std::vector<ClientInfo*>::iterator it = _clientList.begin();
	for (fit; fit != fdList.end(); ++fit)
	{
		for (it; it != _clientList.end(); ++it)
		{
			if ((*it)->getSocket() == (*fit))
			{
				_activeClients.push_back((*it));
				break;
			}
		}
	}
	return true;
}

ClientInfo * NetworkHandler::getActiveClient()
{
	if (_activeClients.size() < 1)
		return NULL;

	ClientInfo*	client = _activeClients.back();
	_activeClients.pop_back();

	client->setPacket("");
	char	data[BUFF_LEN];

	if (_network->recvData(data, client->getSocket(), NULL) == PASSED)
	{
		client->setPacket(std::string(data));
		return client;
	}
	return NULL;
}

void	NetworkHandler::broadcast(char* msg)
{
	for (std::vector<ClientInfo*>::iterator it = _clientList.begin(); it != _clientList.end(); ++it)
	{/*
		_network->sendData((*it)->getSocket(), msg, sizeof(msg));*/
	}
}

TransmitStatus NetworkHandler::receiveFromClient(ClientInfo* client)
{
	char	buffer[256];

	*buffer = 0;/*
				while (std::string(buffer).find("\r\n", 0) == std::string::npos)
				{*/
	if (_network->recvData(buffer, client->getSocket(), NULL) == PASSED)
		closeConnection(client);/*
								}*/
	_packet = std::string(buffer);
	_packet = _packet.substr(0, 4 - 1);
}

TransmitStatus NetworkHandler::receiveFromClient(SOCKET sock)
{
	TransmitStatus ret;
	char	buffer[256];

	*buffer = 0;/*
				while (std::string(buffer).find("\r\n", 0) == std::string::npos)
				{*/
	ret = _network->recvData(buffer, sock, NULL);
//								}
	_packet = std::string(buffer);
	_packet = _packet.substr(0, 4 - 1);
	return ret;
}

bool NetworkHandler::sendToClient(ClientInfo *client, std::string const& data)
{
	std::cout << "before send :: " << data << "END" << std::endl;
	_network->sendData((void*)data.c_str(), data.size(), client->getSocket(), NULL);
	return (true);
}

void NetworkHandler::closeConnection(ClientInfo* client)
{
	_network->closeConnection(client->getSocket());
	_clientList.erase(std::find(_clientList.begin(), _clientList.end(), client));
	delete client;
}
