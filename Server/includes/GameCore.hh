#ifndef GAMECORE_H_
# define GAMECORE_H_

# include <vector>
# include "GamerInfo.hh"
# include "UDPNetworkHandler.hh"


class GameCore
{
public :
  GameCore(std::string const&, std::string const&);
  virtual ~GameCore();
  bool		run();

private :
  GameCore(const GameCore &);
  GameCore &operator=(const GameCore &);
  bool		receivePacket();
  bool		processPacket(GamerInfo*, IClientPacket<ClientUDPCommand>*);

private :
  std::vector<GamerInfo*>*	_clients;
  UDPNetworkHandler*		_network;
};

#endif /* !GAMECORE_H_ */
