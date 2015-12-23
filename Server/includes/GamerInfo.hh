#ifndef GAMERINFO_H_
# define GAMERINFO_H_

# include <string>
# include <SFML/System/Time.hpp>
# include "NetworkDefines.h"
# include "IClientPacket.hh"

class GamerInfo
{
private:
  ClientDatas*		_clientInfo;
  ClientUDPHeader*	_header;
  std::string		_name;
  bool			_isAuth;
  int			_id;
  sf::Time		_timeout;

public:
  GamerInfo(ClientDatas*);
  virtual ~GamerInfo();
  ClientDatas*		getClientInfos() const;
  void			setHeader(ClientUDPHeader*);
  ClientUDPHeader*	getHeader() const;
  std::string const&	getName() const;
  void			setName(std::string const& name);
  bool			isAuth() const;
  void			setAuth(bool auth);
  int			getID() const;
  void			setID(int id);
  bool			updateAlive(sf::Time const&);
  void			resetAlive();

private:
  GamerInfo(const GamerInfo &);
  GamerInfo &operator=(const GamerInfo &);
};


#endif /* !GAMERINFO_H_ */
