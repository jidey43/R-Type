#include "PacketFactory.hh"

PacketFactory::PacketFactory()
{}

PacketFactory::~PacketFactory()
{}

IServerPacket<ServerUDPResponse>*	PacketFactory::build(ServerUDPHeader *header)
{
  switch(header->command)
    {
    default:
      return NULL;
    }
}

IServerPacket<ServerTCPResponse>*	PacketFactory::build(ServerTCPHeader *header)
{
  switch(header->command)
    {
    default:
      return NULL;
    }
}

IClientPacket<ClientUDPCommand>*		PacketFactory::build(ClientUDPHeader *header)
{
  switch(header->command)
    {
    default:
      return NULL;
    }
}

IClientPacket<ClientTCPCommand>*		PacketFactory::build(ClientTCPHeader* header)
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

std::string const&	PacketFactory::disassemble(IClientPacket<ClientUDPCommand>* packet)
{
  std::string		ret;

  delete(packet);
}

std::string const&	PacketFactory::disassemble(IClientPacket<ClientTCPCommand>* packet)
{
  std::string		ret;

  delete(packet);
}

std::string const&	PacketFactory::disassemble(IServerPacket<ServerTCPResponse>* packet)
{
  std::string		ret;

  delete(packet);
}

std::string const&	PacketFactory::disassemble(IServerPacket<ServerUDPResponse>* packet)
{
  std::string		ret;

  delete(packet);
}
