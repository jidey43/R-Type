#ifndef _ALIENFACTORY_HH_
# define _ALIENFACTORY_HH_

# include <cstddef>
# include <deque>
# include "IAlienFactory.hh"
# include "Waves.hh"

template <class T>
class	AlienFactory : public IAlienFactory
{
public:
  AlienFactory(const T& rhs) {};
  ~AlienFactory() {};

public:
  IObject	*getNextEnemy()
  {
    IObject	*obj;
    if (0 /*_order.front()->getTime() == 0 future timer*/ )
      {
        obj = new T(_order.front()->getSpeed(), _order.front()->getPos(), _order.front()->getCoeff());
	_order.front()->pop();
      }
    else
      obj = NULL;
    if (_order.front()->getCount() == 0)
      _order.pop_front();
    return (obj);
  }
  
public:
  std::deque<Waves*>	_order;
};

#endif
