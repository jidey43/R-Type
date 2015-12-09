# include <string.h>
# include "DesGamePacket.h"

DesGamePacket::DesGamePacket(ServerTCPResponse resp, int id, std::string const& gameName, std::string const& players) : _response(resp), _data(new DesGameData)
{
  _data->id = id;
  bzero(_data->gameName, 256);
  bzero(_data->players, 256);
  memcpy(&(_data->gameName), gameName.c_str(), gameName.size());
  memcpy(&(_data->players), players.c_str(), players.size());
  _data->magic = MAGIC;
}

DesGamePacket::~DesGamePacket()
{
}

std::string const&		DesGamePacket::deserialize()
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
