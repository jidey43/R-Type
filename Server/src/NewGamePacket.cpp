#include <string.h>
#include "NewGamePacket.h"

NewGamePacket::NewGamePacket(ClientTCPHeader *header)
  : AClientPacket(header->command), _data(new NewGameData), _header(header)
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

}
