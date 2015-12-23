# include "UMutex.h"
# ifndef _WIN32


CUMutex::CUMutex()
{
}

CUMutex::~CUMutex()
{
}

void CUMutex::InitMutex()
{
}

void CUMutex::DestroyMutex()
{
}

void CUMutex::LockMutex()
{
	_mutex.lock();
}

bool CUMutex::TrylockMutex()
{
	return _mutex.try_lock();
}

void CUMutex::UnlockMutex()
{
	_mutex.unlock();
}

IMutex*				getMutexInstance()
{
	return new CUMutex;
}

#endif // !_WIN32