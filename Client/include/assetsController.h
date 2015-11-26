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

public:
	sf::Music					*getSoundTrack();
	sf::Texture					*getShipTexture(int id);

private:
	std::string					_assetsPath;

private:
	sf::Music					*_soundTrack;

private:
	std::vector<sf::Texture*>	_shipTexture;
};