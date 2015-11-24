#pragma once
#include <string>
#include <SFML/Audio/Music.hpp>

class            AssetsController
{
public:
	AssetsController(const char *);
	~AssetsController();

public:
	bool		loadAssets();

public:
	sf::Music	*getSoundTrack();

private:
	std::string	_assetsPath;

private:
	sf::Music	*_soundTrack;
};