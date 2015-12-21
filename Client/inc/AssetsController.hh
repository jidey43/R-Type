#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio.hpp>
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

typedef enum    e_Sound
{
    BASICSHOT = 0,
    NUMBEROFSOUND   
}               Sound;

typedef enum e_Fonts
{
	STAR = 0,
	NUMBEROFFONTS
}			Font;

typedef enum e_Shot
{
	BASICALIENSHOT = 0,
	BASICPLAYERSHOT,
	NUMBEROFSHOT
}			 Shot;

typedef enum e_AlienType
{
	BYDO = 0,
	GLAM,
	DOKAN,
	KAYBEROS,
	RIOS,
	SCANT,
	SHELL,
	YORK,
	XELF16,
	NUMBEROFALIEN
}			AlienType;

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
	bool						loadAliens();

public:
	sf::Music					*getSoundTrack();
    sf::SoundBuffer             *getSound(Sound);
	sf::Texture					*getShipTexture(int id);
	sf::Texture					*getBackground(int id);
	sf::Texture					*getShot(Shot);
	sf::Texture					*getButton(ButtonType, bool);
	sf::Texture					*getLogo();
	sf::Font					*getFont(Font);
	sf::Texture					*getAlien(AlienType);

private:
	std::string					_assetsPath;

private:
	sf::Music					*_soundTrack;

private:
	std::vector<sf::Texture*>	_ships;
	std::vector<sf::Texture*>	_aliens;
	std::vector<sf::Texture*>	_backgrounds;
	std::vector<sf::Texture*>	_buttons;
	std::vector<sf::Texture*>	_buttonsHigh;
	std::vector<sf::Texture*>	_shots;
	std::vector<sf::Font*>		_fonts;
    std::vector<sf::SoundBuffer*> _sounds;
	sf::Texture*				_rtypeLogo;
};