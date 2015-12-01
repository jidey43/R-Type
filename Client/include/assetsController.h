#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics.hpp>

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

public:
	sf::Music					*getSoundTrack();
	sf::Texture					*getShipTexture(int id);
	sf::Texture					*getBackground(int id);
	sf::Texture					*getShot(int id);

private:
	std::string					_assetsPath;

private:
	sf::Music					*_soundTrack;

private:
	std::vector<sf::Texture*>	_shipTexture;
	std::vector<sf::Texture*>	_backgroundTexture;
	sf::Texture*				_shipShot;
};