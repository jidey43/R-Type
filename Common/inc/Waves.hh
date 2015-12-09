#ifndef _WAVES_HH_
# define _WAVES_HH_

# include <SFML/System/Vector2.hpp>
# include <SFML/System/Time.hpp>
# include "ObjectInfo.hpp"

class	Waves
{
public:
  Waves(int, sf::Time, sf::Time, sf::Vector2i, sf::Vector2f, float, ObjectInfo::WaveType);
  Waves();
  ~Waves();
  
public:
  Waves			&operator=(const Waves&);
  int		        getCount() const;
  sf::Time		getTime() const;
  sf::Time		getFreq() const;
  sf::Vector2i		getPos() const;
  sf::Vector2f	        getSpeed() const;
  float		        getCoeff() const;
  ObjectInfo::WaveType  getType() const;
  void			setCount(int);  
  void			pop();

private:
  int			_count;
  sf::Time		_time;
  sf::Time		_frequency;
  sf::Vector2i		_pos;
  sf::Vector2f		_speed;
  float			_coeff;
  ObjectInfo::WaveType	_type;
};

#endif
