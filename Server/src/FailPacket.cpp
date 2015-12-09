# include <string.h>
# include "FailPacket.h"

FailPacket::FailPacket(ServerTCPResponse resp) : _response(resp)
{
}

FailPacket::~FailPacket()
{
}

std::string const&		FailPacket::deserialize()
{
  ServerTCPHeader			header;
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
