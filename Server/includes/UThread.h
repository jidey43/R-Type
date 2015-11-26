#ifndef UTHREAD_H_
# define UTHREAD_H_

# ifdef __linux__

#include <thread>
#include "IThread.h"

class CUThread : public IThread
{
public:
	CUThread(SafeQueue &safeStock);
	~CUThread();

private:
	SafeQueue&		_safeStock;
	std::thread*	_thread;
	void			(*_routine)(IMutex *param);

public:
	bool		InitThread(void routine(SafeQueue &params));
	bool		StartThread();
	bool		WaitThread();
	void		DestroyThread();
};

# endif

#endif