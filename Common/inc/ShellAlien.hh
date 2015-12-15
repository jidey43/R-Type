#ifndef _SHELL_ALIEN_HH_
# define _SHELL_ALIEN_HH_

# include "Alien.hh"

class ShellAlien : public Alien
{
public:
  ShellAlien(sf::Vector2f speed, sf::Vector2i pos, unsigned int id, float coeff);
  ~ShellAlien();

public:
  bool		update();
  bool		update(std::vector<IObject*>&);
  IObject	*Basicshoot();
}

# endif
