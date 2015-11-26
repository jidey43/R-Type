#include "Dispatcher.h"

Dispatcher::Dispatcher()
	: _work(MOVE), _freeT(8), _mutex(getMutexInstance()), _moveQueue(new SafeQueue), _scriptQueue(new SafeQueue)
{
}

Dispatcher::~Dispatcher()
{
}

WorkType Dispatcher::getWorkType() const
{
	return _work;
}

void Dispatcher::noticeWorkDone()
{
	ScopedLock scope(_mutex);

	++_freeT;
}

IObject * Dispatcher::askForWork()
{
	if (_work == MOVE)
	{
		if ((_buff = _moveQueue->popList()) == nullptr && _freeT == 8 && !_scriptQueue->isEmpty())
			_work = SCRIPT;
		else
			--_freeT;
		return _buff;
	}
	else if (_work == SCRIPT)
	{
		if ((_buff = _scriptQueue->popList()) == nullptr && _freeT == 8)
			_work = MOVE;
		else
			--_freeT;
		return _buff;
	}
	return NULL;
}

void Dispatcher::setObjectList(std::vector<IObject*>* objectList)
{
	_objectList = objectList;
}

void Dispatcher::fillWorkQueue()
{
	for (std::vector<IObject*>::iterator it = _objectList->begin(); it != _objectList->end(); ++it)
	{
		_moveQueue->fillList((*it));
		_scriptQueue->fillList((*it));
	}
}
