#include "Manager.h"

Manager::Manager()
{
}

Manager::~Manager()
{

}

void					Manager::loop()
{
	sf::Sprite sprite;
	sf::Texture texture;
	texture.loadFromFile("ship1.png");
	//texture.loadFromFile("toto.jpg");
	sprite.setTexture(texture);
	std::cout << "salut" << std::endl;
	//STARTING
	//vc->startSoundtrack();
	//GAME LOOP
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