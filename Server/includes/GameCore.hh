#ifndef GAMECORE_H_
# define GAMECORE_H_

# include <vector>
# include "Player.hh"
# include "GamerInfo.hh"
# include "FactoryManager.hh"
# include "MapController.hh"

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
  void		authGamer(GamerInfo* client, IClientPacket<ClientUDPCommand>*);
  void		gamerTryShoot(GamerInfo* client, IClientPacket<ClientUDPCommand>* packet);
  void		gamerMove(GamerInfo* client, IClientPacket<ClientUDPCommand>* packet);
  void		gamerDisconnect(GamerInfo* client, IClientPacket<ClientUDPCommand>* packet);

private :
  std::vector<GamerInfo*>*	_clients;
  UDPNetworkHandler*		_network;
  MapController*		_map;
  FactoryManager*		_factory;
};

#endif /* !GAMECORE_H_ */
