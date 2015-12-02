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

bool NetworkHandler::initSocket()
{
	if (_network->initClientSocket(_ip, _port))
	{
		_listen = _network->getFd();
		return true;
	}
	return false;
}
/*
bool NetworkHandler::selectSockets()
{
	std::vector<SOCKET>	fdList;

	fdList.push_back(_listen);
	for (std::vector<ClientInfo*>::iterator it = _clientList.begin(); it != _clientList.end(); ++it)
		fdList.push_back((*it)->getSocket());
	_network->selectFD(fdList, NULL);
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
*/
void	NetworkHandler::broadcast(char* msg)
{
	for (std::vector<ClientInfo*>::iterator it = _clientList.begin(); it != _clientList.end(); ++it)
	{/*
		_network->sendData((*it)->getSocket(), msg, sizeof(msg));*/
	}
}

TransmitStatus NetworkHandler::receiveFromServer()
{
	TransmitStatus ret;
	char	buffer[BUFF_LEN];

	/*
	while (std::string(buffer).find("\r\n", 0) == std::string::npos)
	{*/
	memset(buffer, 0, BUFF_LEN);
	ret = _network->recvData(buffer, BUFF_LEN, _listen, NULL);
	//								}
	_packet = std::string(buffer);
	_packet = _packet.substr(0, _packet.find("\n", 0));
	return ret;
}

bool NetworkHandler::sendToServer(std::string const& data)
{
	int		size = ((data.size() / BUFF_LEN) + 1) * BUFF_LEN;
	char *buff = new char(size);

	memset(buff, 0, size);
	memcpy(buff, data.c_str(), data.size());
	std::cout << "before send :: " << data << "END" << std::endl;
	_network->sendData(buff, size, _listen, NULL);
	return (true);
}

void NetworkHandler::closeConnection()
{
	_network->closeConnection(_listen);
}

std::string NetworkHandler::getPacket() const
{
	return _packet;
}
