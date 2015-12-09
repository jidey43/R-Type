#ifdef _WIN32

# include "WThread.h"

CWThread::CWThread(SafeQueue *stock)
	: _safeStock(stock), _thread(NULL)
{
}

CWThread::~CWThread()
{
}

bool CWThread::InitThread(void routine(SafeQueue *params))
{
	return ((_thread = CreateThread(
		NULL,									// default security attributes
		0,										// use default stack size  
		(LPTHREAD_START_ROUTINE)routine,		// thread function name
		_safeStock,								// argument to thread function 
		CREATE_SUSPENDED,						// use default creation flags 
		0										// returns the thread identifier 
		)) == NULL ? false : true);	
}

bool CWThread::StartThread()
{
	return (ResumeThread(_thread) == (DWORD)-1 ? false : true);
}

void CWThread::DestroyThread()
{
	CloseHandle(_thread);
}

bool CWThread::WaitThread()
{
	return (WaitForSingleObject(_thread, INFINITE) == WAIT_FAILED ? false : true);
}

IThread*				getThreadInstance(SafeQueue* queue)
{
	return new CWThread(queue);
}

#endif