#ifndef THREADPOOL_H_
# define THREADPOOL_H_

# include "IThread.h"
# include <vector>

class ThreadPool
{
public:
	ThreadPool();
	~ThreadPool();

private:
	std::vector<IThread*>	_pool;

public:
	bool					initThreads(void routine(SafeQueue &params));
	void					startThreads();
	void					waitThreads();
};

ThreadPool::ThreadPool()
{
}

ThreadPool::~ThreadPool()
{
}

bool ThreadPool::initThreads(void routine(SafeQueue &params))
{
	return false;
}

void ThreadPool::startThreads()
{
}

void ThreadPool::waitThreads()
{
}

#endif