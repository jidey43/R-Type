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
  if (_header->magic != MAGIC)
    return false;
  else if (_header->command < AUTH_TCP|| _header->command > QUIT)
    return false;
  else if (_header->size < 0)
    return false;
  return true;
}
