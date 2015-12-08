#ifndef GAMERINFO_H_
# define GAMERINFO_H_

# include <string>
# include "NetworkDefines.h"

class GamerInfo
{
private:
  ClientDatas*	_clientInfo;

public:
  GamerInfo(ClientDatas*);
  virtual ~GamerInfo();
  ClientDatas*	getClientInfos() const;

private:
  GamerInfo(const GamerInfo &);
  GamerInfo &operator=(const GamerInfo &);
};


#endif /* !GAMERINFO_H_ */
