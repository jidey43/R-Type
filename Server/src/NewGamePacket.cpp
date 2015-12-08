#include <string.h>
#include "NewGamePacket.h"

NewGamePacket::NewGamePacket()
  : _command(ADD_GAME), _data(new NewGameData)
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
