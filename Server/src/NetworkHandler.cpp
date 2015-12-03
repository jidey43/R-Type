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

SOCKET NetworkHandler::acceptNewClient()
{
	SOCKET			sock = _network->acceptSocket();

	if (sock == INVALID_SOCKET)
		return INVALID_SOCKET;
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
	return sock;
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
  SOCKET sock = INVALID_SOCKET;
  if ((*fit) == _listen && (sock = acceptNewClient()) == INVALID_SOCKET)
    return false;

  _activeClients.clear();
  // if (sock != INVALID_SOCKET)
  //   _activeClients.push_back(_clientList.back());
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
  std::cout << "active clients : " << _clientList.size() << std::endl;
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

	if (_network->recvData((void*)data, BUFF_LEN, client->getSocket(), NULL) == PASSED)
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
	TransmitStatus ret;
	char	buffer[BUFF_LEN];

	/*
	while (std::string(buffer).find("\r\n", 0) == std::string::npos)
	{*/
	memset(buffer, 0, BUFF_LEN);
	ret = _network->recvData(buffer, BUFF_LEN, client->getSocket(), NULL);
	//								}
	_packet = std::string(buffer);
	_packet = _packet.substr(0, _packet.find("\n", 0));
	return ret;
}

TransmitStatus NetworkHandler::receiveFromClient(SOCKET sock)
{
	TransmitStatus ret;
	char	buffer[BUFF_LEN];

	/*
	while (std::string(buffer).find("\r\n", 0) == std::string::npos)
	{*/
	memset(buffer, 0, BUFF_LEN);
	ret = _network->recvData(buffer, BUFF_LEN, sock, NULL);
	//								}
	_packet = std::string(buffer);
	_packet = _packet.substr(0, _packet.find("\n", 0));
	return ret;
}

bool NetworkHandler::sendToClient(ClientInfo *client, std::string const& data)
{
	int		size = ((data.size() / BUFF_LEN) + 1) * BUFF_LEN;
	char *buff = new char[size];

	memset(buff, 0, size);
	memcpy(buff, data.c_str(), data.size());
	std::cout << "before send :: " << data << "END" << std::endl;
	_network->sendData(buff, size, client->getSocket(), NULL);
	return (true);
}
void NetworkHandler::closeConnection(ClientInfo* client)
{
	_network->closeConnection(client->getSocket());
	_clientList.erase(std::find(_clientList.begin(), _clientList.end(), client));
	delete client;
}
