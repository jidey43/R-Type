#include "PacketFactory.hh"

PacketFactory::PacketFactory()
{}

PacketFactory::~PacketFactory()
{}

// IClientPacket*		PacketFactory::build(ServerUDPHeader *header)
// {
//   switch(header->command)
//     {
//     default:
//       return NULL;
//     }
// }

// IClientPacket*		PacketFactory::build(ServerTCPHeader *header)
// {
//   switch(header->command)
//     {
//     default:
//       return NULL;
//     }
// }

// IClientPacket*		PacketFactory::build(ClientUDPHeader *header)
// {
//   switch(header->command)
//     {
//     default:
//       return NULL;
//     }
// }

IClientPacket*		PacketFactory::build(ClientTCPHeader* header)
{
  switch(header->command)
    {
    case AUTH_TCP:
      return new NickPacket(header);
      break;
    case JOIN_GAME:
      return new JoinPacket(header);
      break;
    case ADD_GAME:
      return new NewGamePacket(header);
      break;
    default:
      return NULL;
      break;
    }
}

std::string const&	PacketFactory::disassemble(IClientPacket* packet)
{
  std::string		ret;

  delete(packet);
  // ret +=
}
