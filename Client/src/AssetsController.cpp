#include "assetsController.h"

AssetsController::AssetsController(const char *assetsPath)
{
	_assetsPath = std::string(assetsPath);	_soundTrack = new sf::Music;
}

AssetsController::~AssetsController()
{

}

bool AssetsController::loadAssets()
{
	if (
		loadShipsAssets() &&
		loadSoundAssets()
		)
		return (true);
	return (false);
}

bool AssetsController::loadSoundAssets()
{
	if (_soundTrack->openFromFile(_assetsPath + "audio/ost.ogg") == false)
		return false;
	return true;
}

bool AssetsController::loadShipsAssets()
{
	for (int i = 0; i != 4; i++)
	{
		_shipTexture.emplace_back(new sf::Texture);
	}
	if (
		_shipTexture[0]->loadFromFile(_assetsPath + "ships/ship1.png") &&
		_shipTexture[1]->loadFromFile(_assetsPath + "ships/ship2.png") &&
		_shipTexture[2]->loadFromFile(_assetsPath + "ships/ship3.png") &&
		_shipTexture[3]->loadFromFile(_assetsPath + "ships/ship4.png")
		)
		return true;
	return false;
}

sf::Music * AssetsController::getSoundTrack()
{
	return _soundTrack;
}

sf::Texture* AssetsController::getShipTexture(int id)
{
	return _shipTexture[id - 1];
}
