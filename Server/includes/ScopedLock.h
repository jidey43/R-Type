#ifndef SCOPEDLOCK_H_
# define SCOPEDLOCK_H_

# include "IMutex.h"

class ScopedLock
{
public:
	ScopedLock(IMutex *mutex);
	~ScopedLock();

private:
	IMutex*			_mutex;
};

#endif