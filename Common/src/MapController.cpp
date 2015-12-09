#include "MapController.hh"
#include <iostream>

MapController::MapController()
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
}

void		MapController::updatePlayer()
{
}
