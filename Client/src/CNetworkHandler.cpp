#include <iostream>
#include "CNetworkHandler.hh"

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

IServerPacket<ServerTCPResponse>*	NetworkHandler::receiveFromServer()
{
  ServerTCPHeader*			header = new ServerTCPHeader;
  std::string				tmp;
  char*					buff;
  IServerPacket<ServerTCPResponse>*	packet;

  memset(header, 0, sizeof(ServerTCPHeader));
  tryReceive((char*)header, sizeof(ServerTCPHeader));
  packet = _factory->build(header);
  if (!packet->checkHeader())
    return NULL;
  buff = new char[header->size + 1];
  memset(buff, 0, header->size + 1);
  tryReceive(buff, header->size);
  tmp = std::string(buff);
  packet->setRawData(tmp);
  return packet;
}

bool			NetworkHandler::tryReceive(char* header, int size)
{
  try
    {
        _network->recvData(header, sizeof(ServerTCPHeader), _listen, NULL);
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

bool			NetworkHandler::sendToServer(IClientPacket<ClientTCPCommand>* packet)
{
  std::string	toSend = packet->deserialize();

  try
    {
      _network->sendData((void*)toSend.c_str(), toSend.size(), _listen, NULL);
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

void NetworkHandler::closeConnection()
{
	_network->closeConnection(_listen);
}

std::string NetworkHandler::getPacket() const
{
	return _packet;
}
