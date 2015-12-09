# include <string.h>
# include "AuthPacket.h"

AuthPacket::AuthPacket(ServerResponse resp, int data) : _response(resp), _data(new AuthData)
{
  _data->data = data;
  _data->magic = MAGIC;
}

AuthPacket::~AuthPacket()
{
}

std::string const&		AuthPacket::deserialize()
{
  ServerTCPHeader			header;
  char*				buff = new char[sizeof(header) + sizeof(*_data) + 1];
  static std::string		ret;

  header.magic = MAGIC;
  header.command = _response;
  header.size = sizeof(*_data);
  memcpy(buff, &header, sizeof(header));
  memcpy(*(&buff + sizeof(header)), _data, sizeof(*_data));
  buff[sizeof(header) + sizeof(*_data)] = 0;
  ret = buff;
  return ret;
}
