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

public:
	sf::Music					*getSoundTrack();
	sf::Texture					*getShipTexture(int id);
	sf::Texture					*getBackground(int id);
	sf::Texture					*getShot(int id);
	sf::Texture					*getButton(ButtonType, bool);

private:
	std::string					_assetsPath;

private:
	sf::Music					*_soundTrack;

private:
	std::vector<sf::Texture*>	_shipTexture;
	std::vector<sf::Texture*>	_backgroundTexture;
	std::vector<sf::Texture*>	_buttonTexture;
	std::vector<sf::Texture*>	_buttonTextureHigh;
	sf::Texture*				_shipShot;
};