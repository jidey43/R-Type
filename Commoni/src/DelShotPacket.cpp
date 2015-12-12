# include <string.h>
# include "DelShotPacket.h"

DelShotPacket::DelShotPacket(ServerUDPResponse resp, int idx, float x, float y) : AServerPacket<ServerUDPResponse>(resp), _data(new DelShotData), _header(new ServerUDPHeader)
{
  _header->magic = MAGIC;
  _header->command = resp;
  _header->size = sizeof(*_data);
  _header->idx = idx;
  _data->x = x;
  _data->x = y;
  _data->magic = MAGIC;
}

DelShotPacket::DelShotPacket(ServerUDPHeader *header)
  : AServerPacket<ServerUDPResponse>(header->command), _data(new DelShotData), _header(header)
{
}

DelShotPacket::~DelShotPacket()
{
}

void			DelShotPacket::setRawData(std::string const& data)
{
  void*			buff;

  buff = (void*)data.c_str();
  memcpy(_data, buff, sizeof(*_data));
}

DelShotData*		DelShotPacket::getData() const
{
  return _data;
}

bool			DelShotPacket::checkHeader()
{
  if (_header->magic != MAGIC)
    return false;
  else if (_header->command < AUTH_UDP || _header->command > MOVE)
    return false;
  else if (_header->size < 0)
    return false;
  return true;
}

std::string const&		DelShotPacket::deserialize()
{
  char*				buff = new char[sizeof(*_header) + sizeof(*_data) + 1];
  static std::string		ret;

  memcpy(buff, _header, sizeof(*_header));
  memcpy(buff + sizeof(*_header), _data, sizeof(*_data));
  buff[sizeof(*_header) + sizeof(*_data)] = 0;
  ret = buff;
  return ret;
}
