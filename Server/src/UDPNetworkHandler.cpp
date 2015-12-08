#include "UDPNetworkHandler.hh"
#include "PacketFactory.hh"

UDPNetworkHandler::UDPNetworkHandler(std::string const& ip, std::string const& port)
  : _ip(ip),
    _port(port),
    _network(getNetworkInstance<UDPSocket>()),
    _factory(new PacketFactory())
{
}

UDPNetworkHandler::~UDPNetworkHandler()
{
  std::vector<ClientInfo*>::iterator it;

  for (it = _activeClients.begin(); it != _activeClients.end(); ++it)
    {
      delete (*it);
    }
  delete _network;
  delete _factory;
}

bool		UDPNetworkHandler::initSocket()
{
  if (_network->initServerSocket(_ip, _port))
    {
      _socket = _network->getFd();
      return true;
    }
  return false;
}

bool			UDPNetworkHandler::selectClient()
{
  std::vector<int>	fdList;
  ConnectionData	clientDatas;
  HeaderServerUDP*	header = new HeaderServerUDP();

  fdList.push_back(_socket);
  _network->selectClients(fdList, NULL);
  if (!fdList.empty())
    {
      _network->recvData(header, sizeof(HeaderServerUDP), _socket, &clientDatas);
    }
}
