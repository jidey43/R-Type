# include "ClientInfo.h"

ClientInfo::ClientInfo(SOCKET socket)
	: _isInGame(false), _socket(socket)
{
}

ClientInfo::~ClientInfo()
{
}

SOCKET ClientInfo::getSocket() const
{
	return _socket;
}

std::string ClientInfo::getNickname() const
{
	return _nickname;
}
