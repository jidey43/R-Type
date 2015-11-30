#ifndef SERIALIZER_H_
# define SERIALIZER_H_

# include <vector>
# include "NetworkDefines.h"

class Serializer
{
public:
	Serializer();
	~Serializer();

private:
	std::vector<int>	_structSize;
	ClientPacket		_cPacket;

public:
	ClientPacket*		getClientPacket(std::string& data);
};

#endif