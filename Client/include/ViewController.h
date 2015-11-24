#pragma once

# include <iostream>
# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include "KeyboardStatus.h"

class				ViewController
{
public:
	ViewController();
	~ViewController();

public:
	void			refresh();
	void			draw(sf::Drawable*);
	void			clear();
	keyboardStatus			getEvents();

private:
	sf::RenderWindow	*_mainWindow;

};