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
  
  
private:
  std::vector<IObject*>		_objList;
};

#endif
