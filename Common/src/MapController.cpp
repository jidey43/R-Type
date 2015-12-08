#include "MapController.hh"

MapController::MapController()
{}

MapController::~MapController()
{}

void		MapController::addObject(IObject* obj)
{
  _objList.push_back(obj);
}

void		MapController::updateMap()
{
}

void		MapController::updatePlayer()
{
}
