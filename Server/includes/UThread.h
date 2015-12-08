#ifndef UTHREAD_H_
# define UTHREAD_H_

# ifndef _WIN32

#include <thread>
#include "IThread.h"

class CUThread : public IThread
{
public:
	CUThread(SafeQueue *safeStock);
	~CUThread();

private:
	SafeQueue*		_safeStock;
	std::thread*		_thread;
	void			(*_routine)(SafeQueue* stock);

public:
	bool		InitThread(void routine(SafeQueue *params));
	bool		StartThread();
	bool		WaitThread();
	void		DestroyThread();
};

# endif

#endif
