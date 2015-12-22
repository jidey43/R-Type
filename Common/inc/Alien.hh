#ifndef _ALIEN_HH_
# define _ALIEN_HH_

# define _USE_MATH_DEFINES
# include <cmath>
# include "BasicAlienProjectile.hh"
# include "Object.hh"

class Alien : public Object
{
public:
  Alien(sf::Vector2f, sf::Vector2f, sf::Vector2i, unsigned int, float);
  Alien(const Alien &);
  ~Alien();

public:
  virtual bool		        update(sf::Clock const&, std::vector<IObject*>&);
  virtual bool		        update(sf::Clock const&);
  const float&			getCoeff() const;
  BasicAlienProjectile		*BasicShoot();
  const ObjectInfo::WaveType	&getRealType() const;

protected:
  float			_coeff;
  int			_f;
  int			_a;
  float			_rad;
  ObjectInfo::WaveType	_realType;
};

# endif
