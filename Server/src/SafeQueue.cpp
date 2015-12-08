#include "ScopedLock.h"
#include "SafeQueue.h"
#include <iostream>


SafeQueue::SafeQueue()
	: _mutex(getMutexInstance()), _list(new std::deque<IObject*>())
{
}

SafeQueue::SafeQueue::~SafeQueue()
{
	delete _mutex;
	delete _list;
}

IObject*	SafeQueue::SafeQueue::popList()
{
	ScopedLock		scope(_mutex);
	IObject*		ret;

	if (_list->size() > 0)
	{
		ret = _list->front();
		_list->pop_front();
		return (ret);
	}
	return (NULL);
}


void SafeQueue::fillList(IObject* const data)
{
	ScopedLock		scope(_mutex);

	_list->push_back(data);
}

 
bool SafeQueue::isEmpty()
{
	return _list->empty();
}
/*
#include "ScopedLock.h"
#include <iostream>

template <typename T>
SafeQueue<T>::SafeQueue()
	: _mutex(getMutexInstance()), _list(new std::deque<T*>())
{
}

template <typename T>
SafeQueue<T>::~SafeQueue()
{
	delete _mutex;
	delete _list;
}

template <typename T>
T*			SafeQueue<T>::popList()
{
	ScopedLock		scope(_mutex);
	T*		ret;

	if (_list->size() > 0)
	{
		ret = _list->front();
		_list->pop_front();
		return (ret);
	}
	return (NULL);
}

template <typename T>
void SafeQueue<T>::fillList(T* const data)
{
	ScopedLock		scope(_mutex);

	_list->push_back(data);
}

template <typename T> 
bool SafeQueue<T>::isEmpty()
{
	return _list->empty();
}
*/
