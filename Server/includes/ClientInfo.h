#ifndef CLIENTINFO_H_
# define CLIENTINFO_H_

# include <string>
# include "NetworkDefines.h"

class ClientInfo
{
public:
	ClientInfo(SOCKET socket);
	ClientInfo(SOCKET socket, std::string const& nick);
	~ClientInfo();

private:
	bool			_isInGame;
	SOCKET			_socket;
	std::string		_nickname;
	std::string		_packet;
	std::string		_remainPacket;

public:
	bool			isInGame() const;
	void			setPacket(std::string const& str);
	std::string		getPacket() const;
	SOCKET			getSocket() const;
	std::string		getNickname() const;
	std::string		getRemainPacket() const;
	void			setRemainPacket(std::string const&);
};

#endif
