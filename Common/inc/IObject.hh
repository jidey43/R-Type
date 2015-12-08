#ifndef _IOBJECT_HH_
# define _IOBJECT_HH_

# include "ObjectInfo.hpp"

class IObject
{
public:
  virtual ~IObject() {}

public:
  virtual ObjectInfo::Type		&getObjType() = 0;
  virtual void				uptade() = 0;
};

#endif
