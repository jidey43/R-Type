#include <string.h>
#include "NewGamePacket.h"

NewGamePacket::NewGamePacket(ClientTCPHeader *header)
  : AClientPacket<ClientTCPCommand>(header->command), _data(new NewGameData), _header(header)
{
}

NewGamePacket::~NewGamePacket()
{
}

void			NewGamePacket::setRawData(std::string const& data)
{
  void*			buff;

  buff = (void*)data.c_str();
  memcpy(_data, buff, sizeof(*_data));
}

NewGameData*		NewGamePacket::getData() const
{
  return _data;
}

bool			NewGamePacket::checkHeader()
{
    if (_header->magic != MAGIC)
    return false;
  else if (_header->command < AUTH_TCP|| _header->command > QUIT)
    return false;
  else if (_header->size < 0)
    return false;
  return true;
}

std::string const&	NewGamePacket::deserialize()
{
  char*				buff = new char[sizeof(*_header) + 1];
  static std::string		ret;

  memcpy(buff, _header, sizeof(*_header));
  memcpy(*(&buff + sizeof(*_header)), _data, sizeof(*_data));
  buff[sizeof(*_header) + sizeof(*_data)] = 0;
  ret = buff;
  return ret;
}
