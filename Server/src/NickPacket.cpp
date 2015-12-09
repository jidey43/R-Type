#include <string.h>
#include "NickPacket.h"

NickPacket::NickPacket()
  : _command(AUTH_TCP), _data(new NickData)
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
