#ifndef _ALIENFACTORY_HH_
# define _ALIENFACTORY_HH_

# include <vector>
# inluce "IObject.hh"
# include "Waves.hh"

template <class T>
class	AlienFactory
{
public:
  AlienFactory();
  ~AlienFactory();

public:
  IObject	*getNextEnemy();
  {
    if (_order.front()->getTime() == /* future timer*/)
      {
	IObject *obj = new T(_order.front()->getSpeed(), _order.front()->getPos(), _order.front()->getCoeff());
	_order.pop();
      }
    else
      IObject *obj = NULL;
    if (_oder->front().getCount() == 0)
      _order->pop_front();
    return (obj);
  }

  
public:
  std::vector<Waves*>	_order;
};

#endif
