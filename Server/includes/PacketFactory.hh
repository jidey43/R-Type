#include "IPacket.h"
#include "NetworkDefines.h"

class PacketFactory
{
public:
  PacketFactory();
  virtual ~PacketFactory();

  IPacket*		build(ClientCommand cmd, std::string const& data);
  std::string const&	disassemble(IPacket* packet);

};
