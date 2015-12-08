#include "JoinPacket.hh"

JoinPacket::JoinPacket()
  : _command(JOIN_GAME), _data(new JoinData)
{
}

JoinPacket::~JoinPacket()
{
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
