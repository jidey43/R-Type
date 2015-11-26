#ifndef ITHREAD_H_
# define ITHREAD_H_

# include "SafeQueue.h"

class IThread
{
public:
	virtual ~IThread() {}

public:
	virtual bool	InitThread(void routine(SafeQueue *params)) = 0;
	virtual bool	StartThread() = 0;
	virtual bool	WaitThread() = 0;
	virtual void	DestroyThread() = 0;
};

IThread*				getThreadInstance();

#endif
