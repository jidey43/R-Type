#include <algorithm>
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
  std::vector<GamerInfo*>::iterator it;

  for (it = _clients.begin(); it != _clients.end(); ++it)
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

GamerInfo*		UDPNetworkHandler::getClient(ClientDatas* datas)
{
  for (std::vector<GamerInfo*>::iterator it = _clients.begin(); it != _clients.end(); ++it)
    {
      if (*((*it)->getClientInfos()) == *datas)
	{
	  free(datas);
	  std::cout << "FIND CLIENT" << std::endl;
	  return *it;
	}
    }
  if (_clients.size() < 4)
    {
      GamerInfo*	newPlayer = new GamerInfo(datas);
      _clients.push_back(newPlayer);
      std::cout << "NEW CLIENT" << std::endl;
      return newPlayer;
    }
  return NULL;
}

bool			UDPNetworkHandler::selectClient()
{
  std::vector<int>	fdList;
  ClientDatas*		clientDatas = new ClientDatas();
  HeaderServerUDP*	header = new HeaderServerUDP();
  GamerInfo*		client;

  fdList.push_back(_socket);
  _network->selectClients(fdList, NULL);
  if (!fdList.empty())
    {
      _network->recvData(header, sizeof(HeaderServerUDP), _socket, clientDatas);
      if ((client = this->getClient(clientDatas)))
	{
	  std::cout << "TODO" << std::endl;
	}
    }
}

bool		operator==(ClientDatas left, ClientDatas right)
{
  if (left.sin_family == right.sin_family
      && left.sin_port == right.sin_port
      && left.sin_addr.s_addr == right.sin_addr.s_addr)
    return true;
  return false;
}
