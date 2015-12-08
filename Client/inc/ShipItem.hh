#pragma once

# include "GameItem.hh"
# include "AssetsController.hh"
# include "ViewController.hh"

extern AssetsController *ac;
extern ViewController *vc;

class                 ShipItem : public GameItem
{
public:
	ShipItem(int id);
	~ShipItem();

public:
	void			setPosition(sf::Vector2f);
	void			update() {}
};