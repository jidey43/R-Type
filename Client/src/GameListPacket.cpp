# include <string.h>
# include "GameListPacket.h"

GameListPacket::GameListPacket(ServerTCPResponse resp) : AServerPacket<ServerTCPResponse>(resp), _header(new ServerTCPHeader)
{
  _header->magic = MAGIC;
  _header->size = 0;
  _header->command = resp;
}

GameListPacket::~GameListPacket()
{
}

std::string const&		GameListPacket::deserialize()
{
  char*				buff = new char[sizeof(*_header) + 1];
  static std::string		ret;

  memcpy(buff, _header, sizeof(*_header));
  buff[sizeof(_header)] = 0;
  ret = buff;
  return ret;
}

bool				GameListPacket::checkHeader()
{
  if (_header->magic != MAGIC)
    return false;
  else if (_header->command < AUTH || _header->command > FAIL)
    return false;
  else if (_header->size < 0)
    return false;
  return true;
}

void				GameListPacket::setRawData(std::string const& data)
{
}