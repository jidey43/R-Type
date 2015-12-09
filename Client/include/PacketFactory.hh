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

  IClientPacket<ClientTCPCommand>*		build(ClientTCPHeader*);
  IClientPacket<ClientUDPCommand>*		build(ClientUDPHeader*);
  IServerPacket<ServerTCPResponse>*		build(ServerTCPHeader*);
  IServerPacket<ServerUDPResponse>*		build(ServerUDPHeader*);
  std::string const&				disassemble(IClientPacket<ClientUDPCommand>* packet);
  std::string const&				disassemble(IClientPacket<ClientTCPCommand>* packet);
  std::string const&				disassemble(IServerPacket<ServerTCPResponse>* packet);
  std::string const&				disassemble(IServerPacket<ServerUDPResponse>* packet);
};

#endif
