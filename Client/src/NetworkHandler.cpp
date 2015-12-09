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
  _activeFD.clear();
  _activeFD.push_back(_listen);
  _network->selectFD(_activeFD, NULL);
  return true;
}

bool	 NetworkHandler::getActiveClient()
{
  if (_activeFD.size() < 1)
    return false;
  return true;
}

// void	NetworkHandler::broadcast(IClientPacket* packet)
// {
//   for (std::vector<ClientInfo*>::iterator it = _clientList.begin(); it != _clientList.end(); ++it)
//     {
//       sendToClient((*it), packet);
//     }
// }

IServerPacket<ServerTCPResponse>*	NetworkHandler::receiveFromServer(SOCKET sock)
{
  ServerTCPHeader*	header = new ServerTCPHeader;
  std::string		tmp;
  char*			buff;
  IServerPacket<ServerTCPResponse>*	packet;

  tryReceive(header, sizeof(ServerTCPHeader), sock);
  packet = _factory->build(header);
  if (!packet->checkHeader())
    return NULL;
  buff = new char[header->size + 1];
  tryReceive(buff, header->size, sock);
  buff[header->size] = 0;
  tmp = std::string(buff);
  packet->setRawData(tmp);
  return packet;
}

bool			NetworkHandler::tryReceive(ServerTCPHeader* header, size_t size, SOCKET sock)
{
  try
    {
        _network->recvData(header, sizeof(ServerTCPHeader), client, NULL);
    }
  catch (Exceptions::NetworkExcept e)
    {
      std::cerr << e.what() << std::endl;
      closeConnection();
      return false;
    }
  catch (Exceptions::ConnectionExcept e)
    {
      std::cerr << e.what() << std::endl;
      closeConnection();
      return false;
    }
  return true;
}

bool			NetworkHandler::sendToServer(SOCKET client, IServerPacket* packet)
{
  std::string	toSend = packet->deserialize();

  try
    {
      _network->sendData((void*)toSend.c_str(), toSend.size(), client, NULL);
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
