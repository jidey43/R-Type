# include <string.h>
# include "CreIAPacket.h"

CreIAPacket::CreIAPacket(ServerUDPResponse resp, int idx, int id, float x, float y) : AServerPacket<ServerUDPResponse>(resp, sizeof(*_data)), _data(new CreIAData), _header(new ServerUDPHeader)
{
  _header->magic = MAGIC;
  _header->command = resp;
  _header->size = sizeof(*_data);
  _header->idx = idx;
  _data->id = id;
  _data->x = x;
  _data->x = y;
  _data->magic = MAGIC;
}

CreIAPacket::CreIAPacket(ServerUDPHeader *header)
  : AServerPacket<ServerUDPResponse>(header->command, header->size), _data(new CreIAData), _header(header)
{
}

CreIAPacket::~CreIAPacket()
{
}

void			CreIAPacket::setRawData(std::string const& data)
{
  void*			buff;

  buff = (void*)data.c_str();
  memcpy(_data, buff, sizeof(*_data));
}

CreIAData*		CreIAPacket::getData() const
{
  return _data;
}

bool			CreIAPacket::checkHeader()
{
  if (_header->magic != MAGIC)
    return false;
  else if (_header->command < AUTH_UDP || _header->command > MOVE)
    return false;
  else if (_header->size < 0)
    return false;
  return true;
}

std::string const&		CreIAPacket::deserialize()
{
  char*				buff = new char[sizeof(*_header) + sizeof(*_data) + 1];
  static std::string		ret;

  memcpy(buff, _header, sizeof(*_header));
  memcpy(buff + sizeof(*_header), _data, sizeof(*_data));
  buff[sizeof(*_header) + sizeof(*_data)] = 0;
  ret = buff;
  return ret;
}
