#include "UDPNetworkHandler.hh"
#include "PacketFactory.hh"

UDPNetworkHandler::UDPNetworkHandler(std::string const& ip,
				     std::string const& port,
				     std::vector<GamerInfo*>* clients)
  : _ip(ip),
    _port(port),
    _network(getNetworkInstance<SUDPSocket>()),
    _clients(clients),
    _factory(new PacketFactory())
{
}

UDPNetworkHandler::~UDPNetworkHandler()
{
  std::vector<GamerInfo*>::iterator it;

  for (it = _clients->begin(); it != _clients->end(); ++it)
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
  for (std::vector<GamerInfo*>::iterator it = _clients->begin(); it != _clients->end(); ++it)
    {
      if (*((*it)->getClientInfos()) == *datas)
	{
	  free(datas);
	  std::cout << "CLIENT FOUND" << std::endl;
	  return *it;
	}
    }
  if (_clients->size() < 4)
    {
      GamerInfo*	newPlayer = new GamerInfo(datas);
      _clients->push_back(newPlayer);
      std::cout << "NEW CLIENT" << std::endl;
      return newPlayer;
    }
  return NULL;
}

IClientPacket<ClientUDPCommand>*	UDPNetworkHandler::receiveFrom(GamerInfo *client)
{
  char*					buff;
  IClientPacket<ClientUDPCommand>*	packet;
  ClientUDPHeader*			header;

  if ((header = client->getHeader()))
    client->setHeader(NULL);
  else
    return NULL;
  packet = _factory->build(header);
  if (!packet->checkHeader())
    throw Exceptions::BadHeaderRequest("Error, received bad Header from known client");
  buff = new char[header->size + 1];
  memset(buff, 0, header->size + 1);
  try
    {
      _network->recvData(buff, header->size, _socket, client->getClientInfos());
    }
  catch (Exceptions::NetworkExcept e)
    {
      std::cerr << e.what() << std::endl;
      return NULL;
    }
  packet->setRawData(std::string(buff));
  return packet;
}

bool					UDPNetworkHandler::sendTo(GamerInfo *client,
								  IServerPacket<ServerUDPResponse>* response)
{
  char*					buff;
  IClientPacket<ClientUDPCommand>*	packet;
  ClientUDPHeader*			header;
  std::string				toSend = response->deserialize();

  try
    {
      _network->sendData((void*)(toSend.c_str()),
			 toSend.size(),
			 _socket,
			 client->getClientInfos());
    }
  catch (Exceptions::NetworkExcept e)
    {
      std::cerr << e.what() << std::endl;
      return false;
    }
  return true;
}

GamerInfo*				UDPNetworkHandler::selectClient()
{
  std::vector<int>			fdList;
  GamerInfo*				client;

  fdList.push_back(_socket);
  _network->selectClients(fdList, NULL);
  if (!fdList.empty())
    {
      ClientDatas*	clientDatas = new ClientDatas();
      ClientUDPHeader*	header = new ClientUDPHeader();

      try
	{
	  _network->recvData(header, sizeof(*header), _socket, clientDatas);
	}
      catch (Exceptions::NetworkExcept e)
	{
	  std::cerr << e.what() << std::endl;
	  return NULL;
	}
      if ((client = this->getClient(clientDatas)))
	client->setHeader(header);
	return client;
    }
  return NULL;
}

bool		operator==(ClientDatas left, ClientDatas right)
{
  if (left.sin_family == right.sin_family
      && left.sin_port == right.sin_port
      && left.sin_addr.s_addr == right.sin_addr.s_addr)
    return true;
  return false;
}
