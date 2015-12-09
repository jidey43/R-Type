# include <string.h>
# include "GameOverPacket.h"

GameOverPacket::GameOverPacket(ServerResponse resp, int data) : _response(resp), _data(new GameOverData)
{
  _data->data = data;
  _data->magic = MAGIC;
}

GameOverPacket::~GameOverPacket()
{
}

std::string const&		GameOverPacket::deserialize()
{
  ServerHeader			header;
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
