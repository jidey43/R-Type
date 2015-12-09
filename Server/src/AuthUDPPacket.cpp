# include <string.h>
# include "AuthUDPPacket.h"

AuthUDPPacket::AuthUDPPacket(ServerUDPResponse resp, int success, std::string const& name) : AServerPacket<ServerUDPResponse>(resp), _data(new AuthUDPData)
{
  _data->success = success;
  bzero(_data->name, 256);
  memcpy(&(_data->name), name.c_str(), name.size());
  _data->magic = MAGIC;
}

AuthUDPPacket::~AuthUDPPacket()
{
}

std::string const&		AuthUDPPacket::deserialize()
{
  ServerUDPHeader			header;
  char*				buff = new char[sizeof(header) + sizeof(*_data) + 1];
  static std::string		ret;

  header.magic = MAGIC;
  header.command = _command;
  header.size = sizeof(*_data);
  memcpy(buff, &header, sizeof(header));
  memcpy(*(&buff + sizeof(header)), _data, sizeof(*_data));
  buff[sizeof(header) + sizeof(*_data)] = 0;
  ret = buff;
  return ret;
}
