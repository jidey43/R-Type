#ifndef WTHREAD_H_
# define WTHREAD_H_

# ifdef _WIN32

# include <Windows.h>
# include "IThread.h"
# include "SafeQueue.h"

class CWThread : public IThread
{
public:
	CWThread(SafeQueue &safeStock);
	~CWThread();

private:
	SafeQueue&	_safeStock;
	HANDLE		_thread;

public:
	bool	InitThread(void routine(SafeQueue &params));
	bool	StartThread();
	bool	WaitThread();
	void	DestroyThread();
};

# endif

#endif
