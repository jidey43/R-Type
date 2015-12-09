#include "AssetsController.hh"

AssetsController::AssetsController(const char *assetsPath)
{
	_assetsPath = std::string(assetsPath);	
	_soundTrack = new sf::Music;
}

AssetsController::~AssetsController()
{

}

bool AssetsController::loadAssets()
{
	if (
		loadShipsAssets() &&
		loadSoundAssets() &&
		loadBackground() &&
		loadShots() &&
		loadButtons()
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

bool AssetsController::loadBackground()
{
	_rtypeLogo = new sf::Texture;
	for (int i = 0; i != NUMBEROFBACKGROUND; i++)
	{
		_backgroundTexture.emplace_back(new sf::Texture);
	}
	if (
		_rtypeLogo->loadFromFile(_assetsPath + "rtypelogo.png") && 
		_backgroundTexture[MENU_BACKGROUND]->loadFromFile(_assetsPath + "background/menu_background.png") &&
		_backgroundTexture[BACKGROUND_ONE]->loadFromFile(_assetsPath + "background/background1.png")
		)
		return true;
	return false;
}

bool AssetsController::loadShots()
{
	_shipShot = new sf::Texture;
	if (_shipShot->loadFromFile(_assetsPath + "shipShot.png"))
		return true;
	return false;
}

bool AssetsController::loadButtons()
{
	for (int i = 0; i != NUMBEROFBUTTON; i += 1)
	{
		_buttonTexture.emplace_back(new sf::Texture);
		_buttonTextureHigh.emplace_back(new sf::Texture);
	}
	if (
		_buttonTexture[JOIN]->loadFromFile(_assetsPath + "buttons/join.png") &&
		_buttonTextureHigh[JOIN]->loadFromFile(_assetsPath + "buttons/join_high.png") &&
		_buttonTexture[EXIT]->loadFromFile(_assetsPath + "buttons/exit.png") &&
		_buttonTextureHigh[EXIT]->loadFromFile(_assetsPath + "buttons/exit_high.png")
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

sf::Texture* AssetsController::getBackground(int id)
{
	return _backgroundTexture[id];
}

sf::Texture* AssetsController::getShot(int)
{
	return _shipShot;
}

sf::Texture * AssetsController::getButton(ButtonType button, bool highlight)
{
	if (highlight)
		return _buttonTextureHigh[button];
	return _buttonTexture[button];
}

sf::Texture	*AssetsController::getLogo()
{
	return _rtypeLogo;
}
