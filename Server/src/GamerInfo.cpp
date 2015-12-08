#include "GamerInfo.hh"

GamerInfo::GamerInfo(ClientDatas* datas)
  : _clientInfo(datas)
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
