#pragma once
#include "ViewController.hh"
#include "AssetsController.hh"

extern ViewController *vc;
extern AssetsController *ac;

class GraphicalItem
{
public:
	GraphicalItem();
	sf::Drawable*		getDrawable();
	virtual void				update() = 0;

protected:
	sf::Sprite			*_sprite;
};