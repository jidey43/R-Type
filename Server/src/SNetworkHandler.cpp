#include <iostream>
#include <algorithm>
#include "SNetworkHandler.h"

SOCKET				_listen = -1;
std::vector<ClientInfo*>	_clientList;

NetworkHandler::NetworkHandler(std::string const & ip, std::string const & port)
	: _ip(ip),
	  _port(port),
	  _network(getNetworkInstance<STCPSocket>()),
	  _factory(new PacketFactory())
{
  _to.tv_usec = 100;
  _to.tv_sec = 0;
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

bool NetworkHandler::acceptNewClient()
{
  SOCKET			sock = _network->acceptSocket();
  std::string			clientName = "user_" + std::to_string(_clientList.size());

  if (sock == INVALID_SOCKET)
    return false;
  _clientList.push_back(new ClientInfo(sock, clientName));

  std::cout << "new client : " << sock << " " + _clientList.back()->getNickname() << std::endl;
  return true;
}

bool NetworkHandler::selectClient()
{
  std::vector<SOCKET>	fdList;

  fdList.push_back(_listen);
  for (std::vector<ClientInfo*>::iterator it = _clientList.begin(); it != _clientList.end(); ++it)
    fdList.push_back((*it)->getSocket());
  _network->selectClients(fdList, &_to);
  if (fdList.size() <= 0)
    return false;

  std::vector<SOCKET>::iterator fit = fdList.begin();
  SOCKET sock = INVALID_SOCKET;
  if ((*fit) == _listen && !acceptNewClient())
    return false;

  _activeClients.clear();
  std::vector<ClientInfo*>::iterator it;
  while (fit != fdList.end())
  {
      for (it = _clientList.begin(); it != _clientList.end(); ++it)
	{
	  if ((*it)->getSocket() == (*fit))
	    {
	      _activeClients.push_back((*it));
	      break;
	    }
	}
      ++fit;
    }
  return true;
}

ClientInfo*	NetworkHandler::getActiveClient()
{
  if (_activeClients.empty())
    return NULL;

  ClientInfo*	client = _activeClients.back();

  _activeClients.pop_back();
  if (receiveFromClient(client) && client->getPacket() != NULL)
    return client;
  else
    return getActiveClient();
}

void	NetworkHandler::broadcast(IServerPacket<ServerTCPResponse>* packet)
{
  for (std::vector<ClientInfo*>::iterator it = _clientList.begin(); it != _clientList.end(); ++it)
    {
      sendToClient((*it), packet);
    }
}

bool			NetworkHandler::receiveFromClient(ClientInfo* client)
{
  ClientTCPHeader*			header = new ClientTCPHeader;
  char*					buff;
  IClientPacket<ClientTCPCommand>*	packet;

  client->setPacket(NULL);
  if (!tryReceive(client, (char*)header, sizeof(ClientTCPHeader)))
    return false;
  packet = _factory->build(header);
  if (!packet || !packet->checkHeader())
    return false;
  buff = new char[header->size + 1];
  if (!tryReceive(client, (char*)buff, header->size))
    return false;
  packet->setRawData(buff);
  client->setPacket(packet);
  return true;
}

bool			NetworkHandler::tryReceive(ClientInfo* client, char* header, int size)
{
  memset(header, 0, size);
  try
    {
      _network->recvData(header, size, client->getSocket(), NULL);
    }
  catch (Exceptions::NetworkExcept e)
    {
      std::cerr << e.what() << std::endl;
      closeConnection(client);
      return false;
    }
  catch (Exceptions::ConnectionExcept e)
    {
      std::cerr << e.what() << std::endl;
      closeConnection(client);
      return false;
    }
  return true;
}

bool			NetworkHandler::sendToClient(ClientInfo* client, IServerPacket<ServerTCPResponse>* packet)
{
  char*			toSend = packet->deserialize();

  try
    {
      _network->sendData(toSend, packet->getPacketSize(), client->getSocket(), NULL);
    }
  catch (Exceptions::NetworkExcept e)
    {
      std::cerr << e.what() << std::endl;
      closeConnection(client);
      return false;
    }
  catch (Exceptions::ConnectionExcept e)
    {
      std::cerr << e.what() << std::endl;
      closeConnection(client);
      return false;
    }
  return true;
}

void	NetworkHandler::closeConnection(ClientInfo* client)
{
  _network->closeConnection(client->getSocket());
  _clientList.erase(std::find(_clientList.begin(), _clientList.end(), client));
  delete client;
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