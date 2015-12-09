#include "JoinPacket.hh"

JoinPacket::JoinPacket(ClientTCPHeader* header)
  : AClientPacket(header->command), _data(new JoinData), _header(header)
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

bool			JoinPacket::checkHeader()
{

}
