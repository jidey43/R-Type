#ifndef UDPNETWORKHANDLER_H_
# define UDPNETWORKHANDLER_H_

# include <string>
# include <vector>
# include "TCPSocket.hh"
# include "UDPSocket.hh"
# include "NetworkDefines.h"
# include "INetwork.hh"
# include "UNetwork.hh"
# include "WNetwork.hh"
# include "GamerInfo.hh"
# include "PacketFactory.hh"
# include "IServerPacket.hh"
# include "IClientPacket.hh"
# include "Exceptions.hpp"

template class					INetwork<UDPSocket>;

class UDPNetworkHandler
{
public:
  UDPNetworkHandler(std::string const&, std::string const&, std::vector<GamerInfo*>*);
  virtual ~UDPNetworkHandler();

private:
  UDPNetworkHandler(const UDPNetworkHandler &);
  UDPNetworkHandler	&operator=(const UDPNetworkHandler &);
  GamerInfo*		getClient(ClientDatas*);

public:
  bool						initSocket();
  GamerInfo*					selectClient();
  IClientPacket<ClientUDPCommand>*		receiveFrom(GamerInfo*);
  bool						sendTo(GamerInfo*, IServerPacket<ServerUDPResponse>*);

private:
  std::string					_ip;
  std::string					_port;
  INetwork<UDPSocket>*				_network;
  std::vector<GamerInfo*>*			_clients;
  PacketFactory*				_factory;
  SOCKET					_socket;
};

bool		operator==(ClientDatas left, ClientDatas right);

#endif /* !UDPNETWORKHANDLER_H_ */
