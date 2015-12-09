# include <string.h>
# include "GameListPacket.h"

GameListPacket::GameListPacket(ServerTCPResponse resp) : AServerPacket<ServerTCPResponse>(resp)
{
}

GameListPacket::~GameListPacket()
{
}

std::string const&		GameListPacket::deserialize()
{
  ServerTCPHeader			header;
  char*				buff = new char[sizeof(header) + 1];
  static std::string		ret;

  header.magic = MAGIC;
  header.command = _command;
  header.size = 0;
  memcpy(buff, &header, sizeof(header));
  buff[sizeof(header)] = 0;
  ret = buff;
  return ret;
}
