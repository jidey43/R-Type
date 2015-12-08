#include "Waves.hh"

Waves::Waves(int count, sf::Time time, sf::Time freq, sf::Vector2i pos, sf::Vector2f speed, float coeff, ObjectInfo::WaveType type)
  : _count(count), _time(time), _frequency(freq), _pos(pos), _speed(speed), _coeff(coeff), _type(type)
{}

Waves::~Waves() {}

void		Waves::pop()
{
  _time = _time - _frequency;
  _count = _count - 1;
}

int	        Waves::getCount() const
{
  return _count;
}

sf::Time	Waves::getFreq() const
{
  return _frequency;
}

sf::Time	Waves::getTime() const
{
  return _time;
}

sf::Vector2i	Waves::getPos() const
{
  return _pos;
}

float		Waves::getCoeff() const
{
  return _coeff;
}

