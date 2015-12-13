#ifndef CUDPNETWORKHANDLER_H_
# define CUDPNETWORKHANDLER_H_

# include <string>
# include <vector>
# include <string.h>
# include "CUDPSocket.hh"
# include "NetworkDefines.h"
# include "CINetwork.hh"
# include "CUNetwork.hh"
# include "CWNetwork.hh"
# include "GamerInfo.hh"
# include "PacketFactory.hh"
# include "IServerPacket.hh"
# include "IClientPacket.hh"
# include "Exceptions.hpp"

template class					CINetwork<CUDPSocket>;

class CUDPNetworkHandler
{
public:
  CUDPNetworkHandler(std::string const&, std::string const&);
  virtual ~CUDPNetworkHandler();

private:
  CUDPNetworkHandler(const CUDPNetworkHandler &);
  CUDPNetworkHandler	&operator=(const CUDPNetworkHandler &);

public:
  bool						initSocket();
  bool						selectServer();
  IServerPacket<ServerUDPResponse>*		receive();
  bool						send(IClientPacket<ClientUDPCommand>*);

private:
  std::string					_ip;
  std::string					_port;
  CINetwork<CUDPSocket>*			_network;
  PacketFactory*				_factory;
  SOCKET					_socket;
  ClientDatas					_serveraddr;
  ServerUDPHeader*				_header;
};

bool		operator==(ClientDatas left, ClientDatas right);

#endif /* !CUDPNETWORKHANDLER_H_ */
