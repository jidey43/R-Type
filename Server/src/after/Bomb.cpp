#include "Bomb.hh"

Bomb::Bomb(ObjectInfo::Type type,sf::Vector2f speed, sf::Vector2i pos, float coeff)
{
  _objType = type;
  _speed = speed;
  _pos = pos;
  _coeff = coeff;
}

Bomb::~Bomb()
{
}

void	Bomb::update()
{}

void	Bomb::boum()
{}
