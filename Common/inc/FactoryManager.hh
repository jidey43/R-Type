#ifndef _FACTORY_MANAGER_HH_
# define _FACTORY_MANAGER_HH_

# include <vector>
# include "MapController.hh"
# include "AlienFactory.hpp"

class FactoryManager
{
public:
  FactoryManager(MapController*);
  ~FactoryManager();

  void		update();

private:
  MapController			*_map;
  std::vector<IAlienFactory*>	_factories;
};

#endif
