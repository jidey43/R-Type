#pragma once

#include "ViewController.hh"
#include "AssetsController.hh"
#include "MenuButton.h"
#include "TextArea.h"
#include "Background.h"
#include "CNetworkHandler.hh"
#include "CUDPNetworkHandler.hh"

class			GameSelectorController
{
	public :
	
	GameSelectorController(CUDPNetworkHandler **handler, CNetworkHandler *tcpHand);
	void						loop();
	void						treatEvents();
	void						update();
	void						drawMenuItems();
	void						onClick(ButtonType);
	void						joinGame();

private:
		sf::Clock					_clock;
		keyboardStatus				_keyboardStatus;
		Backgroud*					_background;
		sf::Time					_loopTime;
		bool						_join;
		sf::Text*					_disclaimer;
		
private:
		CNetworkHandler				*_tcpHand;
};
