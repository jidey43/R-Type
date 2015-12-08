#ifndef IOBJECT_H_
# define IOBJECT_H_

typedef enum
{
	PLAYER,
	MONSTER,
	ROCK
}			ObjectType;

class IObject
{
public:
	IObject();
	~IObject();

private:
	virtual ObjectType		getObjectType() const = 0;
	virtual void			update() = 0;
};

#endif