#include <string.h>
#include "NickPacket.h"

NickPacket::NickPacket(ClientTCPHeader *header)
  : AClientPacket(header->command),  _data(new NickData), _header(header)
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

}
