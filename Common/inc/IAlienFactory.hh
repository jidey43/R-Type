#ifndef _IALIEN_FACTORY_HH_
# define _IALIEN_FACTORY_HH_

# include "IObject.hh"

class IAlienFactory
{
  virtual ~IAlienFactory() {};
  template<class T>IObject *getNextEnemy();
};

#endif
