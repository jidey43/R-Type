#include "GamerInfo.hh"

GamerInfo::GamerInfo(ClientDatas* datas)
  : _clientInfo(datas), _header(NULL)
{
}

GamerInfo::~GamerInfo()
{
  delete _clientInfo;
}

ClientDatas*	GamerInfo::getClientInfos() const
{
  return _clientInfo;
}

void		GamerInfo::setHeader(ClientUDPHeader* header)
{
  _header = header;
}

ClientUDPHeader*	GamerInfo::getHeader() const
{
  return _header;
}
