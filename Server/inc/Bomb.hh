#ifndef _BOMB_HH_
# define _BOMB_HH_

# include "Projectile.hh"

class Bomb : public Projectile
{
public:
  Bomb(Object::Type , sf::Vector2i);
  ~Bomb();

public:
  void		update();
  void	        boum();

private:
  short		_countDown;
}

# endif
