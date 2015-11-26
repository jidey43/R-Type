#ifdef __linux__

#include "UThread.h"

CUThread::CUThread(IMutex *mutex)
	: _mutex(mutex)
{
}


CUThread::~CUThread()
{
}

bool CUThread::InitThread(void routine(IMutex *params))
{
	_routine = routine;
	return true;
}

bool CUThread::StartThread()
{
	_thread = new std::thread(_routine, _mutex);
	return true;
}

bool CUThread::WaitThread()
{
	_thread->join();
	return true;
}

void CUThread::DestroyThread()
{
	delete _thread;
}

#endif