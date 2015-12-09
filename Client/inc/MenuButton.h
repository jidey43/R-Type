#pragma once

#include <ViewController.hh>


class    MenuButton
{
public:
	MenuButton();
	sf::Drawable*		getDrawable();
	sf::Vector2f		getPosition();
	void				update(sf::Vector2i);
	bool				cursorOnIt(sf::Vector2i);

public:
	bool				getIsHigh();

protected:
	sf::Sprite			*_spriteReg;
	sf::Sprite			*_spriteHigh;
	bool				_isHigh;
	sf::Vector2f		_position;
};