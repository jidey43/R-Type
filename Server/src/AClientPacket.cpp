#include "AClientPacket.hh"

AClientPacket::AClientPacket(ClientCommand cmd) : _command(cmd)
{
}

AClientPacket::~AClientPacket()
{
}

ClientCommand		AClientPacket::getCommandType() const
{
  return _command;
}
