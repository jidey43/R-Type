#ifndef _WAVES_HH_
# define _WAVES_HH_

# include <SFML/System/Vector2.hpp>
# include <Time.hpp>

class	Waves
{
  Waves(int, sf::Time, sf::vector2i, sf::vector2f, float);
  ~Waves();
public:
  int		        &getCount() const;
  sf::Time		&getTime() const;
  sf::Vector2i	        &getSize() const;
  sf::Vector2f	        &getSpeed() const;
  float		        &getCoeff() const;

  void			pop();
  

private:
  int			_count;
  sf::Time		_time;
  sf::Time		_frequency;
  sf::Vector2i		_pos;
  sf::Vector2f		_speed;
  float			_coeff;
};

#endif
