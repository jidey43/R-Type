#include "ScopedLock.h"

ScopedLock::ScopedLock(IMutex* mutex)
	: _mutex(mutex)
{
	_mutex->LockMutex();
}

ScopedLock::~ScopedLock()
{
	_mutex->UnlockMutex();
}