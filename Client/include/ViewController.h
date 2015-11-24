#pragma once

# include <iostream>
# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include "KeyboardStatus.h"
# include "AssetsController.h"

extern AssetsController *ac;

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

//INPUT STUFF
	keyboardStatus	getEvents();

//AUDIO STUFF
public:
	void			startSoundtrack();

private:
	sf::RenderWindow	*_mainWindow;
	sf::Music			*_soundTrack;
};