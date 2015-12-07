#include "PaquetFactory.hh"

PacketFactory::PacketFactory()
{}

PacketFactory::~PacketFactory()
{}

IPacket*		PacketFactory::build(ClientCommand cmd, std::string const& data)
{
  switch(cmd)
    {
    case DESCRIBE_GAME:
      return new DescribePacket(data)
      break;
    case SET_NICK:
      return new SetNickPacket(data)
      break;
    case JOIN_GAME:
      return new JoinPacket(data)
      break;
    case CREATE_GAME:
      return new NewGamePacket(data)
      break;
    default:
      return NULL
    }
}

std::string const&	PacketFactory::disassemble(IPacket* packet)
{
  std::string		ret;

  ret +=
}
