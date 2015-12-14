#ifndef _ALIEN_HH_
# define _ALIEN_HH_

# include "Object.hh"

class Alien : public Object
{
public:
  Alien(sf::Vector2f, sf::Vector2f, sf::Vector2i, unsigned int, float);
  ~Alien();

public:
  bool		update();
  IObject	*Basicshoot();

protected:
  float		_coeff;
};

# endif
