#ifndef _ALIEN_HH_
# define _ALIEN_HH_

# include <cmath>
# include "Object.hh"

class Alien : public Object
{
public:
  Alien(sf::Vector2f, sf::Vector2f, sf::Vector2i, unsigned int, float);
  ~Alien();

public:
  bool			update();
  IObject		*Basicshoot();
  ObjectInfo::WaveType	getRealType() const;
 
protected:
  float			_coeff;
  int			_t;
  int			_f;
  int			_a;
  float			_rad;
  ObjectInfo::WaveType	_realType;
};

# endif
