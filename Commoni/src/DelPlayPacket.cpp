# include <string.h>
# include "DelPlayPacket.h"

DelPlayPacket::DelPlayPacket(ServerUDPResponse resp, int idx) : AServerPacket<ServerUDPResponse>(resp), _header(new ServerUDPHeader)
{
  _header->magic = MAGIC;
  _header->command = resp;
  _header->size = 0;
  _header->idx = idx;
}

DelPlayPacket::DelPlayPacket(ServerUDPHeader *header)
  : AServerPacket<ServerUDPResponse>(header->command), _header(header)
{
}

DelPlayPacket::~DelPlayPacket()
{
}

void			DelPlayPacket::setRawData(std::string const& data)
{
}

bool			DelPlayPacket::checkHeader()
{
  if (_header->magic != MAGIC)
    return false;
  else if (_header->command < AUTH_UDP || _header->command > MOVE)
    return false;
  else if (_header->size < 0)
    return false;
  return true;
}

std::string const&		DelPlayPacket::deserialize()
{
  char*				buff = new char[sizeof(*_header) + 1];
  static std::string		ret;

  memcpy(buff, _header, sizeof(*_header));
  buff[sizeof(*_header)] = 0;
  ret = buff;
  return ret;
}
