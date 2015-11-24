#include "AssetsController.h"

AssetsController::AssetsController(const char *assetsPath)
{
	_assetsPath = std::string(assetsPath);	_soundTrack = new sf::Music;
}

AssetsController::~AssetsController()
{

}

bool			AssetsController::loadAssets()
{
	if (_soundTrack->openFromFile(_assetsPath += "audio/ost.ogg") == false)
		return false;
	return true;
}

sf::Music * AssetsController::getSoundTrack()
{
	return _soundTrack;
}
