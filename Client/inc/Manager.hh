#pragma once

#include "ViewController.hh"
#include "AssetsController.hh"
#include "ItemController.hh"
#include "ObjectInfo.hpp"
#include "CUDPNetworkHandler.hh"
#include "IServerPacket.hh"
#include "CrePlayPacket.h"
#include "CreObjPacket.h"
#include "CreIAPacket.h"
#include "MovePacket.h"

extern ViewController *vc;
extern AssetsController *ac;

class					Manager
{
public:
	Manager(CUDPNetworkHandler*);
	~Manager();

public:
	void				loop();
	sf::Time 		getElapsedTimeSinceLoop();
	void				treatEventsFromKeyboard();
	void				treatEventsFromNetwork();
	void 				treatPacket(IServerPacket<ServerUDPResponse>* res);

private:
	sf::Clock			_clock;
	sf::Time			_referential;

private:
	keyboardStatus		_keyboardStatus;
	ItemController		*_itemCtrl;
	CUDPNetworkHandler *_udpHand;
};
