#include "ExitButton.h"

ExitButton::ExitButton() : MenuButton()
{
	int posx = (RES_X - (RES_X * 0.5)) - (BUTTON_X / 2);
	int posy = RES_Y - (RES_Y * 0.2) - (BUTTON_Y / 2);
	_position = sf::Vector2f(posx, posy);
	_spriteReg->setTexture(*(ac->getButton(EXIT, false)));
	_spriteReg->setPosition(_position);
	_spriteHigh->setTexture(*(ac->getButton(EXIT, true)));
	_spriteHigh->setPosition(_position);
}

ExitButton::~ExitButton()
{
}
