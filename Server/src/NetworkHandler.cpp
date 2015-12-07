#include <iostream>
#include <algorithm>
#include "NetworkHandler.h"
#include "IPacket.h"

SOCKET				_listen = -1;
std::vector<ClientInfo*>	_clientList;

NetworkHandler::NetworkHandler(std::string const & ip, std::string const & port)
	: _ip(ip),
	  _port(port),
	  _network(getNetworkInstance<TCPSocket>()),
	  _packet(NULL),
	  _factory(new PacketFactory())
{
}

NetworkHandler::~NetworkHandler()
{
  delete _network;
  delete _factory;
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
  std::string			clientName = "user_" + std::to_string(_clientList.size());

  if (sock == INVALID_SOCKET)
    return INVALID_SOCKET;
  _clientList.push_back(new ClientInfo(sock, clientName));
  std::cout << "new client : " << sock << " " + clientName << std::endl;
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

ClientInfo*	NetworkHandler::getActiveClient()
{
  if (_activeClients.empty())
    return NULL;

  TransmitStatus ret;
  ClientInfo*	client = _activeClients.back();
  _activeClients.pop_back();

  ret = receiveFromClient(client);

  if (ret == DISCONNECTED || ret == ERR)
    closeConnection(client);
  else
    return client;
  return NULL;
}

void	NetworkHandler::broadcast(char* msg)
{
	for (std::vector<ClientInfo*>::iterator it = _clientList.begin(); it != _clientList.end(); ++it)
	{/*
		_network->sendData((*it)->getSocket(), msg, sizeof(msg));*/
	}
}

/*
** For text Protocol
*/

// TransmitStatus NetworkHandler::receiveFromClient(ClientInfo* client)
// {
//   TransmitStatus	ret;
//   char			buffer[BUFF_LEN];
//   std::string		entry = client->getRemainPacket();
//   size_t		pos;

//   client->setRemainPacket("");
//   memset(buffer, 0, BUFF_LEN);
//   ret = _network->recvData(buffer, BUFF_LEN, client->getSocket(), NULL);
//   entry += std::string(buffer);
//   while ((pos = entry.rfind("\r\n")) == std::string::npos)
//     {
//       _packet += entry;
//       memset(buffer, 0, BUFF_LEN);
//       ret = _network->recvData(buffer, BUFF_LEN, client->getSocket(), NULL);
//       entry = std::string(buffer);
//     }
//   client->setRemainPacket(entry.substr(pos + 1, entry.size()));
//   _packet += entry.substr(0, pos);
//   return PASSED;
// }

// TransmitStatus NetworkHandler::receiveFromClient(SOCKET sock)
// {
//   TransmitStatus	ret;
//   char			buffer[BUFF_LEN];
//   std::string		entry;
//   size_t		pos;

//   memset(buffer, 0, BUFF_LEN);
//   ret = _network->recvData(buffer, BUFF_LEN, sock, NULL);
//   entry += std::string(buffer);
//   while ((pos = entry.rfind("\r\n")) == std::string::npos)
//     {
//       _packet += entry;
//       memset(buffer, 0, BUFF_LEN);
//       ret = _network->recvData(buffer, BUFF_LEN, sock, NULL);
//       entry = std::string(buffer);
//     }
//   _packet += entry.substr(0, pos);
//   return PASSED;
// }

// bool	NetworkHandler::sendToClient(ClientInfo *client, std::string const& data)
// {
//   int	size = ((data.size() / BUFF_LEN) + 1) * BUFF_LEN;
//   char	*buff = new char[size];

//   memset(buff, 0, size);
//   memcpy(buff, data.c_str(), data.size());
//   std::cout << "before send :: " << size << "END" << std::endl;
//   _network->sendData(buff, size, client->getSocket(), NULL);
//   return (true);
// }

TransmitStatus		NetworkHandler::receiveFromClient(ClientInfo* client)
{
  TransmitStatus	ret;
  HeaderNetwork*	header = new HeaderNetwork;
  std::string		tmp;
  char*			buff = new char[sizeof(HeaderNetwork) + 5];
  IPacket*		packet;

  if ((ret = _network->recvData(buff, sizeof(HeaderNetwork) + 4, client->getSocket(), NULL)) == PASSED)
    {
      buff[sizeof(HeaderNetwork) + 4] = 0;
      tmp = std::string(buff);

      int *nb = (int*)(tmp.substr(tmp.size() - 4, tmp.size()).c_str());
      if (*nb != MAGIC)
	return ERR;
      memcpy(header, (tmp.substr(0, sizeof(HeaderNetwork)).c_str()), sizeof(HeaderNetwork));
    }
  delete (buff);
  buff = new char[header->size + 5];
  if ((ret = _network->recvData(buff, header->size + 4, client->getSocket(), NULL)) == PASSED)
    {
      buff[header->size + 4] = 0;
      tmp = std::string(buff);

      int *nb = (int*)(tmp.substr(tmp.size() - 4, tmp.size()).c_str());
      if (*nb != MAGIC)
	return ERR;
      tmp = tmp.substr(0, tmp.size() - 5);
    }
  client->setPacket(_factory->build(header->command, tmp));
  return ret;
}

bool		NetworkHandler::sendToClient(ClientInfo* client, IPacket* packet)
{

}

void	NetworkHandler::closeConnection(ClientInfo* client)
{
  _network->closeConnection(client->getSocket());
  _clientList.erase(std::find(_clientList.begin(), _clientList.end(), client));
  delete client;
}
