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
# include "ClientInfo.h"
# include "PacketFactory.hh"
# include "IServerPacket.hh"

template class					INetwork<UDPSocket>;

class UDPNetworkHandler
{
public:
  UDPNetworkHandler(std::string const&, std::string const&);
  virtual ~UDPNetworkHandler();
  std::string					_ip;
  std::string					_port;
  INetwork<UDPSocket>*				_network;
  std::vector<ClientInfo*>			_activeClients;
  PacketFactory*				_factory;
  SOCKET					_socket;

private:
  UDPNetworkHandler(const UDPNetworkHandler &);
  UDPNetworkHandler &operator=(const UDPNetworkHandler &);

public:
  bool						initSocket();
  bool						selectClient();
};

#endif /* !UDPNETWORKHANDLER_H_ */
