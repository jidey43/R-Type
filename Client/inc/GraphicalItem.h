#pragma once
#include "ViewController.hh"
#include "AssetsController.hh"

//extern ViewController *vc;
extern AssetsController *ac;

class GraphicalItem
{
public:
	GraphicalItem();
	sf::Drawable*		getDrawable();
	virtual bool	        update() = 0;

protected:
	sf::Sprite			*_sprite;
};
