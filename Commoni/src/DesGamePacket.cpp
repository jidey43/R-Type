# include <string.h>
# include "DesGamePacket.h"

DesGamePacket::DesGamePacket(ServerTCPResponse resp, int id, std::string const& gameName, std::string const& players) : AServerPacket<ServerTCPResponse>(resp, sizeof(*_data)), _header(new ServerTCPHeader), _data(new DesGameData)
{
  _header->magic = MAGIC;
  _header->command = resp;
  _header->size = sizeof(*_data);
  _data->id = id;
  bzero(_data->gameName, 256);
  bzero(_data->players, 256);
  memcpy(&(_data->gameName), gameName.c_str(), gameName.size());
  memcpy(&(_data->players), players.c_str(), players.size());
  _data->magic = MAGIC;
}

DesGamePacket::DesGamePacket(ServerTCPHeader* header) :
  AServerPacket<ServerTCPResponse>(header->command, header->size), _data(new DesGameData), _header(header)
{
}

DesGamePacket::~DesGamePacket()
{
}

std::string const&		DesGamePacket::deserialize()
{
  char*				buff = new char[sizeof(*_header) + sizeof(*_data) + 1];
  static std::string		ret;

  memcpy(buff, _header, sizeof(*_header));
  memcpy(buff + sizeof(*_header), _data, sizeof(*_data));
  buff[sizeof(*_header) + sizeof(*_data)] = 0;
  ret = buff;
  return ret;
}

bool				DesGamePacket::checkHeader()
{
  if (_header->magic != MAGIC)
    return false;
  else if (_header->command < AUTH || _header->command > FAIL)
    return false;
  else if (_header->size < 0)
    return false;
  return true;
}

void				DesGamePacket::setRawData(std::string const& data)
{
  void*			buff;

  buff = (void*)data.c_str();
  memcpy(_data, buff, sizeof(*_data));
}

DesGameData*			DesGamePacket::getData() const
{
  return _data;
}
