#include <iostream>
#include <algorithm>
#include "MapController.hh"
#include "ObjectInfo.hpp"

unsigned int _maxId;

MapController::MapController() : _map(), _deserializedMap(new std::vector<IServerPacket<ServerUDPResponse>*>)
{}

MapController::~MapController()
{
  delete _deserializedMap;
}

void			MapController::generatePacketsMap(IObject* player)
{
  for (std::vector<IObject*>::iterator it = _map.begin(); it != _map.end(); ++it)
    {
      if (*it == player)
	continue ;
      switch ((*it)->getObjType())
	{
	case ObjectInfo::PLAYER :
	  _deserializedMap->push_back(new CrePlayPacket(CRE_PLAY, 0, (*it)->getId(), (*it)->getPos().x, (*it)->getPos().y));
	  break ;
	case ObjectInfo::SHOT :
	  _deserializedMap->push_back(new CreObjPacket(CRE_OBJ, 0, (*it)->getId(), (*it)->getPos().x, (*it)->getPos().y, 2, ObjectInfo::PLAYERREGULAR));
	  break ;
	default :
	  break ;
	}
    }
}

std::vector<IServerPacket<ServerUDPResponse>*>*	MapController::getMap() const
{
  return _deserializedMap;
}

void		MapController::addObject(IObject* obj)
{
  _map.push_back(obj);
}

void		MapController::updateMap(// sf::Clock const& clock
					 )
{
  _deserializedMap->clear();
  for (std::vector<IObject*>::iterator it = _map.begin(); it != _map.end(); ++it)
    {
      (*it)->update(_map// , clock
		    );
      checkNewObj(it, (*it));
    }
}

void		MapController::checkNewObj(std::vector<IObject*>::iterator& it, IObject* obj)
{
  if (obj->isShooting())
    {
      _deserializedMap->push_back(new CreObjPacket(CRE_OBJ, 0, obj->getId(), obj->getPos().x, obj->getPos().y, 2, ObjectInfo::PLAYERREGULAR));
      // _map->addObject(obj->BasicShoot());
    }  // if (obj->)
}

void		MapController::updatePlayer(IObject* player// , sf::Clock const& clock
					    )
{
  player->update(_map// , clock
		 );
}

IObject*	MapController::getPlayer(int id)
{
  if (id == -1)
    return NULL;
  for (std::vector<IObject*>::iterator it = _map.begin(); it != _map.end(); ++it)
    {
      if ((*it)->getId() == id)
	return (*it);
    }
  return NULL;
}

void		MapController::deletePlayer(int id)
{
  delete (this->getPlayer(id));
  _map.erase(std::find(_map.begin(), _map.end(), this->getPlayer(id)));
}
