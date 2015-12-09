#ifndef PACKETFACTORY_H_
# define PACKETFACTORY_H_

#include "IClientPacket.hh"
#include "NetworkDefines.h"

class PacketFactory
{
public:
  PacketFactory();
  virtual ~PacketFactory();

  IClientPacket*		build(ClientTCPHeader*);
  std::string const&	disassemble(IClientPacket* packet);
};

#endif
