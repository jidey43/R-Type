#pragma once

#include <vector>
#include "ViewController.hh"
#include "GraphicalItem.h"
#include "ObjectInfo.hpp"
#include "BydoAlienGraphical.hh"
#include "BasicPlayerProjectileGraphical.h"
#include "BasicAlienProjectileGraphical.h"
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

public:
	void						addAlien(CreIAPacket *packet);

public:
	void						setBackgroud(int id);

private:
	std::vector<GraphicalItem*> _items;
	sf::Sprite*					_background;
  int						_playerCount;
};
