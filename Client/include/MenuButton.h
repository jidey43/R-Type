#pragma once

#include <ViewController.hh>


class    MenuButton
{
public:
	MenuButton(std::string, sf::Vector2f, sf::Vector2f, Font);
	sf::Drawable*		getBackground();
	sf::Drawable*		getDrawableText();
	sf::Vector2f		getPosition();
	void				update(sf::Vector2i);
	bool				cursorOnIt(sf::Vector2i);

public:
	bool				getIsHigh();

protected:
	std::string			_text;
	sf::Text*			_drawableText;		
	sf::RectangleShape*	_background;
	// sf::Sprite			*_spriteReg;
	// sf::Sprite			*_spriteHigh;
	bool				_isHigh;
	sf::Vector2f		_position;
	sf::Vector2f		_size;
	sf::Font*			_font;
};