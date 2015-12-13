#ifndef UTHREAD_H_
# define UTHREAD_H_

/* # ifndef _WIN32 */

# include <thread>
# include <string>
# include "IThread.h"

class UThread : public IThread
{
 public:
  UThread(std::string const& port, std::string const& ip);
  ~UThread();

 private:
  std::string		_port;
  std::string		_ip;
  std::thread*		_thread;
  void			(*_routine)(std::string const& port, std::string const& ip);

 public:
  bool			InitThread(void routine(std::string const& port, std::string const& ip));
  bool			StartThread();
  bool			TryWaitThread();
  void			DestroyThread();
};

/* # endif */

#endif
