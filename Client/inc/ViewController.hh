#pragma once

# include <iostream>
# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include "GameItem.hh"
# include "KeyboardStatus.hh"
# include "AssetsController.hh"

extern AssetsController *ac;

#define SCREENRATIO 0.83333

#define MAP_SIZE_Y 900
#define MAP_SIZE_X 1600

#define RES_X 1920
#define RES_Y 1080

#define SHIP_ASSET_SIZE_Y 300
#define SHOT_ASSET_SIZE_Y 20

#define LOGO_SIZE_X 500
#define LOGO_SIZE_Y 100

#define BUTTON_X 100
#define BUTTON_Y 50

class GameItem;

class				ViewController
{
public:
	ViewController();
	~ViewController();

//GRAPHICAL STUFF
public:
	void			refresh();
	void			draw(sf::Drawable*);
	void			clear();
	void			operator<<(GameItem*);

//INPUT STUFF
	keyboardStatus	getKeyboardStatus();

//AUDIO STUFF
public:
	void			startSoundtrack();

private:
	sf::RenderWindow	*_mainWindow;
	sf::Music			*_soundTrack;
};