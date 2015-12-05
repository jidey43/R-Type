# include "ClientInfo.h"

ClientInfo::ClientInfo(SOCKET socket)
  : _isInGame(false), _socket(socket), _remainPacket("")
{
}

ClientInfo::ClientInfo(SOCKET socket, std::string const & nick)
	: _isInGame(false), _socket(socket), _nickname(nick)
{
}

ClientInfo::~ClientInfo()
{
}

bool ClientInfo::isInGame() const
{
	return _isInGame;
}

void ClientInfo::setPacket(std::string const& str)
{
	_packet = str;
}

std::string ClientInfo::getPacket() const
{
	return _packet;
}

SOCKET ClientInfo::getSocket() const
{
	return _socket;
}

std::string ClientInfo::getNickname() const
{
	return _nickname;
}

std::string ClientInfo::getRemainPacket() const
{
  return _remainPacket;
}


void		ClientInfo::setRemainPacket(std::string const& remain)
{
  _remainPacket = remain;
}
