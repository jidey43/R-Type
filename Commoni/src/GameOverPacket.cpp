# include <string.h>
# include "GameOverPacket.h"

GameOverPacket::GameOverPacket(ServerTCPResponse resp, int data) : AServerPacket<ServerTCPResponse>(resp), _header(new ServerTCPHeader), _data(new GameOverData)
{
  _header->magic = MAGIC;
  _header->command = resp;
  _header->size = sizeof(*_data);
  _data->data = data;
  _data->magic = MAGIC;
}

GameOverPacket::GameOverPacket(ServerTCPHeader* header)
  : AServerPacket<ServerTCPResponse>(header->command), _data(new GameOverData), _header(header)
{
}

GameOverPacket::~GameOverPacket()
{
}

std::string const&		GameOverPacket::deserialize()
{
  char*				buff = new char[sizeof(*_header) + sizeof(*_data) + 1];
  static std::string		ret;

  memcpy(buff, _header, sizeof(*_header));
  memcpy(buff + sizeof(*_header), _data, sizeof(*_data));
  buff[sizeof(*_header) + sizeof(*_data)] = 0;
  ret = buff;
  return ret;
}
bool				GameOverPacket::checkHeader()
{
  if (_header->magic != MAGIC)
    return false;
  else if (_header->command < AUTH || _header->command > FAIL)
    return false;
  else if (_header->size < 0)
    return false;
  return true;
}

void				GameOverPacket::setRawData(std::string const& data)
{
  void*			buff;

  buff = (void*)data.c_str();
  memcpy(_data, buff, sizeof(*_data));
}

GameOverData*			GameOverPacket::getData() const
{
  return _data;
}
