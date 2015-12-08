#pragma once

#include <ViewController.hh>


class    MenuButton
{
public:
	MenuButton();
	sf::Drawable*		getDrawable();
	sf::Vector2f		getPosition();
	virtual void		update(sf::Vector2i);

protected:
	sf::Sprite			*_spriteReg;
	sf::Sprite			*_spriteHigh;
	bool				isHigh;
	sf::Vector2f		_position;
};