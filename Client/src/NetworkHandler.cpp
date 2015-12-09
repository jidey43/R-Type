#include <iostream>
#include "NetworkHandler.hh"

NetworkHandler::NetworkHandler(std::string const & ip, std::string const & port)
	: _ip(ip),
	  _port(port),
	  _network(getNetworkInstance<TCPSocket>()),
	  _factory(new PacketFactory())
{
}

NetworkHandler::~NetworkHandler()
{
  delete _network;
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
  else
    ++fit;

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

ClientInfo * NetworkHandler::getActiveClient()
{
  if (_activeClients.size() < 1)
    return NULL;

  ClientInfo*	client = _activeClients.back();

  _activeClients.pop_back();
  try
    {
      receiveFromClient(client);
    }
  catch (Exceptions::NetworkExcept e)
    {
      std::cerr << e.what() << std::endl;
      closeConnection(client);
      return getActiveClient();
    }
  catch (Exceptions::ConnectionExcept e)
    {
      std::cerr << e.what() << std::endl;
      closeConnection(client);
      return getActiveClient();
    }
  return client;
}

void	NetworkHandler::broadcast(IClientPacket* packet)
{
  for (std::vector<ClientInfo*>::iterator it = _clientList.begin(); it != _clientList.end(); ++it)
    {
      sendToClient((*it), packet);
    }
}

void			NetworkHandler::receiveFromServer(ClientInfo* client)
{
  ServerTCPHeader*	header = new ServerTCPHeader;
  std::string		tmp;
  char*			buff;
  IServerPacket*	packet;

  client->setPacket(NULL);
  _network->recvData(header, sizeof(ServerTCPHeader), client->getSocket(), NULL);
  packet = _factory->build(header);
  if (!packet->checkHeader())
    return ;
  buff = new char[header->size + 1];
  _network->recvData(buff, header->size, client->getSocket(), NULL);
  buff[header->size] = 0;
  tmp = std::string(buff);
  packet->setRawData(tmp);
  client->setPacket(packet);
}

bool			NetworkHandler::sendToServer(ClientInfo* client, IServerPacket* packet)
{
  std::string	toSend = packet->deserialize();

  try
    {
      _network->sendData((void*)toSend.c_str(), toSend.size(), client->getSocket(), NULL);
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

void NetworkHandler::closeConnection()
{
	_network->closeConnection(_listen);
}

std::string NetworkHandler::getPacket() const
{
	return _packet;
}
