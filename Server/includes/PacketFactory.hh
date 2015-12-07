#include "IClientPacket.hh"
#include "NetworkDefines.h"

class PacketFactory
{
public:
  PacketFactory();
  virtual ~PacketFactory();

  IClientPacket*		build(ClientCommand cmd, std::string const& data);
  std::string const&	disassemble(IClientPacket* packet);
};
