#include <iostream>
#include "CNetworkHandler.hh"

CNetworkHandler::CNetworkHandler(std::string const & ip, std::string const & port)
	: _ip(ip),
	  _port(port),
	  _network(getNetworkInstance<CTCPSocket>()),
	  _factory(new PacketFactory())
{
}

CNetworkHandler::~CNetworkHandler()
{
  delete _network;
  delete _network;
}

bool CNetworkHandler::initSocket()
{
  if (_network->initClientSocket(_ip, _port))
    {
      _listen = _network->getFd();
      return true;
    }
  return false;
}

bool CNetworkHandler::selectSockets()
{
  _activeFD.clear();
  _activeFD.push_back(_listen);
  _network->selectFD(_activeFD, NULL);
  return true;
}

bool	 CNetworkHandler::getActiveClient()
{
  if (_activeFD.size() < 1)
    return false;
  return true;
}

// void	CNetworkHandler::broadcast(IClientPacket* packet)
// {
//   for (std::vector<ClientInfo*>::iterator it = _clientList.begin(); it != _clientList.end(); ++it)
//     {
//       sendToClient((*it), packet);
//     }
// }

IServerPacket<ServerTCPResponse>*	CNetworkHandler::receiveFromServer()
{
  ServerTCPHeader*			header = new ServerTCPHeader;
  std::string				tmp;
  char*					buff;
  IServerPacket<ServerTCPResponse>*	packet;

  memset(header, 0, sizeof(ServerTCPHeader));
  if (!tryReceive((char*)header, sizeof(ServerTCPHeader)))
    return NULL;
  packet = _factory->build(header);
  if (!packet->checkHeader())
    return NULL;
  buff = new char[header->size + 1];
  memset(buff, 0, header->size + 1);
  if (!tryReceive(buff, header->size))
    return NULL;;
  tmp = std::string(buff);
  packet->setRawData(tmp);
  return packet;
}

bool			CNetworkHandler::tryReceive(char* header, int size)
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

bool			CNetworkHandler::sendToServer(IClientPacket<ClientTCPCommand>* packet)
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

void CNetworkHandler::closeConnection()
{
	_network->closeConnection(_listen);
}

std::string CNetworkHandler::getPacket() const
{
	return _packet;
}
