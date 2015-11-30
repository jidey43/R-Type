#include <string.h>
#include "Serializer.h"

Serializer::Serializer()
{
	_structSize[CPACKET] = sizeof(ClientPacket);
}


Serializer::~Serializer()
{
}

ClientPacket* Serializer::getClientPacket(std::string& data)
{
	void*				tmp;
	ClientPacket*			packet = new ClientPacket;
	int*				nb;

	nb = (int*)(data.substr(0, 3).c_str());
	if (*nb == CPACKET && data[4] == ':')
	{
		tmp = (void*)data.substr(4, _structSize[CPACKET] + 4).c_str();
		memcpy(packet, tmp, _structSize[CPACKET]);
		return (packet);
	}
	return NULL;
}
