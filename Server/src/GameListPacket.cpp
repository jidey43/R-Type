# include <string.h>
# include "GameListPacket.h"

GameListPacket::GameListPacket(ServerResponse resp) : _response(resp)
{
}

GameListPacket::~GameListPacket()
{
}

std::string const&		GameListPacket::deserialize()
{
  ServerHeader			header;
  char*				buff = new char[sizeof(header) + 1];
  static std::string		ret;

  header.magic = MAGIC;
  header.command = _response;
  header.size = 0;
  memcpy(buff, &header, sizeof(header));
  buff[sizeof(header)] = 0;
  ret = buff;
  return ret;
}
