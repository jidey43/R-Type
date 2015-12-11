# include <string.h>
# include "CrePlayPacket.h"

CrePlayPacket::CrePlayPacket(ServerUDPResponse resp, float x, float y) : AServerPacket<ServerUDPResponse>(resp), _data(new CrePlayData)
{
  _data->x = x;
  _data->x = y;
  _data->magic = MAGIC;
}

CrePlayPacket::CrePlayPacket(ServerUDPHeader *header)
  : AServerPacket<ServerUDPResponse>(header->command), _data(new CrePlayData)
{
}

CrePlayPacket::~CrePlayPacket()
{
}

std::string const&		CrePlayPacket::deserialize()
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
