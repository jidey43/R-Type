# include <string.h>
# include "AuthTCPPacket.h"

AuthTCPPacket::AuthTCPPacket(ServerTCPResponse resp, int data) : AServerPacket<ServerTCPResponse>(resp), _header(new ServerTCPHeader), _data(new AuthTCPData)
{
  _header->size = sizeof(*_data);
  _header->magic = MAGIC;
  _header->command = resp;
  _data->data = data;
  _data->magic = MAGIC;
}

AuthTCPPacket::AuthTCPPacket(ServerTCPHeader* header)
  : AServerPacket<ServerTCPResponse>(header->command), _data(new AuthTCPData)
{
}

AuthTCPPacket::~AuthTCPPacket()
{
}

std::string const&		AuthTCPPacket::deserialize()
{
  char*				buff = new char[sizeof(_header) + sizeof(*_data) + 1];
  static std::string		ret;

  memcpy(buff, _header, sizeof(*_header));
  memcpy(*(&buff + sizeof(*_header)), _data, sizeof(*_data));
  buff[sizeof(*_header) + sizeof(*_data)] = 0;
  ret = buff;
  return ret;
}
bool				AuthTCPPacket::checkHeader()
{
  if (_header->magic != MAGIC)
    return false;
  else if (_header->command < AUTH || _header->command > FAIL)
    return false;
  else if (_header->size < 0)
    return false;
  return true;
}

void				AuthTCPPacket::setRawData(std::string const& data)
{
  void*			buff;

  buff = (void*)data.c_str();
  memcpy(_data, buff, sizeof(*_data));
}

AuthTCPData*			AuthTCPPacket::getData() const
{
  return _data;
}
