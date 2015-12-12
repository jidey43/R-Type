# include <string.h>
# include "AuthUDPPacket.h"

AuthUDPPacket::AuthUDPPacket(ServerUDPResponse resp, int idx, int success, std::string const& name) : AServerPacket<ServerUDPResponse>(resp, sizeof(*_data)), _data(new AuthUDPData)
{
  _header->magic = MAGIC;
  _header->command = resp;
  _header->size = sizeof(*_data);
  _header->idx = idx;
  _data->success = success;
  bzero(_data->name, 256);
  memcpy(&(_data->name), name.c_str(), name.size());
  _data->magic = MAGIC;
}

AuthUDPPacket::AuthUDPPacket(ServerUDPHeader* header)
  : AServerPacket<ServerUDPResponse>(header->command, header->size), _data(new AuthUDPData), _header(header)
{
}

AuthUDPPacket::~AuthUDPPacket()
{
}

void			AuthUDPPacket::setRawData(std::string const& data)
{
  void*			buff;

  buff = (void*)data.c_str();
  memcpy(_data, buff, sizeof(*_data));
}

AuthUDPData*		AuthUDPPacket::getData() const
{
  return _data;
}

bool			AuthUDPPacket::checkHeader()
{
  if (_header->magic != MAGIC)
    return false;
  else if (_header->command < AUTH_UDP || _header->command > MOVE)
    return false;
  else if (_header->size < 0)
    return false;
  return true;
}

std::string const&		AuthUDPPacket::deserialize()
{
  char*				buff = new char[sizeof(*_header) + sizeof(*_data) + 1];
  static std::string		ret;

  memcpy(buff, _header, sizeof(*_header));
  memcpy(buff + sizeof(*_header), _data, sizeof(*_data));
  buff[sizeof(*_header) + sizeof(*_data)] = 0;
  ret = buff;
  return ret;
}
