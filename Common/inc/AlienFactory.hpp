#ifndef _ALIENFACTORY_HH_
# define _ALIENFACTORY_HH_

# include <cstddef>
# include <deque>
# include "IAlienFactory.hh"
# include "MapController.hh"
# include "Waves.hh"

extern unsigned int _maxId;

template <class T>
class	AlienFactory : public IAlienFactory
{
public:
  AlienFactory(ObjectInfo::WaveType type) : _type(type){};
  ~AlienFactory() {};

public:
  IObject	*getNextEnemy(const sf::Clock &clock)
  {
    IObject	*obj;

    if (_order.size() <= 0)
      return NULL;
    if (clock.getElapsedTime() >= _order.front()->getTime())
      {
	// std::cout << "max ID : " << _maxId<< std::endl;
        obj = new T(_order.front()->getSpeed(), _order.front()->getPos(), _maxId++, _order.front()->getCoeff());
	_order.front()->pop();
      }
    else
      obj = NULL;
    if (_order.front()->getCount() == 0)
      _order.pop_front();
    return (obj);
  }

  const ObjectInfo::WaveType	&getType() const
  {
    return _type;
  }

  void			setWave(Waves *wave)
  {
    _order.push_back(wave);
  }

public:
  std::deque<Waves*>	_order;
  ObjectInfo::WaveType	_type;
};

#endif
