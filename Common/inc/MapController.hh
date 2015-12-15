#ifndef MAP_CONTROLLER_HH_
# define MAP_CONTROLLER_HH_

# include <vector>
# include "IObject.hh"
# include "ObjectInfo.hpp"
# include "UDPNetworkHandler.hh"
# include "GamerInfo.hh"
# include "IServerPacket.hh"

class	MapController
{
public:
  MapController();
  ~MapController();


  void		addObject(IObject*);
  void		updateMap();
  std::vector<IServerPacket<ServerUDPResponse>*>*     getMap() const;
  void		updatePlayer(IObject*);
  IObject*	getPlayer(int id);
  void		deletePlayer(int id);
  void		generatePacketsMap(IObject *);

private:
  std::vector<IObject*>		_map;
  std::vector<IServerPacket<ServerUDPResponse>*>	*_deserializedMap;
  std::vector<IObject*>		_toCreate;
  std::vector<IObject*>		_toDestroy;
};

#endif
