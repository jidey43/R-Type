#include <iostream>
#include <algorithm>
#include "MapController.hh"

MapController::MapController()
  : _maxID(0)
{}

MapController::~MapController()
{}

void		MapController::addObject(IObject* obj)
{
  std::cout << "opopop" << std::endl;
  _objList.push_back(obj);
}

void		MapController::updateMap()
{
  for (std::vector<IObject*>::iterator it = _map.begin(); it != _map.end(); ++it)
    {
      if ((*it)->getObjectType() != ObjectInfo::PLAYER)
	(*it)->update(_map);
    }
}

void		MapController::updatePlayer(IObject* player)
{
  player->update(_objectList);
}

unsigned int	MapController::getMaxID()
{
  return _maxID++;
}

IObject*	MapController::getPlayer(int id)
{
  for (std::vector<IObject*>::iterator it = _objList.begin(); it != _objList.end(); ++it)
    {
      if ((*it)->getID() == id)
	return (*it);
    }
  return NULL;
}

void		MapController::deletePlayer(int id)
{
  delete (_map.getPlayer(id));
  _map.erase(std::find(_map.begin(), _map.end(), _map.getPlayer(id));
}
