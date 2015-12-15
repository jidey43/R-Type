#ifndef _BOMB_HH_
# define _BOMB_HH_

# include "Projectile.hh"

class Bomb : public Projectile
{
public:
  Bomb(ObjectInfo::Type, sf::Vector2f, sf::Vector2i, unsigned int);
  ~Bomb();

public:
  bool		update();
  bool		update(std::vector<IObject*>&);
  void	        boum();

private:
  short		_countDown;
};

# endif
