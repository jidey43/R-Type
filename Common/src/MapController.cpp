#include <iostream>
#include <algorithm>
#include "MapController.hh"

unsigned int _maxId;

MapController::MapController()
{}

MapController::~MapController()
{}

void		MapController::addObject(IObject* obj)
{
  std::cout << "ajout d'un player avec id " << obj->getId() << std::endl;
  _map.push_back(obj);
}

void		MapController::updateMap()
{
  for (std::vector<IObject*>::iterator it = _map.begin(); it != _map.end(); ++it)
    {
	(*it)->update(_map);
    }
}

void		MapController::updatePlayer(IObject* player)
{
  player->update(_map);
}

IObject*	MapController::getPlayer(int id)
{
  std::cout << "trying to find player with id = " << id << std::endl;
  for (std::vector<IObject*>::iterator it = _map.begin(); it != _map.end(); ++it)
    {
      if ((*it)->getId() == id)
	return (*it);
    }
  std::cout << "not found player" << std::endl;
  return NULL;
}

void		MapController::deletePlayer(int id)
{
  delete (this->getPlayer(id));
  _map.erase(std::find(_map.begin(), _map.end(), this->getPlayer(id)));
}
