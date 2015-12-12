
#include "ViewController.hh"

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

void ViewController::operator<<(GraphicalItem *item)
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

keyboardStatus					ViewController::getKeyboardStatus()
{
	keyboardStatus		state = {sf::Vector2i(), false, false, false, false, false};


	//debug
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		exit(0);

	state.mousePos = sf::Mouse::getPosition(*_mainWindow);
	state.textEntered = getTextEntered();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		state.leftClick = true;
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

char ViewController::getTextEntered()
{
	sf::Event e;
	_mainWindow->pollEvent(e);
	if (e.type == sf::Event::TextEntered)
	{
		if (e.text.unicode < 128)
			return(static_cast<char>(e.text.unicode));
	}
	return -1;
}

void ViewController::startSoundtrack()
{
	_soundTrack->play();
}
