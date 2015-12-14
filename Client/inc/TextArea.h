#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include "ViewController.hh"
#include "AssetsController.hh"

extern ViewController *vc;

class TextArea
{
public:
	TextArea(Font font, sf::Vector2f pos, sf::Vector2f size, std::string defaultText);
	void			update(keyboardStatus status);
	sf::Drawable*	getTextArea();
	std::string	getText();
	sf::Text*		getDrawableText();
	bool			cursorOnIt(sf::Vector2i);

private:
	sf::Font		*_font;
	std::string		_text;
	std::string		_defaultText;
	sf::RectangleShape		*_textArea;
	sf::Text		*_drawableText;
	sf::Vector2f	_pos;
	sf::Vector2f	_size;
};
