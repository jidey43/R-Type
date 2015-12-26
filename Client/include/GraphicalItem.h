#pragma once
#include "ViewController.hh"
#include "AssetsController.hh"
#include "IObject.hh"

//extern ViewController *vc;
extern AssetsController *ac;

class GraphicalItem
{
public:
	GraphicalItem();
	virtual sf::Drawable*		getDrawable();
	virtual bool	        update(sf::Clock const&) = 0;

protected:
	sf::Sprite			*_sprite;
};
