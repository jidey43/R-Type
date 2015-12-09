# include <string.h>
# include "AuthTCPPacket.h"

AuthTCPPacket::AuthTCPPacket(ServerTCPResponse resp, int data) : AServerPacket<ServerTCPResponse>(resp), _data(new AuthData)
{
  _data->data = data;
  _data->magic = MAGIC;
}

AuthTCPPacket::~AuthTCPPacket()
{
}

std::string const&		AuthTCPPacket::deserialize()
{
  ServerTCPHeader			header;
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
