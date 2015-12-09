#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics.hpp>

typedef enum e_ButtonType
{
	JOIN = 0,
	EXIT,
	NUMBEROFBUTTON,
}			ButtonType;

typedef enum e_BackgroundType
{
	MENU_BACKGROUND = 0,
	BACKGROUND_ONE,
	NUMBEROFBACKGROUND
}				BackgroundType;

typedef enum e_Fonts
{
	STAR = 0,
	NUMBEROFFONTS
}			Font;

class							AssetsController
{
public:
	AssetsController(const char *);
	~AssetsController();

public:
	bool						loadAssets();
	bool						loadSoundAssets();
	bool						loadShipsAssets();
	bool						loadBackground();
	bool						loadShots();
	bool						loadButtons();
	bool						loadFonts();

public:
	sf::Music					*getSoundTrack();
	sf::Texture					*getShipTexture(int id);
	sf::Texture					*getBackground(int id);
	sf::Texture					*getShot(int id);
	sf::Texture					*getButton(ButtonType, bool);
	sf::Texture					*getLogo();
	sf::Font					*getFont(Font);

private:
	std::string					_assetsPath;

private:
	sf::Music					*_soundTrack;

private:
	std::vector<sf::Texture*>	_shipTexture;
	std::vector<sf::Texture*>	_backgroundTexture;
	std::vector<sf::Texture*>	_buttonTexture;
	std::vector<sf::Texture*>	_buttonTextureHigh;
	std::vector<sf::Font*>		_fonts;
	sf::Texture*				_shipShot;
	sf::Texture*				_rtypeLogo;
};