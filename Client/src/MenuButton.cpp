#include "..\inc\MenuButton.h"

MenuButton::MenuButton()
{
	_spriteHigh = new sf::Sprite;
	_spriteReg = new sf::Sprite;
}

sf::Drawable * MenuButton::getDrawable()
{
	if (_isHigh)
		return _spriteHigh;
	return _spriteReg;
}

sf::Vector2f MenuButton::getPosition()
{
	return _position;
}

void MenuButton::update(sf::Vector2i mousepos)
{
	_isHigh = cursorOnIt(mousepos);
}

bool MenuButton::cursorOnIt(sf::Vector2i mousepos)
{
	if (
		mousepos.x > _position.x &&
		mousepos.x < (_position.x + BUTTON_X) &&
		mousepos.y > _position.y &&
		mousepos.y < (_position.y + BUTTON_Y)
		)
		return true;
	return false;
}

bool MenuButton::getIsHigh()
{
	return _isHigh;
}