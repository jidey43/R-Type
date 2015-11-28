#ifndef _SHELL_ALIEN_HH_
# define _SHELL_ALIEN_HH_

# include "Alien.hh"

class ShellAlien : public Alien
{
public:
  ShellAlien(sf::Vector2i pos);
  ~ShellAlien();

public:
  void		update();
  IObject	*Basicshoot();
}

# endif
