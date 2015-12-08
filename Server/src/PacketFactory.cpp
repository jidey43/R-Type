#include "PacketFactory.hh"
#include "NewGamePacket.h"

PacketFactory::PacketFactory()
{}

PacketFactory::~PacketFactory()
{}

IClientPacket*		PacketFactory::build(ClientCommand cmd)
{
  switch(cmd)
    {
    // case DESCRIBE_GAME:
    //   return new DescribePacket()
    //   break;
    // case AUTH_TCP:
    //   return new SetNickPacket()
    //   break;
    // case JOIN_GAME:
    //   return new JoinPacket()
    //   break;
    case ADD_GAME:
      return new NewGamePacket();
      break;
    default:
      return NULL;
    }
}

std::string const&	PacketFactory::disassemble(IClientPacket* packet)
{
  std::string		ret;

  // ret +=
}
