#ifdef _WIN32

CWMutex::CWMutex()
{
	InitMutex();
}

CWMutex::~CWMutex()
{
	DestroyMutex();
}

void CWMutex::InitMutex()
{
	// exception raised STATUS_NO_MEMORY
	InitializeCriticalSectionAndSpinCount(&_mutex, 0x00000400);
}

void CWMutex::DestroyMutex()
{
	DeleteCriticalSection(&_mutex);
}

void CWMutex::LockMutex()
{
	// exception raised EXCEPTION_POSSIBLE_DEADLOCK
	EnterCriticalSection(&_mutex);
}

bool CWMutex::TrylockMutex()
{
	TryEnterCriticalSection(&_mutex);
	return (true);
}

void CWMutex::UnlockMutex()
{
	LeaveCriticalSection(&_mutex);
}

IMutex*				getMutexInstance()
{
	return new CWMutex();
}
#endif