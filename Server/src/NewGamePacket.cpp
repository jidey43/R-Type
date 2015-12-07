#include <string.h>
#include "NewGamePacket.h"

NewGamePacket::NewGamePacket(std::string const& data)
  : _command(ADD_GAME), _data(new NewGameData)
{
  setRawData(data);
}

NewGamePacket::~NewGamePacket()
{
}

ClientCommand const&	NewGamePacket::getCommandType() const
{
  return _command;
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
