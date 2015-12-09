#ifndef GAMERINFO_H_
# define GAMERINFO_H_

# include <string>
# include "NetworkDefines.h"
# include "IClientPacket.hh"

class GamerInfo
{
private:
  ClientDatas*		_clientInfo;
  ClientUDPHeader*	_header;

public:
  GamerInfo(ClientDatas*);
  virtual ~GamerInfo();
  ClientDatas*		getClientInfos() const;
  void			setHeader(ClientUDPHeader*);
  ClientUDPHeader*	getHeader() const;

private:
  GamerInfo(const GamerInfo &);
  GamerInfo &operator=(const GamerInfo &);
};


#endif /* !GAMERINFO_H_ */
