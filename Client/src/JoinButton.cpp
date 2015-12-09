#include "JoinButton.h"

JoinButton::JoinButton() : MenuButton()
{
	int posx = (RES_X - ( RES_X * 0.5)) - (BUTTON_X / 2);
	int posy = RES_Y - (RES_Y * 0.5) - (BUTTON_Y / 2);
	_position = sf::Vector2f(posx, posy);
	_spriteReg->setTexture(*(ac->getButton(JOIN, false)));
	_spriteReg->setPosition(_position);
	_spriteHigh->setTexture(*(ac->getButton(JOIN, true)));
	_spriteHigh->setPosition(_position);
}

JoinButton::~JoinButton()
{
}
