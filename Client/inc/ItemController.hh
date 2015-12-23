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
#include "GlamAlienGraphical.hh"
#include "DokanAlienGraphical.hh"
#include "KayberosAlienGraphical.hh"
#include "RiosAlienGraphical.hh"
#include "ScantAlienGraphical.hh"
#include "ShellAlienGraphical.hh"
#include "YorkAlienGraphical.hh"
#include "Xelf16AlienGraphical.hh"
#include "WallGraphical.hh"
#include "ScoreController.hh"

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
  void						addObj(CreObjPacket *packet, int idPlayer = -1);
  void						moveShip(MovePacket *packet);
  void						deleteObject(DelItemPacket *packet);
  void						addExplosion(sf::Vector2f);

public:
  void						addAlien(CreIAPacket *packet);

public:
  void						setBackground(BackgroundType id);

private:
  sf::Clock					         _clock;
  std::vector<GraphicalItem*>			 _items;
  std::vector<GraphicalItem*>			 _unlogicalItems;
  sf::Sprite*					         _background;
  int						             _playerCount;
  ScoreController                      _scoreCtrl;
};
