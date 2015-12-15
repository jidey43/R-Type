#ifndef MAP_CONTROLLER_HH_
# define MAP_CONTROLLER_HH_

# include <vector>
# include "IObject.hh"
# include "UDPNetworkHandler.hh"
# include "GamerInfo.hh"

class	MapController
{
public:
  MapController(UDPNetworkHandler* network);
  ~MapController();

  void		addObject(IObject*);
  void		updateMap();

  void		updatePlayer(IObject*);
  IObject*	getPlayer(int id);
  void		deletePlayer(int id);

private:
  UDPNetworkHandler		*_network;
  std::vector<IObject*>		_map;
};

#endif
