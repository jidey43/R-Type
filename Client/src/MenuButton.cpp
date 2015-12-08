#include "../inc/MenuButton.h"

MenuButton::MenuButton()
{
	_spriteHigh = new sf::Sprite;
	_spriteReg = new sf::Sprite;
}

sf::Drawable * MenuButton::getDrawable()
{
	if (isHigh)
		return _spriteHigh;
	return _spriteReg;
}

sf::Vector2f MenuButton::getPosition()
{
	return _position;
}

void MenuButton::update(sf::Vector2i mousepos)
{
	if (
		mousepos.x > _position.x &&
		mousepos.x < (_position.x + BUTTON_X) &&
		mousepos.y > _position.y &&
		mousepos.y < (_position.y + BUTTON_Y)
		)
		isHigh = true;
	else
		isHigh = false;
}
