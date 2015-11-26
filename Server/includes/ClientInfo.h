#ifndef CLIENTINFO_H_
# define CLIENTINFO_H_

# include <string>
# include "NetworkDefines.h"

class ClientInfo
{
public:
	ClientInfo(SOCKET socket);
	~ClientInfo();

private:
	bool			_isInGame;
	SOCKET		_socket;
	std::string		_nickname;

public:
	SOCKET		getSocket() const;
	std::string		getNickname() const;
};

#endif