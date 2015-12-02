#ifdef __linux__

#include "UThread.h"

CUThread::CUThread(SafeQueue* stock)
  : _safeStock(stock)
{
}


CUThread::~CUThread()
{
}

bool CUThread::InitThread(void routine(SafeQueue* stock))
{
	_routine = routine;
	return true;
}

bool CUThread::StartThread()
{
	_thread = new std::thread(_routine, _safeStock);
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

IThread*				getThreadInstance(SafeQueue* queue)
{
	return new CUThread(queue);
}

#endif
