# include <string.h>
# include "GameInfoPacket.h"

GameInfoPacket::GameInfoPacket(ServerTCPResponse resp, int id, int port) : AServerPacket<ServerTCPResponse>(resp), _data(new GameInfoData)
{
  _data->id = id;
  _data->port = port;
  _data->magic = MAGIC;
}

GameInfoPacket::~GameInfoPacket()
{
}

std::string const&		GameInfoPacket::deserialize()
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
