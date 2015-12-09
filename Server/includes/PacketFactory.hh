#ifndef PACKETFACTORY_H_
# define PACKETFACTORY_H_

#include "IClientPacket.hh"
#include "IServerPacket.hh"
#include "NewGamePacket.h"
#include "NickPacket.h"
#include "JoinPacket.hh"
#include "NetworkDefines.h"

class PacketFactory
{
public:
  PacketFactory();
  virtual ~PacketFactory();

  IClientPacket*		build(ClientTCPHeader*);
  IClientPacket*		build(ClientUDPHeader*);
  IServerPacket<ServerTCPResponse>*		build(ServerTCPHeader*);
  IServerPacket<ServerUDPResponse>*		build(ServerUDPHeader*);
  std::string const&				disassemble(IClientPacket* packet);
  std::string const&				disassemble(IServerPacket<ServerTCPResponse>* packet);
  std::string const&				disassemble(IServerPacket<ServerUDPResponse>* packet);
};

#endif
