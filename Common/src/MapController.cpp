#include <iostream>
#include <algorithm>
#include "MapController.hh"
#include "ObjectInfo.hpp"

unsigned int _maxId;

MapController::MapController(UDPNetworkHandler* network) : _network(network)
{}

MapController::~MapController()
{}

void		MapController::addObject(IObject* obj)
{
  std::cout << "ajout d'un player avec id " << obj->getId() << std::endl;
  _map.push_back(obj);
  // switch (obj->getObjType())
  //   {
  //   case (ObjectInfo::PLAYER):
  //     _network->broadcast(new CrePlayPacket(CRE_PLAY, 0, obj->getId(), obj->getPos().x, obj->getPos().y));
  //     break;
  //   case (ObjectInfo::ALIEN):
  //     break;
  //   case (ObjectInfo::SHOT):
  //     break;
  //   default:
  //     break;
  //   }
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
