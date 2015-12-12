# include <string.h>
# include "CreShotPacket.h"

CreShotPacket::CreShotPacket(ServerUDPResponse resp, int idx, float x, float y, int speed) : AServerPacket<ServerUDPResponse>(resp, sizeof(*_data)), _data(new CreShotData), _header(new ServerUDPHeader)
{
  _header->magic = MAGIC;
  _header->command = resp;
  _header->size = sizeof(*_data);
  _header->idx = idx;
  _data->x = x;
  _data->x = y;
  _data->speed = speed;
  _data->magic = MAGIC;
}

CreShotPacket::CreShotPacket(ServerUDPHeader *header)
  : AServerPacket<ServerUDPResponse>(header->command, header->size + sizeof(*_header)), _data(new CreShotData), _header(header)
{
}

CreShotPacket::~CreShotPacket()
{
}

void			CreShotPacket::setRawData(char *data)
{
  memcpy(_data, (void *)data, sizeof(*_data));
}

CreShotData*		CreShotPacket::getData() const
{
  return _data;
}

bool			CreShotPacket::checkHeader()
{
  if (_header->magic != MAGIC)
    return false;
  else if (_header->command < AUTH_UDP || _header->command > MOVE)
    return false;
  else if (_header->size < 0)
    return false;
  return true;
}

std::string const&		CreShotPacket::deserialize()
{
  char*				buff = new char[sizeof(*_header) + sizeof(*_data) + 1];
  static std::string		ret;

  memcpy(buff, _header, sizeof(*_header));
  memcpy(buff + sizeof(*_header), _data, sizeof(*_data));
  buff[sizeof(*_header) + sizeof(*_data)] = 0;
  ret = buff;
  return ret;
}
