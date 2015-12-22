#include "AssetsController.hh"

AssetsController::AssetsController(const char *assetsPath)
{
	_assetsPath = std::string(assetsPath);
	_soundTrack = new sf::Music;
}

// AssetsController::~AssetsController()
// {

// }

bool AssetsController::loadAssets()
{
	if (
		loadShipsAssets() &&
		loadSoundAssets() &&
		loadBackground() &&
		loadShots() &&
		loadButtons() &&
		loadFonts() &&
		loadAliens()
		)
		return (true);
	return (false);
}

bool AssetsController::loadSoundAssets()
{
	if (_soundTrack->openFromFile(_assetsPath + "audio/ost.ogg") == false)
		return false;
        for (int i = 0; i != NUMBEROFSOUND; i++)
            _sounds.emplace_back(new sf::SoundBuffer);
    if (
        _sounds[BASICALIENSHOT]->loadFromFile(_assetsPath + "audio/shot.wav")
    )
        return true;
	return false;
}

bool AssetsController::loadShipsAssets()
{
    _explosion = new sf::Texture;
	for (int i = 0; i != NUMBEROFSHIP; i++)
	{
		_ships.emplace_back(new sf::Texture);
	}
	if (
		_ships[PONE]->loadFromFile(_assetsPath + "ships/ship1.png") &&
		_ships[PTWO]->loadFromFile(_assetsPath + "ships/ship2.png") &&
		_ships[PTHREE]->loadFromFile(_assetsPath + "ships/ship3.png") &&
		_ships[PFOUR]->loadFromFile(_assetsPath + "ships/ship4.png") &&
		_ships[PONEFIRE]->loadFromFile(_assetsPath + "ships/ship1prop.png") &&
		_ships[PTWOFIRE]->loadFromFile(_assetsPath + "ships/ship2prop.png") &&
		_ships[PTHREEFIRE]->loadFromFile(_assetsPath + "ships/ship3prop.png") &&
		_ships[PFOURFIRE]->loadFromFile(_assetsPath + "ships/ship4prop.png") &&
        _explosion->loadFromFile(_assetsPath + "explosion.png")
		)
		return true;
	return false;
}

bool AssetsController::loadBackground()
{
	_rtypeLogo = new sf::Texture;
	for (int i = 0; i != NUMBEROFBACKGROUND; i++)
	{
		_backgrounds.emplace_back(new sf::Texture);
	}
	if (
		_rtypeLogo->loadFromFile(_assetsPath + "rtypelogo.png") &&
		_backgrounds[MENU_BACKGROUND]->loadFromFile(_assetsPath + "background/menu_background.png") &&
		_backgrounds[BACKGROUND_ONE]->loadFromFile(_assetsPath + "background/background1.png")
		)
		return true;
	return false;
}

bool AssetsController::loadShots()
{
	for (int i = 0; i != NUMBEROFSHOT; i++)
		_shots.emplace_back(new sf::Texture);
	if (_shots[BASICALIENSHOT]->loadFromFile(_assetsPath + "shots/alienShot.png") &&
		_shots[BASICPLAYERSHOT]->loadFromFile(_assetsPath + "shots/playerShot.png")
		)
		return true;
	return false;
}

bool AssetsController::loadButtons()
{
	for (int i = 0; i != NUMBEROFBUTTON; i += 1)
	{
		_buttons.emplace_back(new sf::Texture);
		_buttonsHigh.emplace_back(new sf::Texture);
	}
	if (
		_buttons[JOIN]->loadFromFile(_assetsPath + "buttons/join.png") &&
		_buttonsHigh[JOIN]->loadFromFile(_assetsPath + "buttons/join_high.png") &&
		_buttons[EXIT]->loadFromFile(_assetsPath + "buttons/exit.png") &&
		_buttonsHigh[EXIT]->loadFromFile(_assetsPath + "buttons/exit_high.png")
		)
		return true;
	return false;
}

bool AssetsController::loadFonts()
{
	for (int i = 0; i != NUMBEROFFONTS; i++)
		_fonts.emplace_back(new sf::Font);
	if (
		_fonts[STAR]->loadFromFile(_assetsPath + "jedi.ttf")
		)
		return true;
	return false;
}

bool AssetsController::loadAliens()
{
	for (int i = 0; i != NUMBEROFALIEN; i++)
		_aliens.emplace_back(new sf::Texture);
	if (
		_aliens[BYDO]->loadFromFile(_assetsPath + "aliens/bydo.png") &&
		_aliens[GLAM]->loadFromFile(_assetsPath + "aliens/bydo.png") &&
		_aliens[DOKAN]->loadFromFile(_assetsPath + "aliens/bydo.png") &&
		_aliens[KAYBEROS]->loadFromFile(_assetsPath + "aliens/bydo.png") &&
		_aliens[RIOS]->loadFromFile(_assetsPath + "aliens/bydo.png") &&
		_aliens[SCANT]->loadFromFile(_assetsPath + "aliens/bydo.png") &&
		_aliens[SHELL]->loadFromFile(_assetsPath + "aliens/bydo.png") &&
		_aliens[YORK]->loadFromFile(_assetsPath + "aliens/bydo.png") &&
		_aliens[XELF16]->loadFromFile(_assetsPath + "aliens/bydo.png")
		)
		return true;
	return false;
}

sf::Music * AssetsController::getSoundTrack()
{
	return _soundTrack;
}

sf::Texture* AssetsController::getShipTexture(Ship id)
{
	return _ships[id];
}

sf::Texture* AssetsController::getBackground(int id)
{
	return _backgrounds[id];
}

sf::Texture* AssetsController::getShot(Shot type)
{
	return _shots[type];
}

sf::Texture * AssetsController::getButton(ButtonType button, bool highlight)
{
	if (highlight)
		return _buttonsHigh[button];
	return _buttons[button];
}

sf::Texture	*AssetsController::getLogo()
{
	return _rtypeLogo;
}

sf::Font* AssetsController::getFont(Font font)
{
	return _fonts[font];
}

sf::Texture * AssetsController::getAlien(AlienType type)
{
	return _aliens[type];
}

sf::Texture*					AssetsController::getExplosion()
{
    return _explosion;
}

sf::SoundBuffer* AssetsController::getSound(Sound sound)
{
    return _sounds[sound];
}