#include "GamerInfo.hh"

GamerInfo::GamerInfo(ClientDatas* datas)
  : _clientInfo(datas), _header(NULL), _name(""), _isAuth(false), _id(-1)
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

std::string const&	GamerInfo::getName() const
{
  return _name;
}

void			GamerInfo::setName(std::string const& name)
{
  _name = name;
}

bool			GamerInfo::isAuth() const
{
  return _isAuth;
}

void			GamerInfo::setAuth(bool auth)
{
  _isAuth = auth;
}

int			GamerInfo::getID() const
{
  return _id;
}

void			GamerInfo::setID(int id)
{
  _id = id;
}
