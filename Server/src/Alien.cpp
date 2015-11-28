#include "Alien.hh"

Alien::Alien(sf::Vector2i pos)
{
  _objType = ALIEN;
  _size.x = 0; // a def
  _size.y = 0; // a def
  _pos = pos;
  _speed.x = 0; // a def
  _speed.y = 0; // a def
}

Player::~Player() {}

void		update()
{
}
