#ifndef _MAP_CONTROLLER_HH_
# define _MAP_CONTROLLER_HH_

# include <vector>
# include "IObject.hh"

class	MapController
{
public:
  MapController();
  ~MapController();

  void		addObject(IObject*);
  void		updateMap();

  void		updatePlayer();
  IObject*	getPlayer(int id);
  void		deletePlayer(int id);

private:
  std::vector<IObject*>		_map;
  unsigned int			_maxID;

public:
  unsigned int			getMaxID();
};

#endif
