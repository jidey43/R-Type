# include <string.h>
# include "NextLvlPacket.hh"

NextLvlPacket::NextLvlPacket(ServerTCPResponse resp, int data) : AServerPacket<ServerTCPResponse>(resp, sizeof(*_data) + sizeof(*_header)), _header(new ServerTCPHeader), _data(new NextLvlData)
{
  _header->magic = MAGIC;
  _header->command = resp;
  _header->size = sizeof(*_data);
  _data->data = data;
  _data->magic = MAGIC;
}

NextLvlPacket::NextLvlPacket(ServerTCPHeader* header)
  : AServerPacket<ServerTCPResponse>(header->command, header->size + sizeof(*_header)), _data(new NextLvlData), _header(header)
{
}

NextLvlPacket::~NextLvlPacket()
{
}

char*				NextLvlPacket::deserialize()
{
  char*				buff = new char[sizeof(*_header) + sizeof(*_data)];

  memcpy(buff, _header, sizeof(*_header));
  memcpy(buff + sizeof(*_header), _data, sizeof(*_data));
  return buff;
}

bool				NextLvlPacket::checkHeader()
{
  if (_header->magic != MAGIC)
    return false;
  else if (_header->command < AUTH || _header->command > FAIL)
    return false;
  else if (_header->size < 0)
    return false;
  return true;
}

void				NextLvlPacket::setRawData(char *data)
{
  memcpy(_data, (void *)data, sizeof(*_data));
}

NextLvlData*			NextLvlPacket::getData() const
{
  return _data;
}
