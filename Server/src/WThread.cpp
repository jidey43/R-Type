#ifdef _WIN32

# include "WThread.h"

CWThread::CWThread(std::string const& port, std::string const& ip)
  : _port(port), _ip(ip)
{
}

CWThread::~CWThread()
{
}

bool CWThread::InitThread(void routine(std::string const& port, std::string const& ip))
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
  return (WaitForSingleObject(_thread, NULL) == WAIT_FAILED ? false : true);
}

IThread*				getThreadInstance(SafeQueue* queue)
{
  return new CWThread(queue);
}

#endif
