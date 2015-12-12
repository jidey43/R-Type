# include <string.h>
# include "DelIAPacket.h"

DelIAPacket::DelIAPacket(ServerUDPResponse resp, int idx, int data) : AServerPacket<ServerUDPResponse>(resp), _data(new DelIAData), _header(new ServerUDPHeader)
{
  _header->magic = MAGIC;
  _header->command = resp;
  _header->size = sizeof(*_data);
  _header->idx = idx;
  _data->data = data;
  _data->magic = MAGIC;
}

DelIAPacket::DelIAPacket(ServerUDPHeader *header)
  : AServerPacket<ServerUDPResponse>(header->command), _data(new DelIAData), _header(header)
{
}

DelIAPacket::~DelIAPacket()
{
}

void			DelIAPacket::setRawData(std::string const& data)
{
  void*			buff;

  buff = (void*)data.c_str();
  memcpy(_data, buff, sizeof(*_data));
}

DelIAData*		DelIAPacket::getData() const
{
  return _data;
}

bool			DelIAPacket::checkHeader()
{
  if (_header->magic != MAGIC)
    return false;
  else if (_header->command < AUTH_UDP || _header->command > MOVE)
    return false;
  else if (_header->size < 0)
    return false;
  return true;
}

std::string const&		DelIAPacket::deserialize()
{
  char*				buff = new char[sizeof(*_header) + sizeof(*_data) + 1];
  static std::string		ret;

  memcpy(buff, _header, sizeof(*_header));
  memcpy(buff + sizeof(*_header), _data, sizeof(*_data));
  buff[sizeof(*_header) + sizeof(*_data)] = 0;
  ret = buff;
  return ret;
}
