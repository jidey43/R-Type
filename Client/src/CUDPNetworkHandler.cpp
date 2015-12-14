#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "CUDPNetworkHandler.hh"
#include "PacketFactory.hh"

CUDPNetworkHandler::CUDPNetworkHandler(std::string const& ip,
				       std::string const& port)
  : _ip(ip),
    _port(port),
    _network(getNetworkInstance<CUDPSocket>()),
    _factory(new PacketFactory()),
    _header(NULL)
{
  struct hostent	*server;

  server = gethostbyname(ip.c_str());
  memset((void *)&_serveraddr, 0, sizeof(_serveraddr));
  _serveraddr.sin_family = AF_INET;
  _serveraddr.sin_port = htons(std::atoi(port.c_str()));
  inet_aton(ip.c_str(), &_serveraddr.sin_addr);
}

CUDPNetworkHandler::~CUDPNetworkHandler()
{
  delete _network;
  delete _factory;
}

bool		CUDPNetworkHandler::initSocket()
{
  if (_network->initClientSocket(_ip, _port))
    {
      _socket = _network->getFd();
      return true;
    }
  return false;
}

IServerPacket<ServerUDPResponse>*	CUDPNetworkHandler::receive()
{
  char*					buff;
  IServerPacket<ServerUDPResponse>*	packet;
  ServerUDPHeader*			header;

  if (_header)
    {
      packet = _factory->build(_header);
      if (!packet->checkHeader())
	throw Exceptions::BadHeaderRequest("Error, received bad Header from known client");
      buff = new char[header->size];
      memset(buff, 0, header->size);
      try
	{
	  _network->recvData((void *)buff, header->size, _socket, &_serveraddr);
	}
      catch (Exceptions::NetworkExcept e)
	{
	  std::cerr << e.what() << std::endl;
	  _header = NULL;
	  return NULL;
	}
      packet->setRawData(buff);
      _header = NULL;
      return packet;
    }
  return NULL;
}

bool					CUDPNetworkHandler::send(IClientPacket<ClientUDPCommand>* response)
{
  char*					buff;
  std::string				toSend = response->deserialize();

  try
    {
      _network->sendData((void*)(toSend.c_str()),
			 response->getPacketSize(),
			 _socket,
			 &_serveraddr);
    }
  catch (Exceptions::NetworkExcept e)
    {
      std::cerr << e.what() << std::endl;
      return false;
    }
  return true;
}

bool					CUDPNetworkHandler::selectServer(struct timeval *to)
{
  std::vector<int>			fdList;

  fdList.push_back(_socket);
  _network->selectFD(fdList, to);
  if (!fdList.empty())
    {
      ServerUDPHeader*	header = new ServerUDPHeader();
      ClientDatas	datas;

      try
	{
	  _network->recvData(header, sizeof(*header), _socket, &datas);
	}
      catch (Exceptions::NetworkExcept e)
	{
	  std::cerr << e.what() << std::endl;
	  return false;
	}
      _header = header;
      return true;
    }
  return false;
}

bool		operator==(ClientDatas left, ClientDatas right)
{
  if (left.sin_family == right.sin_family
      && left.sin_port == right.sin_port
      && left.sin_addr.s_addr == right.sin_addr.s_addr)
    return true;
  return false;
}