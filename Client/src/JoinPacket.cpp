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

std::string const&	JoinPacket::deserialize()
{
  char*				buff = new char[sizeof(*_header) + 1];
  static std::string		ret;

  memcpy(buff, _header, sizeof(*_header));
  memcpy(*(&buff + sizeof(*_header)), _data, sizeof(*_data));
  buff[sizeof(*_header) + sizeof(*_data)] = 0;
  ret = buff;
  return ret;
}
