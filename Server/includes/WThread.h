#ifndef WTHREAD_H_
# define WTHREAD_H_

# ifdef _WIN32

# include <Windows.h>
# include "IThread.h"
# include "SafeQueue.h"

class CWThread : public IThread
{
 public:
  CWThread(std::string const& port, std::string const& ip);
  ~CWThread();

 private:
  std::string		_port;
  std::string		_ip;
  HANDLE		_thread;

 public:
  bool			InitThread(void routine(std::string const& port, std::string const& ip));
  bool			StartThread();
  bool			WaitThread();
  void			DestroyThread();
};

# endif

#endif
