# include <string.h>
# include "DelIAPacket.h"

DelIAPacket::DelIAPacket(ServerUDPResponse resp, int idx, int data) : AServerPacket<ServerUDPResponse>(resp, sizeof(*_data) + sizeof(*_header)), _data(new DelIAData), _header(new ServerUDPHeader)
{
  _header->magic = MAGIC;
  _header->command = resp;
  _header->size = sizeof(*_data);
  _header->idx = idx;
  _data->data = data;
  _data->magic = MAGIC;
}

DelIAPacket::DelIAPacket(ServerUDPHeader *header)
  : AServerPacket<ServerUDPResponse>(header->command, header->size + sizeof(*_header)), _data(new DelIAData), _header(header)
{
}

DelIAPacket::~DelIAPacket()
{
}

void			DelIAPacket::setRawData(char *data)
{
  memcpy(_data, (void *)data, sizeof(*_data));
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

char*				DelIAPacket::deserialize()
{
  char*				buff = new char[sizeof(*_header) + sizeof(*_data) + 1];

  memcpy(buff, _header, sizeof(*_header));
  memcpy(buff + sizeof(*_header), _data, sizeof(*_data));
  buff[sizeof(*_header) + sizeof(*_data)] = 0;
  return buff;
}
