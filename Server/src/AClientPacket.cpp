#include "AClientPacket.hh"

AClientPacket::AClientPacket()
{
}

AClientPacket::~AClientPacket()
{
}

ClientCommand		AClientPacket::getCommandType() const
{
  return _command;
}

bool			AClientPacket::setRawHeader(ClientHeader* header)
{
  return (header->magic != MAGIC ? false : (header->size >= 0 ? true : false));
}
