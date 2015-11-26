#ifndef WMUTEX_H_
# define WMUTEX_H_

# include "IMutex.h"

# ifdef _WIN32

# include <Windows.h>

class CWMutex : public IMutex
{
public:
	CWMutex();
	~CWMutex();

private:
	CRITICAL_SECTION	_mutex;

public:
	void				InitMutex();
	void				DestroyMutex();
	void				LockMutex();
	bool				TrylockMutex();
	void				UnlockMutex();
};

# endif

#endif