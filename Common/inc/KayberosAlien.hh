#ifndef _KAYBEROS_ALIEN_HH_
# define _KAYBEROS_ALIEN_HH_

# include "Alien.hh"

class KayberosAlien : public Alien
{
public:
  KayberosAlien(sf::Vector2i pos);
  ~KayberosAlien();

public:
  void		update();
  IObject	*Basicshoot();
}

# endif
