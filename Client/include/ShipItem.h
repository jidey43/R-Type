#pragma once

# include "GameItem.h"
# include "AssetsController.h"
# include "ViewController.h"

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