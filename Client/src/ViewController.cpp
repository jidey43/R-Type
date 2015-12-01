
#include "ViewController.h"

ViewController::ViewController()
{
	_mainWindow = new sf::RenderWindow(sf::VideoMode(1920, 1080), "RType" ,sf::Style::Fullscreen);
	_mainWindow->setKeyRepeatEnabled(false);
	_soundTrack = ac->getSoundTrack();
}

ViewController::~ViewController()
{

}

void							ViewController::clear()
{
	_mainWindow->clear();
}

void ViewController::operator<<(GameItem *item)
{
	draw(item->getDrawable());
}

void							ViewController::refresh()
{
	_mainWindow->display();
}

void							ViewController::draw(sf::Drawable* drawable)
{
	_mainWindow->draw(*drawable);
}

keyboardStatus					ViewController::getEvents()
{
	keyboardStatus		state = {false, false, false, false};

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		state.up = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		state.down = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		state.left = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		state.right = true;
	return state;
}

void ViewController::startSoundtrack()
{
	_soundTrack->play();
}
