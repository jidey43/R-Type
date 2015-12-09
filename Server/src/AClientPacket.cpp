#include "AClientPacket.hh"

AClientPacket::AClientPacket(ClientTCPCommand cmd) : _command(cmd)
{
}

AClientPacket::~AClientPacket()
{
}

ClientTCPCommand		AClientPacket::getCommandType() const
{
  return _command;
}
