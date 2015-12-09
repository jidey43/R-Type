#ifndef _SHELL_ALIEN_HH_
# define _SHELL_ALIEN_HH_

# include "Alien.hh"

class ShellAlien : public Alien
{
public:
  ShellAlien(sf::Vector2f speed, sf::Vector2i pos, float coeff);
  ~ShellAlien();

public:
  void		update();
  IObject	*Basicshoot();
}

# endif
