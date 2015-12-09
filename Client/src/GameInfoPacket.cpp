# include <string.h>
# include "GameInfoPacket.h"

GameInfoPacket::GameInfoPacket(ServerTCPResponse resp, int id, int port) : AServerPacket<ServerTCPResponse>(resp), _header(new ServerTCPHeader), _data(new GameInfoData)
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
  char*				buff = new char[sizeof(*_header) + sizeof(*_data) + 1];
  static std::string		ret;

  memcpy(buff, _header, sizeof(*_header));
  memcpy(*(&buff + sizeof(*_header)), _data, sizeof(*_data));
  buff[sizeof(*_header) + sizeof(*_data)] = 0;
  ret = buff;
  return ret;
}

bool				GameInfoPacket::checkHeader()
{
  if (_header->magic != MAGIC)
    return false;
  else if (_header->command < AUTH || _header->command > FAIL)
    return false;
  else if (_header->size < 0)
    return false;
  return true;
}

void				GameInfoPacket::setRawData(std::string const& data)
{

}

GameInfoData*			GameInfoPacket::getData() const
{
  return _data;
}
