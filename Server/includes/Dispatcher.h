#ifndef DISPATCHER_H_
# define DISPATCHER_H_

# include "ScopedLock.h"
# include "IMutex.h"
# include "IThread.h"
# include "IObject.h"
# include <vector>

typedef enum
{
	MOVE,
	SCRIPT
}			WorkType;

class Dispatcher
{
public:
	Dispatcher();
	~Dispatcher();

private:
	WorkType		_work;
	char			_freeT;
	IMutex*			_mutex;
	IObject*		_buff;

	std::vector<IObject*>* _objectList;
	SafeQueue*		_moveQueue;
	SafeQueue*		_scriptQueue;

public:
	WorkType		getWorkType() const;
	void			noticeWorkDone();
	IObject*		askForWork();
	void			setObjectList(std::vector<IObject*>* objectList);
	void			fillWorkQueue();
};

#endif