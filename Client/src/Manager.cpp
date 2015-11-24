#include "Manager.h"

Manager::Manager()
{
	//_soundCtrl = new SoundController;
}

Manager::~Manager()
{

}

void					Manager::loop()
{
	sf::Sprite sprite;
	sf::Texture texture;
	texture.loadFromFile("./toto.jpg");
	sprite.setTexture(texture);


		while (1)
	{
		_clock.restart();
		vc->clear();
		vc->getEvents();
		vc->draw(&sprite);
		vc->refresh();
		_loopTime = _clock.getElapsedTime();
		sf::sleep(sf::Time(sf::microseconds(16666)) - _loopTime);
	}
}