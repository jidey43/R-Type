#include <string.h>
#include "NickPacket.h"

NickPacket::NickPacket(ClientTCPHeader *header)
  : AClientPacket<ClientTCPCommand>(header->command),  _data(new NickData), _header(header)
{
}

NickPacket::~NickPacket()
{
}

void			NickPacket::setRawData(std::string const& data)
{
  void*			buff;

  buff = (void*)data.c_str();
  memcpy(_data, buff, sizeof(*_data));
}

NickData*		NickPacket::getData() const
{
  return _data;
}

bool			NickPacket::checkHeader()
{
  if (_header->magic != MAGIC)
    return false;
  else if (_header->command < AUTH_TCP|| _header->command > QUIT)
    return false;
  else if (_header->size < 0)
    return false;
  return true;
}
