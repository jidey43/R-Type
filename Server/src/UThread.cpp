// #ifdef __linux__

#include "UThread.h"

UThread::UThread(std::string const& port, std::string const& ip)
  : _port(port), _ip(ip)
{
}


UThread::~UThread()
{
}

bool UThread::InitThread(void routine(std::string const& port, std::string const& ip))
{
  _routine = routine;
  return true;
}

bool UThread::StartThread()
{
  _thread = new std::thread(_routine, _port, _ip);
  return true;
}

bool UThread::TryWaitThread()
{
  if (_thread->joinable())
    {
      _thread->join();
      return true;
    }
  else
    return false;
}

void UThread::DestroyThread()
{
  delete _thread;
}

// IThread*				getThreadInstance(SafeQueue* queue)
// {
//   return new UThread(queue);
// }

// #endif
