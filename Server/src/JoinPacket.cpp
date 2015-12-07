#include "JoinPacket.hh"

JoinPacket::JoinPacket(std::string const& data)
  : _command(JOIN_GAME), _data(new JoinData)
{
  setRawData(data);
}

JoinPacket::~JoinPacket()
{
}

ClientCommand const&	JoinPacket::getCommandType() const
{
  return _command;
}

void			JoinPacket::setRawData(std::string const& data)
{
  void*			buff;

  buff = (void*)data.c_str();
  memcpy(_data, buff, sizeof(*_data));
}

JoinData*		JoinPacket::getData() const
{
  return _data;
}
