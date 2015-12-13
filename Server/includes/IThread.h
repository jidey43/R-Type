#ifndef ITHREAD_H_
# define ITHREAD_H_

class IThread
{
 public:
  virtual ~IThread() {}

 public:
  virtual bool	InitThread(void routine(std::string const& port, std::string const& ip)) = 0;
  virtual bool	StartThread() = 0;
  virtual bool	TryWaitThread() = 0;
  virtual void	DestroyThread() = 0;
};

IThread*				getThreadInstance();

#endif
