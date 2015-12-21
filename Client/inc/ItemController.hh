#pragma once

#include <vector>
#include "ViewController.hh"
#include "GraphicalItem.h"
#include "ObjectInfo.hpp"
#include "BydoAlienGraphical.hh"
#include "BasicPlayerProjectileGraphical.h"
#include "BasicAlienProjectileGraphical.h"
#include "Explosion.hh"
#include "PlayerGraphical.h"
#include "CrePlayPacket.h"
#include "CreObjPacket.h"
#include "MovePacket.h"
#include "DelItemPacket.h"
#include "CreIAPacket.h"
#include "IServerPacket.hh"

extern ViewController *vc;

class                           ItemController
{
public:
  ItemController();
  ~ItemController();

public:
  void						draw();
  void						update();

public:
  void						addShip(CrePlayPacket *packet);
  void						addObj(CreObjPacket *packet);
  void						moveShip(MovePacket *packet);
  void						deleteObject(DelItemPacket *packet);
  void                      addExplosion(sf::Vector2f);

public:
  void						addAlien(CreIAPacket *packet);

public:
  void						setBackground(int id);

private:
  sf::Clock					_clock;
  std::vector<GraphicalItem*>			 _items;
  std::vector<GraphicalItem*>			 _unlogicalItems;  
  sf::Sprite*					_background;
  int						_playerCount;
};
